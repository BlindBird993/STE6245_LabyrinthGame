#include "cube.h"

Cube::~Cube() {

    // if(_cube) remove(_cube.get());
}

std::vector<std::shared_ptr<collision::StaticPPlane> > Cube::getPlanes() const
{
    return planes;
}

Cube::Cube(double x, double y, double z, double a, GMlib::Material color)
{
    this->x=x;//0
    this->y=y;//0
    this->z=z;//0
    this->a=a;//2

    double r=a/2;

    this->color=color;

    //south
    planes.push_back( std::make_unique<collision::StaticPPlane>
                      (GMlib::Point<float,3>(x+r, y+r, z+r),
                       GMlib::Vector<float,3>(-a, 0.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 0.0f, -a)));

    //north
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x+r, y-r, z-r),
                      GMlib::Vector<float,3>(-a, 0.0f, 0.0f),
                      GMlib::Vector<float,3>(0.0f, 0.0f, a)));


    //west
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x-r, y-r, z-r),
                      GMlib::Vector<float,3>(0.0f, a, 0.0f),
                      GMlib::Vector<float,3>(0.0f, 0.0f, a)));

    //east
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x+r, y-r, z+r),
                      GMlib::Vector<float,3>(0.0f, a, 0.0f),
                      GMlib::Vector<float,3>(0.0f, 0.0f, -a)));

    //floor
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x-r, y-r, z-r),
                      GMlib::Vector<float,3>(a, 0.0f, 0.0f),
                      GMlib::Vector<float,3>(0.0f, a, 0.0f)));


    //ceiling
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x-r, y-r, z+r),
                      GMlib::Vector<float,3>(a, 0.0f, 0.0f),
                      GMlib::Vector<float,3>(0.0f, a, 0.0f)));



    for (const auto& plane : planes)
    {
        plane->toggleDefaultVisualizer();
        plane->replot();
        plane->setMaterial(color);
        this->insert(plane.get());

    }
    setSurroundingSphere(GMlib::Sphere<float,3>(GMlib::Point<float,3>(0.0f,0.0f,0.0f),1.0f));
}

void Cube::create() {

    //    if(_cube) return;

    //    GMlib::Vector<float,3> d = evaluate(0.0f,0.0f,0,0)[0][0];
    //    _torus = std::make_unique<TestTorus,float,float,float>(1.5f,0.5f,0.5f);


    //    _torus->translate(d + d.getNormalized()*2.0f);
    //    _torus->rotate( GMlib::Angle(90), GMlib::Vector<float,3>( 0.0f, 1.0f, 0.0f) );
    //    _torus->toggleDefaultVisualizer();
    //    _torus->replot(200,200,1,1);
    //    _torus->setMaterial(GMlib::GMmaterial::Emerald);
    //    insert(_torus.get());
}

//void
//TestTorus::localSimulate(double dt) {

//    rotate( GMlib::Angle(90) * dt, GMlib::Vector<float,3>( 0.0f, 0.0f, 1.0f ) );
//    rotate( GMlib::Angle(180) * dt, GMlib::Vector<float,3>( 1.0f, 1.0f, 0.0f ) );
//}
