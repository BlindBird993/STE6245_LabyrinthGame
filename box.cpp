#include "box.h"
Box::~Box() {

}

std::vector<std::shared_ptr<collision::StaticPPlane> > Box::getPlanes() const
{
    return planes;
}

//std::vector<std::shared_ptr<collision::StaticPSphere> > Box::getSpheres() const
//{
//    return spheres;
//}

Box::Box(double x, double y, double z, GMlib::Material color)
{
    this->x=x;//20
    this->y=y;//40
    this->z=z;//10

    //this->a=a;//2

    //double r=a/2;

    this->color=color;

    //south
    planes.push_back( std::make_unique<collision::StaticPPlane>
                      (GMlib::Point<float,3>(-x, -x, z),
                       GMlib::Vector<float,3>(y, 0.0f, 0.0f),
                       GMlib::Vector<float,3>(0.0f, 0.0f, -z)));

    //planes.at(0)->setMaterial(color);

    //north
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x, x, z),
                      GMlib::Vector<float,3>(-y, 0.0f, 0.0f),
                      GMlib::Vector<float,3>(0.0f, 0.0f, -z)));

     //planes.at(1)->setMaterial(color);
///
    //first wall
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(10.0f, 15.0f, 0.0f),
//                      GMlib::Vector<float,3>(-30.0f, 0.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f)));

//     planes.at(2)->setMaterial(GMlib::GMmaterial::blackPlastic());

//    //first wall2
//    planes.push_back(std::make_unique<collision::StaticPPlane> //inverse
//                     (GMlib::Point<float,3>(10.0f, 14.9f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f),
//                      GMlib::Vector<float,3>(-30.0f, 0.0f, 0.0f)));


    //second wall
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(10.0f, 15.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, -15.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f)));
///
    //second wall2
//    planes.push_back(std::make_unique<collision::StaticPPlane>//inverse
//                     (GMlib::Point<float,3>(10.0f, 15.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f),
//                      GMlib::Vector<float,3>(0.0f, -15.0f, 0.0f)));

//        planes.at(3)->setMaterial(GMlib::GMmaterial::blackPlastic());
///
    //third wall
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(10.0f, 0.0f, 0.0f),
//                      GMlib::Vector<float,3>(-20.0f, 0.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f)));

//        planes.at(4)->setMaterial(GMlib::GMmaterial::blackPlastic());

    //third wall2
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(10.0f, 0.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f),
//                      GMlib::Vector<float,3>(-20.0f, 0.0f, 0.0f)));


    //fourth wall
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(15.0f, 10.0f, 0.0f),
//                      GMlib::Vector<float,3>(5.0f, 0.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f)));
///
    //fourth wall2
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(15.0f, 10.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f),
//                      GMlib::Vector<float,3>(5.0f, 0.0f, 0.0f)));

//        planes.at(5)->setMaterial(GMlib::GMmaterial::blackPlastic());


    //fifth wall
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(10.0f, 5.0f, 0.0f),
//                      GMlib::Vector<float,3>(5.0f, 0.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f)));


///
    //fifth wall2
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(10.0f, 5.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f),
//                      GMlib::Vector<float,3>(5.0f, 0.0f, 0.0f)));

//        planes.at(6)->setMaterial(GMlib::GMmaterial::blackPlastic());


///
    //sixth wall
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(0.0f, -5.0f, 0.0f),
//                      GMlib::Vector<float,3>(-20.0f, 0.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f)));

//        planes.at(7)->setMaterial(GMlib::GMmaterial::blackPlastic());

    //sixth wall2
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(0.0f, -5.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f),
//                      GMlib::Vector<float,3>(-20.0f, 0.0f, 0.0f)));


///
    //seventh wall
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(20.0f, -10.0f, 0.0f),
//                      GMlib::Vector<float,3>(-25.0f, 0.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f)));

//        planes.at(8)->setMaterial(GMlib::GMmaterial::blackPlastic());



    //seventh wall2
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(20.0f, -10.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, 0.0f, 5.0f),
//                      GMlib::Vector<float,3>(-25.0f, 0.0f, 0.0f)));


    //west
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(-x, x, z),
                      GMlib::Vector<float,3>(0.0f, -y, 0.0f),
                      GMlib::Vector<float,3>(0.0f, 0.0f, -z)));

        //planes.at(9)->setMaterial(color);

    //east
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x, -x, z),
                      GMlib::Vector<float,3>(0.0f, y, 0.0f),
                      GMlib::Vector<float,3>(0.0f, 0.0f, -z)));

        //planes.at(10)->setMaterial(color);

    //floor
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(-x, -x, 0.0f),
                      GMlib::Vector<float,3>(y, 0.0f, 0.0f),
                      GMlib::Vector<float,3>(0.0f, y, 0.0f)));

        //planes.at(11)->setMaterial(color);


//    spheres.push_back(std::make_unique<collision::StaticPSphere>());
//    spheres.at(0)->translateGlobal(GMlib::Vector<float,3>(10.0f,10.0f,2.0f));



    //ceiling
//    planes.push_back(std::make_unique<collision::StaticPPlane>
//                     (GMlib::Point<float,3>(x-r, y-r, z+r),
//                      GMlib::Vector<float,3>(a, 0.0f, 0.0f),
//                      GMlib::Vector<float,3>(0.0f, a, 0.0f)));



    for (const auto& plane : planes)
    {
        plane->toggleDefaultVisualizer();
        plane->replot();
        plane->setMaterial(color);
        this->insert(plane.get());

    }

    setSurroundingSphere(GMlib::Sphere<float,3>(GMlib::Point<float,3>(0.0f,0.0f,0.0f),1.0f));
}

void Box::create() {

}

