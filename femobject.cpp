#include "femobject.h"

int FEMobject::randNum(int nMin, int nMax)
{
    return nMin + (int)((double)rand() / (RAND_MAX+1) * (nMax-nMin+1));
}

void FEMobject::regularTriangulation(int n,int m, float r,bool switcher)
{
    //n - number of nodes
    //m - number of circlse
    //r - radius
    auto start_pt = GMlib::Point<float,2>(0,0);
    this->insertAlways(start_pt);

    for(int i=0;i<m;i++){

        for(int j=0;j<n*(i+1);j++){

            GMlib::Angle a = (j*M_2PI)/(n*(i+1));
            GMlib::SqMatrix<float,2> mt(a,GMlib::Vector<float,2>(1,0),GMlib::Vector<float,2>(0,1));
            GMlib::Point<float,2> pt = mt*GMlib::Vector<float,2>((((i+1)*r)/m),0);

            this->insertAlways(pt);
        }
    }
    if (switcher){
    this->triangulateDelaunay();}
}

void FEMobject::randomTriangulation(int n, float r)
{
    GMlib::Point<float,2> start_pt (0,0);
    auto rn = 4;// regular n
    auto m = n/rn; //number of circles

    regularTriangulation(rn,m,r,false);

    auto nm_coeff = std::max((M_PI/(sqrt(3)*(sin(M_PI/2)*sin(M_PI/2))+2-n))*(1/2*n), 1.1);

    auto num = 1+n*nm_coeff;
    int t = num*0.8;//number of swaps

    std::cout << this->getSize() << std::endl;

    for(int i=0;i<t;i++)
    {
        std::cout << "Shuffle cycle num:" << i << std::endl;

        auto p1 = (*this)[randNum(0,this->getSize())];
        auto p2 = (*this)[randNum(0,this->getSize())];

        std::swap(p1,p2);
    }
    for (int j = 0; j < num*4; j++)
    {
        int todel = randNum(0,this->getSize()-1);

        auto distVector = GMlib::Vector<float,2>(start_pt-(*this)[todel]);
        double dist = distVector.getLength();

        if (std::abs(dist - r) > 0.01)
        {
            this->removeIndex(todel);
        }

    }

    std::cout << this->getSize() << std::endl;

    this->triangulateDelaunay();

}

GMlib::Vector<GMlib::Vector<float, 2>, 3> FEMobject::vectorArray(GMlib::TSTriangle<float>* tr, Node *node)
{

    GMlib::Point<float,2> p0,p1,p2;
    GMlib::Vector<GMlib::Vector<float,2>,3> d; //output
    GMlib::Array<GMlib::TSVertex<float>*>   v = tr->getVertices();

    if (node->isThis(v[1])){
        std::swap(v[0],v[1]);
        std::swap(v[1],v[2]);
        }
    if (node->isThis(v[2])){
        std::swap(v[0],v[2]);
        std::swap(v[1],v[2]);
        }
    p0 = v[0]->getParameter();
    p1 = v[1]->getParameter();
    p2 = v[2]->getParameter();

    d[0] = p1 - p0;
    d[1] = p2 - p0;
    d[2] = p2 - p1;

    return d;

}

