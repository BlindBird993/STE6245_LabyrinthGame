#include "box.h"
Box::~Box() {

}

std::vector<std::shared_ptr<collision::StaticPPlane> > Box::getPlanes() const
{
    return planes;
}

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

    //north
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x, x, z),
                      GMlib::Vector<float,3>(-y, 0.0f, 0.0f),
                      GMlib::Vector<float,3>(0.0f, 0.0f, -z)));


    //west
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(-x, x, z),
                      GMlib::Vector<float,3>(0.0f, -y, 0.0f),
                      GMlib::Vector<float,3>(0.0f, 0.0f, -z)));

    //east
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(x, -x, z),
                      GMlib::Vector<float,3>(0.0f, y, 0.0f),
                      GMlib::Vector<float,3>(0.0f, 0.0f, -z)));

    //floor
    planes.push_back(std::make_unique<collision::StaticPPlane>
                     (GMlib::Point<float,3>(-x, -x, 0.0f),
                      GMlib::Vector<float,3>(y, 0.0f, 0.0f),
                      GMlib::Vector<float,3>(0.0f, y, 0.0f)));


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

