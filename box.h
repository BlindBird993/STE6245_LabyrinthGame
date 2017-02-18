#ifndef BOX_H
#define BOX_H
//#include <vector>


#include <vector>

#include <parametrics/gmpplane>
#include <parametrics/gmpsphere>
#include <parametrics/gmpcylinder>
#include <scene/gmsceneobject>

#include <collision_interface.h>

#include <memory>

class Box : public GMlib::SceneObject {
    GM_SCENEOBJECT(Box)
    public:
    // 6 planes
    std::vector<std::shared_ptr<collision::StaticPPlane>> planes;
    // 12 edges
    //  std::vector <GMlib::PCylinder<float>> cylinders;
    // 8 vertices
    // std::vector <GMlib::PSphere<float>> spheres;

    double x;
    double y;
    double z;

    //double a;

    GMlib::Material color;

    Box(double, double, double, GMlib::Material);

    ~Box();

    void create();

    std::vector<std::shared_ptr<collision::StaticPPlane> > getPlanes() const;

protected:
    // void localSimulate(double dt) override;

private:


}; // END class Box
#endif // BOX_H