void FEMobject::computation()
{
/**


**/
    for (int i=0;i<this->size();i++){

        if (!(this->getVertex(i)->boundary())) {
                //GMlib::TSVertex<float>* vt = this->getVertex(i) ;
                 //Node node = Node();
                 //node._vt = vt;
                 //nodes.insertAlways(node,true);

            //std::cout << i << std::endl;

            nodes+= Node((*this)[i]);
            }
        }
        //std::cout << nodes.getSize() << std::endl;
        A.setDim(nodes.getSize(),nodes.getSize());
        b.setDim(nodes.getSize());

        //set zeroes in _A
            for(int i=0; i<A.getDim1();i++){
                for (int j=0;j<A.getDim2();j++){
                    A[i][j] = 0;
                }
            }

        //computation
        for (int i=0;i<nodes.getSize();i++){

            //Non diagonal elements
            GMlib::Vector<GMlib::Vector<float,2>,3> d;
            for (int j=0;j<i;j++){

                GMlib::TSEdge<float>* edg = nodes[i].neighboor(nodes[j]);
                if (edg != NULL){

                    d = vectorArrays(edg);
                    auto d0 = d[0];
                    auto d1 = d[1];
                    auto d2 = d[2];

                    auto dd =  1/ (std::abs(d0 * d0));

                    auto dh1 = dd * (d1 * d0);
                    auto dh2 = dd * (d2 * d0);

                    auto area1 = std::abs(d0^d1);
                    auto area2 = std::abs(d0^d2);

                    auto h1 = dd * (area1 * area1);
                    auto h2 = dd * (area2 * area2);

                    A[i][j] = (dh1 * (1 - dh1) / h1 - dd) * area1 * 0.5 + (dh2 * (1 - dh2) / h2 - dd) * area2 * 0.5;

                    A[j][i] = A[i][j];
                    //std::cout << A[i][j] << std::endl;

                }
            }

            GMlib::Array <GMlib::TSTriangle<float>*> tr = nodes[i].getTriangles();

            float Tk =0.0;
            for (int k=0;k<tr.getSize();k++){
               d = vectorArray(tr[k],&nodes[i]);
               auto d0 = d[0];
               auto d1 = d[1];
               auto d2 = d[2];

               Tk += (d2 * d2) / (std::abs(d0 ^ d1) * 2);//*0.5
            }
            A[i][i] = Tk;
        }

        for (int i=0;i<nodes.getSize();i++){

            GMlib::Array <GMlib::TSTriangle<float>*> tr = nodes[i].getTriangles();

            float bsum = 0;
            for (int k=0;k<tr.getSize();k++){

                bsum += tr[k]->getArea2D()/3;
            }
            b[i] = bsum;
        }
        A.invert();

}

void FEMobject::localSimulate(double dt)
{
    if (forceswicher == true)
        force += dt;

    if(forceswicher == false)
        force -= dt;

    if (force >= _max)
       forceswicher = false;

    if (force <= _min)
       forceswicher = true;

    updateHeight(force);
}

void FEMobject::setMaxVal(float f)
{
    _max = f;

}

float FEMobject::getMaxVal()
{
    return _max;

}


void FEMobject::updateHeight(float f)
{
    GMlib::DVector<float> x1;
    x1.setDim(nodes.getSize());
    x1 = (f*b);
    GMlib::DVector<float> x = A*x1;

    for (int i=0;i<nodes.getSize();i++){
        this->nodes[i].setZ(x[i]);
    }

}

GMlib::Vector<GMlib::Vector<float, 2>, 3> FEMobject::vectorArrays(GMlib::TSEdge<float>* edg)
{

    GMlib::Array<GMlib::TSTriangle<float>*> tr = edg->getTriangle();

    GMlib::Array<GMlib::TSVertex<float>*>   v1 = tr[0]->getVertices();
    GMlib::Array<GMlib::TSVertex<float>*>   v2 = tr[1]->getVertices();

    GMlib::Vector<GMlib::Vector<float,2>,3> d; //output
    GMlib::Point<float,2> p0,p1,p2,p3;

    p0 = edg->getFirstVertex()->getParameter();
    p1 = edg->getLastVertex()->getParameter();

    //p2
    for(int i=0;i<3;i++){
        if(v1[i]!=edg->getFirstVertex() && v1[i]!=edg->getLastVertex())
            p2 = v1[i]->getParameter();
    }
    //p3
    for(int i=0;i<3;i++){
        if(v2[i]!=edg->getFirstVertex() && v2[i]!=edg->getLastVertex())
            p3 = v2[i]->getParameter();
    }

    d[0] = p1 - p0;
    d[1] = p2 - p0;
    d[2] = p3 - p0;

    return d;

}
