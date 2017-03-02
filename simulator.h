#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <collision_library.h>
#include "femobject.h"
#include <gmParametricsModule>
#include <vector>

#include "box.h"



/**
using DynSphere =
    collision::DynamicPhysObject<GMlib::PSphere<float>>;
using Plane =
    collision::StaticPhysObject<GMlib::PPlane<float>>;
using Cylinder =
    collision::StaticPhysObject<GMlib::PCylinder<float>>;

using DynSpherePtrVector = std::vector<DynSphere*>;
using DynPlanePtrVector = std::vector<Plane*>;
using DynCylinderPtrVector = std::vector<Cylinder*>;

using DynSphereVector = std::vector<std::unique_ptr<DynSphere>>;
using DynPlaneVector = std::vector<std::unique_ptr<Plane>>;
using DynCylinderVector = std::vector<std::unique_ptr<Cylinder>>;


//class SimulationController : public GMlib::SceneObject {
//  GM_SCENEOBJECT(SimulationController)
//public:
//  SimulationController() = default;

//  void add (DynSphere* const sphere );
//  void add (Plane* const plane);
//protected:
//  void localSimulate(double dt) override final;

//private:
//  DynSpherePtrVector _dspheres;
//  DynPlanePtrVector _planes;
//  collision::DefaultEnvironment _environment;
//};

class Simulator {
public:
    explicit Simulator( GMlib::Scene& scene);
    void setupSimulator();
    void setupRollingSim();
    void simulateReplotSim();

private:

    GMlib::Scene& _scene;

    FEMobject*    _obj1;
    FEMobject*    _obj2;

    collision::MyController _controller;
    DynSphereVector _dspheres;
    DynPlaneVector _planes;
    DynCylinderVector _cylinders;

    template <typename T>
    void prepareAndInsert(const std::unique_ptr<T>& obj, int m1,int m2, int d1, int d2);
};



template <typename T>
inline
void Simulator::prepareAndInsert (const std::unique_ptr<T>& obj, int m1,int m2, int d1, int d2){

 obj->toggleDefaultVisualizer();
 obj->replot(m1,m2,d1,d2);
 _scene.insert(obj.get());
_controller.add(obj.get());
}
**/


//helper types
using DynSphere = collision::DynamicPhysObject<GMlib::PSphere<float>>;
using Plane = collision::StaticPhysObject<GMlib::PPlane<float>>;
using Cylinder = collision::StaticPhysObject<GMlib::PCylinder<float>>;


using DynSphereVector = std::vector<std::unique_ptr<DynSphere>>;
using PlaneVector =  std::vector<std::unique_ptr<Plane>>;
using BoxVector =  std::vector<std::unique_ptr<Box>>;

using DynCylinderVector = std::vector<std::unique_ptr<Cylinder>>;

/*class SimulationController : public GMlib::SceneObject{
    GM_SCENEOBJECT(SimulationController)
public:
    SimulationController() = default;
    void add(DynSphere* const sphere); // const here means you can't delete the pointer or change to what it points to
    void add(Plane* const plane);

protected:
    void localSimulate(double dt) override final; //should be named localSimulate if not compiler would complain

private:
    DynSpherePtrVector     _dspheres;
    PlanePtrVector         _planes;


};*/
class Simulator{
public:
    explicit Simulator ( GMlib::Scene& scene);

    void setupSimulator();
    void setupRollingSim();
    //FEM
    void simulateReplotSim();

    collision::DynamicPhysObject<GMlib::PSphere<float> >*   _controlSphere;



private:
    GMlib::Scene&                    _scene;
    collision::MyController         _controller;

    DynSphereVector                  _dspheres;
    PlaneVector                      _planes;
    BoxVector                        _box;
    DynCylinderVector                _cylinders;

    FEMobject*    _obj1;
    FEMobject*    _obj2;

    template <typename T>
    void prepareAndInsert(const std::unique_ptr<T>& obj, int m1, int m2, int d1, int d2);

};

template <typename T>
inline
void Simulator::prepareAndInsert(const std::unique_ptr<T>& obj, int m1, int m2, int d1, int d2){

    obj->toggleDefaultVisualizer();
    obj->replot(m1,m2,d1,d2);
    _scene.insert(obj.get());
    _controller.add(obj.get());
}

template <> inline
void Simulator::prepareAndInsert<Box>(const std::unique_ptr<Box>& obj, int m1, int m2, int d1, int d2)
{
    _scene.insert(obj.get());

    for (const  auto& plane : obj->getPlanes())
        _controller.add(plane.get());
}




#endif // SIMULATOR_H
