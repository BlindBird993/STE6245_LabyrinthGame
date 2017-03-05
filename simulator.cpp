#include "simulator.h"
//#include "femobject.h"


/*
void SimulationController::add(DynSphere * const sphere)
{
  sphere->environment = &_environment;
  _dspheres.push_back(sphere);
}

void SimulationController::add(Plane * const plane)
{
    _planes.push_back(plane);
}

void SimulationController::localSimulate(double dt)
{
    //add collision algorithm here
        for(auto sphere:_dspheres){
            sphere->simulateToTInDt(seconds_type(dt));
        }
}
*/
//void MyController::localSimulate(double dt)
//{
// //Algorithm here ^^
//}
/**

Simulator::Simulator(GMlib::Scene &scene): _scene{scene}
{
    _scene.insert(&_controller);
}

void Simulator::setupSimulator()
{
        _dspheres.push_back(std::make_unique<DynSphere>());
//        _dspheres.push_back(std::make_unique<DynSphere>());
//        _dspheres.push_back(std::make_unique<DynSphere>());
//        _dspheres.push_back(std::make_unique<DynSphere>());
//        _dspheres.push_back(std::make_unique<DynSphere>());
//        _dspheres.push_back(std::make_unique<DynSphere>());
//        _dspheres.push_back(std::make_unique<DynSphere>());
//        _dspheres.push_back(std::make_unique<DynSphere>());

        _dspheres.back()->setMaterial(GMlib::GMmaterial::chrome());
//        _dspheres.at(0)->setMaterial(GMlib::GMmaterial::obsidian());
//        _dspheres.at(1)->setMaterial(GMlib::GMmaterial::plastic());
//        _dspheres.at(2)->setMaterial(GMlib::GMmaterial::polishedGreen());
//        _dspheres.at(3)->setMaterial(GMlib::GMmaterial::brass());
//        _dspheres.at(4)->setMaterial(GMlib::GMmaterial::sapphire());
//        _dspheres.at(5)->setMaterial(GMlib::GMmaterial::gold());
//        _dspheres.at(6)->setMaterial(GMlib::GMmaterial::jade());
//        _dspheres.at(7)->setMaterial(GMlib::GMmaterial::pewter());

        _dspheres.back()->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 1.0f));
//        _dspheres.at(1)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
//        _dspheres.at(2)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
//        _dspheres.at(3)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
//        _dspheres.at(4)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
//        _dspheres.at(5)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
//        _dspheres.at(6)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));
//        _dspheres.at(7)->translateGlobal(GMlib::Vector<float,3> (0.0f, 0.0f, 2.0f));

        _dspheres.back()->velocity=GMlib::Vector<double,3> (5.0f, -10.0f, 0.0f);
//        _dspheres.at(0)->velocity=GMlib::Vector<double,3> (10.0f, 10.0f, 0.0f);
//        _dspheres.at(1)->velocity=GMlib::Vector<double,3> (15.0f, -10.0f, 0.0f);
//        _dspheres.at(2)->velocity=GMlib::Vector<double,3> (20.0f, 10.0f, 0.0f);
//        _dspheres.at(3)->velocity=GMlib::Vector<double,3> (25.0f, -10.0f, 0.0f);
//        _dspheres.at(4)->velocity=GMlib::Vector<double,3> (30.0f, 10.0f, 0.0f);
//        _dspheres.at(5)->velocity=GMlib::Vector<double,3> (35.0f, -10.0f, 0.0f);
//        _dspheres.at(6)->velocity=GMlib::Vector<double,3> (40.0f, 10.0f, 0.0f);
//        _dspheres.at(7)->velocity=GMlib::Vector<double,3> (45.0f, -10.0f, 0.0f);



        //_cylinders.at(0)

//_dspheres.push_back(std::make_unique<DynSphere>());
//_dspheres.push_back(std::make_unique<DynSphere>());
//_dspheres.push_back(std::make_unique<DynSphere>());

//_dspheres.push_back(std::make_unique<DynSphere>());
//_dspheres.push_back(std::make_unique<DynSphere>());
//_dspheres.push_back(std::make_unique<DynSphere>());

//_dspheres.push_back(std::make_unique<DynSphere>());
//_dspheres.push_back(std::make_unique<DynSphere>());
//_dspheres.push_back(std::make_unique<DynSphere>());

//_dspheres.at(0)->velocity = GMlib::Vector<double,3>(0.0f,10.0f,0.0f);
//_dspheres.at(0)->translateGlobal(GMlib::Vector<float,3>(0.0f,10.0f,2.0f));

//_dspheres.at(1)->velocity = GMlib::Vector<double,3>(0.0f,-10.0f,0.0f);
//_dspheres.at(1)->translateGlobal(GMlib::Vector<float,3>(1.0f,-10.0f,2.0f));

//_dspheres.at(2)->velocity = GMlib::Vector<double,3>(14.0f,1.0f,0.0f);
//_dspheres.at(2)->translateGlobal(GMlib::Vector<float,3>(0.0f,0.0f,2.0f));

//_dspheres.at(3)->velocity = GMlib::Vector<double,3>(30.0f,-10.0f,0.0f);
//_dspheres.at(3)->translateGlobal(GMlib::Vector<float,3>(0.0f,10.0f,2.0f));

//_dspheres.at(4)->velocity = GMlib::Vector<double,3>(-10.0f,-20.0f,0.0f);
//_dspheres.at(4)->translateGlobal(GMlib::Vector<float,3>(0.0f,0.0f,2.0f));

//_dspheres.at(5)->velocity = GMlib::Vector<double,3>(10.0f,20.0f,0.0f);
//_dspheres.at(5)->translateGlobal(GMlib::Vector<float,3>(0.0f,0.0f,2.0f));

//_dspheres.at(6)->velocity = GMlib::Vector<double,3>(30.0f,-10.0f,0.0f);
//_dspheres.at(6)->translateGlobal(GMlib::Vector<float,3>(0.0f,10.0f,2.0f));

//_dspheres.at(7)->velocity = GMlib::Vector<double,3>(-10.0f,-20.0f,0.0f);
//_dspheres.at(7)->translateGlobal(GMlib::Vector<float,3>(0.0f,0.0f,2.0f));

//_dspheres.at(8)->velocity = GMlib::Vector<double,3>(10.0f,20.0f,0.0f);
//_dspheres.at(8)->translateGlobal(GMlib::Vector<float,3>(0.0f,0.0f,2.0f));



//auto* norm_visu = new GMlib::PSurfNormalsVisualizer<float,3>();
                    //norm_visu...
//_planes.back()->insertVisualizer(norm_visu);

//south
_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (-20.0f,-20.0f,10.0f),
                      GMlib::Vector<float,3> (40.0f,0.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                  ));

//south2
_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (-20.0f,-19.8f,10.0f),
                      GMlib::Vector<float,3> (40.0f,0.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                  ));

//east
_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (20.0f,-20.0f,10.0f),
                      GMlib::Vector<float,3> (0.0f,40.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                  ));

//east2
_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (19.8f,-20.0f,10.0f),
                      GMlib::Vector<float,3> (0.0f,40.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                  ));

//west
_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (-20.0f,20.0f,10.0f),
                      GMlib::Vector<float,3> (0.0f,-40.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                  ));

//west2
_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (-19.8f,20.0f,10.0f),
                      GMlib::Vector<float,3> (0.0f,-40.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                  ));

//north
_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (20.0f,20.0f,10.0f),
                      GMlib::Vector<float,3> (-40.0f,0.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                  ));

//north2
_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (20.0f,19.8f,10.0f),
                      GMlib::Vector<float,3> (-40.0f,0.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                  ));

//surface
_planes.push_back(std::make_unique<Plane>(
                      GMlib::Point<float,3> (-20.0f,-20.0f,0.0f),
                      GMlib::Vector<float,3> (40.0f,0.0f,0.0f),
                      GMlib::Vector<float,3> (0.0f,40.0f,0.0f)
                  ));

//_cylinders.push_back(std::make_unique<Cylinder>(2,2,15));

for (const auto& sphere:_dspheres)
    prepareAndInsert(sphere, 15,15, 1,1);

//for (const auto& cylinder:_cylinders)
//    prepareAndInsert(cylinder, 150,150, 1,1);

for (const auto& plane:_planes){
    prepareAndInsert(plane, 10,10,1,1);
}

//_obj1 = new FEMobject();
//_obj2 = new FEMobject();

//_obj1->regularTriangulation(10,5,5,true);
//_obj2->randomTriangulation(50,5);

//_obj1->translateGlobal(GMlib::Vector<float,3> (12.0f,0.0f,0.0f),true);
//_obj1->computation();
//_obj1->updateHeight(1);

//_obj2->computation();
//_obj2->updateHeight(1);

//_obj1->toggleDefaultVisualizer();


//_obj2->toggleDefaultVisualizer();


//_scene.insert(_obj1);
//_scene.insert(_obj2);

//delete(_obj);

_scene.insert(&_controller);
}

void Simulator::setupRollingSim()
{
 _dspheres.push_back(std::make_unique<DynSphere>());

 _dspheres.back()->translateGlobal(GMlib::Vector<float,3> (-1.0f, 0.0f, 1.0f));
 _dspheres.back()->velocity=GMlib::Vector<double,3> (0.0f, 0.0f, 0.0f);


 _planes.push_back(std::make_unique<Plane>(
                       GMlib::Point<float,3> (-10.0f,-10.0f,0.0f),
                       GMlib::Vector<float,3> (20.0f,0.0f,-1.0f),
                       GMlib::Vector<float,3> (0.0f,20.0f,0.0f)
                   ));


 for (const auto& sphere:_dspheres)
     prepareAndInsert(sphere, 15,15, 1,1);

 for (const auto& plane:_planes){
     prepareAndInsert(plane, 10,10,1,1);
 }

}

void Simulator::simulateReplotSim()
{
        //    _obj1->replot();
        //    _obj2->replot();
}
**/


