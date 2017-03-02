#ifndef FEMOBJECT_H
#define FEMOBJECT_H
#include <gmTrianglesystemModule>

// gmlib
#include <gmCoreModule>
#include <gmSceneModule>
#include <gmParametricsModule>
//
#include "node.h"


class FEMobject: public GMlib::TriangleFacets<float>
{
private:
    GMlib::ArrayLX<Node> nodes;
    GMlib::DMatrix<float> A;
    GMlib::DVector<float> b;

    float _max = 1.0;
    float _min = -1.0;


    bool forceswicher = true;
    double force = 0.0;

public:

    FEMobject():GMlib::TriangleFacets<float>(50){}
    int randNum(int nMin, int nMax);
    void regularTriangulation(int n,int m, float r,bool switcher);
    void randomTriangulation(int n, float r);
    GMlib::Vector<GMlib::Vector<float,2>,3> vectorArrays(GMlib::TSEdge<float>* edg);
    GMlib::Vector<GMlib::Vector<float,2>,3> vectorArray(GMlib::TSTriangle<float>* tr, Node *node );
    void computation();

void localSimulate(double dt) override;
void setMaxVal(float f);
float getMaxVal();

void updateHeight(float f);
};

#endif // FEMOBJECT_H