Simulator::Simulator(GMlib::Scene& scene) : _scene{scene}
{

}

//FEM
    void Simulator::simulateReplotSim()
    {
//                _obj1->replot();
//                _obj2->replot();
    }


void Simulator::setupSimulator()
{
//Planes
/**
    _dspheres.push_back(std::make_unique<DynSphere>());
    _dspheres.push_back(std::make_unique<DynSphere>());
    _dspheres.push_back(std::make_unique<DynSphere>());


    _dspheres.at(0)->velocity = GMlib::Vector<double,3>(0.0f,0.0f,0.0f);
    _dspheres.at(0)->translateGlobal(GMlib::Vector<float,3>(0.0f,10.0f,2.0f));

    _dspheres.at(1)->velocity = GMlib::Vector<double,3>(0.0f,0.0f,0.0f);
    _dspheres.at(1)->translateGlobal(GMlib::Vector<float,3>(1.0f,-10.0f,2.0f));

    _dspheres.at(2)->velocity = GMlib::Vector<double,3>(0.0f,1.0f,0.0f);
    _dspheres.at(2)->translateGlobal(GMlib::Vector<float,3>(0.0f,0.0f,2.0f));

    //south
    _planes.push_back(std::make_unique<Plane>(
                          GMlib::Point<float,3> (-20.0f,-20.0f,10.0f),
                          GMlib::Vector<float,3> (40.0f,0.0f,0.0f),
                          GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                      ));

    //south2
    _planes.push_back(std::make_unique<Plane>(
                          GMlib::Point<float,3> (-20.0f,-19.8f,10.0f),
                          GMlib::Vector<float,3> (40.0f,0.0f,0.0f),
                          GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                      ));

    //east
    _planes.push_back(std::make_unique<Plane>(
                          GMlib::Point<float,3> (20.0f,-20.0f,10.0f),
                          GMlib::Vector<float,3> (0.0f,40.0f,0.0f),
                          GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                      ));

    //east2
    _planes.push_back(std::make_unique<Plane>(
                          GMlib::Point<float,3> (19.8f,-20.0f,10.0f),
                          GMlib::Vector<float,3> (0.0f,40.0f,0.0f),
                          GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                      ));

    //west
    _planes.push_back(std::make_unique<Plane>(
                          GMlib::Point<float,3> (-20.0f,20.0f,10.0f),
                          GMlib::Vector<float,3> (0.0f,-40.0f,0.0f),
                          GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                      ));

    //west2
    _planes.push_back(std::make_unique<Plane>(
                          GMlib::Point<float,3> (-19.8f,20.0f,10.0f),
                          GMlib::Vector<float,3> (0.0f,-40.0f,0.0f),
                          GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                      ));

    //north
    _planes.push_back(std::make_unique<Plane>(
                          GMlib::Point<float,3> (20.0f,20.0f,10.0f),
                          GMlib::Vector<float,3> (-40.0f,0.0f,0.0f),
                          GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                      ));

    //north2
    _planes.push_back(std::make_unique<Plane>(
                          GMlib::Point<float,3> (20.0f,19.8f,10.0f),
                          GMlib::Vector<float,3> (-40.0f,0.0f,0.0f),
                          GMlib::Vector<float,3> (0.0f,0.0f,-10.0f)
                      ));

    //surface
    _planes.push_back(std::make_unique<Plane>(
                          GMlib::Point<float,3> (-20.0f,-20.0f,0.0f),
                          GMlib::Vector<float,3> (40.0f,0.0f,0.0f),
                          GMlib::Vector<float,3> (0.0f,40.0f,0.0f)
                      ));


    for (auto& plane: _planes){
        prepareAndInsert(plane, 10, 10, 1,1);
    }

    for (auto& sphere: _dspheres){
        prepareAndInsert(sphere, 15, 15, 1,1);
    }
**/


 //FEM

//    _obj1 = new FEMobject();
//    _obj2 = new FEMobject();

//    _obj1->regularTriangulation(10,5,5,true);
//    _obj2->randomTriangulation(50,5);

//    _obj1->translateGlobal(GMlib::Vector<float,3> (12.0f,0.0f,0.0f),true);
//    _obj1->computation();
//    _obj1->updateHeight(1);

//    _obj2->computation();
//    _obj2->updateHeight(1);

//    _obj1->toggleDefaultVisualizer();


//    _obj2->toggleDefaultVisualizer();


//    _scene.insert(_obj1);
//    _scene.insert(_obj2);


   _dspheres.push_back(std::make_unique<DynSphere>());


//   _dspheres.push_back(std::make_unique<DynSphere>());
//   _dspheres.push_back(std::make_unique<DynSphere>());
//   _dspheres.push_back(std::make_unique<DynSphere>());

//   _dspheres.push_back(std::make_unique<DynSphere>());
//   _dspheres.push_back(std::make_unique<DynSphere>());
//   _dspheres.push_back(std::make_unique<DynSphere>());

   _controlSphere = (_dspheres.at(0)).get();

   _dspheres.at(0)->velocity = GMlib::Vector<double,3>(0.0f,1.0f,0.0f);
   _dspheres.at(0)->translateGlobal(GMlib::Vector<float,3>(-18.0f,18.0f,1.0f));
   _dspheres.at(0)->setMaterial(GMlib::GMmaterial::ruby());


//   _dspheres.at(1)->velocity = GMlib::Vector<double,3>(0.0f,-10.0f,0.0f);
//   _dspheres.at(1)->translateGlobal(GMlib::Vector<float,3>(1.0f,-10.0f,2.0f));
//      _dspheres.at(1)->setMaterial(GMlib::GMmaterial::brass());

//   _dspheres.at(2)->velocity = GMlib::Vector<double,3>(14.0f,1.0f,0.0f);
//   _dspheres.at(2)->translateGlobal(GMlib::Vector<float,3>(0.0f,0.0f,2.0f));
//      _dspheres.at(2)->setMaterial(GMlib::GMmaterial::gold());

//   _dspheres.at(3)->velocity = GMlib::Vector<double,3>(30.0f,-10.0f,0.0f);
//   _dspheres.at(3)->translateGlobal(GMlib::Vector<float,3>(0.0f,10.0f,2.0f));
//      _dspheres.at(3)->setMaterial(GMlib::GMmaterial::jade());


//   _dspheres.at(4)->velocity = GMlib::Vector<double,3>(0.0f,10.0f,0.0f);
//   _dspheres.at(4)->translateGlobal(GMlib::Vector<float,3>(1.0f,-10.0f,2.0f));
//      _dspheres.at(4)->setMaterial(GMlib::GMmaterial::sapphire());

//   _dspheres.at(5)->velocity = GMlib::Vector<double,3>(-14.0f,1.0f,0.0f);
//   _dspheres.at(5)->translateGlobal(GMlib::Vector<float,3>(0.0f,0.0f,2.0f));
//      _dspheres.at(5)->setMaterial(GMlib::GMmaterial::silver());

//      _dspheres.at(6)->velocity = GMlib::Vector<double,3>(10.0f,-10.0f,0.0f);
//      _dspheres.at(6)->translateGlobal(GMlib::Vector<float,3>(0.0f,10.0f,2.0f));
//         _dspheres.at(6)->setMaterial(GMlib::GMmaterial::emerald());



   _box.push_back(std::make_unique<Box>(20,40,10, GMlib::GMmaterial::copper() ));


   for (const auto& box : _box)
       prepareAndInsert(box , 10, 10, 1 ,1);
   for (const auto& plane : _planes)
       prepareAndInsert(plane , 10, 10, 1 ,1);

   for (const auto& sphere : _dspheres){
       sphere->_sphereController = &_controller;
       prepareAndInsert(sphere , 10, 10, 1 ,1);
   }



/**
    _planes.push_back(
          std::make_unique<Plane> (    GMlib::Point<float, 3> (-10.0f, 2.0f, 0.0f),
                                       GMlib::Vector<float, 3> (10.0f, -10.0f, 0.0f),
                                       GMlib::Vector<float, 3> (10.0f, 10.0f, 0.0f)));
        _planes.back()->setMaterial(GMlib::GMmaterial::polishedSilver());

    //    _planes.push_back(std::make_unique<Plane> (    GMlib::Point<float, 3> (10.0f, 10.0f, 5.0f),
    //                                                   GMlib::Vector<float, 3> (-20.0f, -20.0f, -10.0f),
    //                                                   GMlib::Vector<float, 3> (0.0f, -10.0f, 5.0f)));

    //     _dspheres.push_back(std::make_unique<DynSphere> ());
    //     _dspheres.back()->velocity = GMlib::Vector<double, 3>{0.0, 2.1, 0.0};
    //     _dspheres.back()->translate(GMlib::Vector<float,3>{1.0f,-3.0f,0.0f});

    //     _dspheres.push_back(std::make_unique<DynSphere> ());
    //     _dspheres.back()->velocity = GMlib::Vector<double, 3>{0.0, -2.1, 0.0};;
    //     _dspheres.back()->translate(GMlib::Vector<float,3>{1.0f,3.0f,0.0f});


    //    _dspheres.push_back(std::make_unique<DynSphere> ());
    //    _dspheres.back()->velocity = GMlib::Vector<double,3> (0.0f, 0.0f, 0.0f);

    //    _dspheres.push_back(std::make_unique<DynSphere> ());
    //    _dspheres.back()->velocity = GMlib::Vector<double,3> (0.0f, 0.0f, 0.0f);
    //    _dspheres.back()->translateGlobal(GMlib::Vector<float,3>{5.0f,3.0f,3.0f});

    //    _dspheres.push_back(std::make_unique<DynSphere> ());
    //    _dspheres.back()->velocity = GMlib::Vector<double,3> (0.0f, 0.0f, 0.0f);
    //    _dspheres.back()->translateGlobal(GMlib::Vector<float,3>{-5.0f,3.0f,3.0f});

    //    _dspheres.push_back(std::make_unique<DynSphere> ());
    //    _dspheres.back()->velocity = GMlib::Vector<double,3> (0.0f, -5.0f, -4.0f);
    //    _dspheres.back()->translateGlobal(GMlib::Vector<float,3>{0.0f,5.0f,5.0f});


        _dspheres.push_back(std::make_unique<DynSphere> ());
        _dspheres.back()->velocity = GMlib::Vector<double,3> (-2.0f, 0.0f, 0.0f);
        _dspheres.back()->translateGlobal(GMlib::Vector<float,3>{0.0f,0.0f,5.0f});
        _dspheres.back()->setMaterial(GMlib::GMmaterial::polishedRed());

        _dspheres.push_back(std::make_unique<DynSphere> ());
        _dspheres.back()->velocity = GMlib::Vector<double,3> (2.0f, 0.0f, 0.0f); //crash
        _dspheres.back()->translateGlobal(GMlib::Vector<float,3>{-5.0f,5.0f,2.0f});
        _dspheres.back()->setMaterial(GMlib::GMmaterial::polishedRed());

        _dspheres.push_back(std::make_unique<DynSphere> ());
        _dspheres.back()->velocity = GMlib::Vector<double,3> (20.0f, 0.0f, 0.0f);
        _dspheres.back()->translateGlobal(GMlib::Vector<float,3>{0.0f,5.0f,0.0f});
        _dspheres.back()->setMaterial(GMlib::GMmaterial::polishedRed());

    //    _dspheres.push_back(std::make_unique<DynSphere> ());
    //    _dspheres.back()->velocity = GMlib::Vector<double,3> (0.0f, -20.0f, 0.0f);
    //    _dspheres.back()->translateGlobal(GMlib::Vector<float,3>{0.0f,0.0f,5.0f});
    //    _dspheres.back()->setMaterial(GMlib::GMmaterial::polishedRed());

    //_planes.push_back(std::make_unique<Plane>( GMlib::Point<float,3>(-10.0f, -10.0f, 5.0f), GMlib::Vector<float,3>(20.0f, 0.0f, 0.0f), GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f) )); _planes.push_back(std::make_unique<Plane>( GMlib::Point<float,3>(10.0f, -10.0f, 5.0f), GMlib::Vector<float,3>(0.0f, 20.0f, 0.0f), GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f) )); _planes.push_back(std::make_unique<Plane>( GMlib::Point<float,3>(-10.0f, 10.0f, 5.0f), GMlib::Vector<float,3>(0.0f, -20.0f, 0.0f), GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f) )); _planes.push_back(std::make_unique<Plane>( GMlib::Point<float,3>(10.0f, 10.0f, 5.0f), GMlib::Vector<float,3>(-20.0f, 0.0f, 0.0f), GMlib::Vector<float,3>(0.0f, 0.0f, -5.0f) ));

        for (auto& plane: _planes)
            prepareAndInsert(plane, 10, 10, 1,1);

        for (auto& sphere: _dspheres){
            sphere->_sphereController = &_controller;
            prepareAndInsert(sphere, 10, 10, 1,1);
        }

**/
     _scene.insert(&_controller);

}


