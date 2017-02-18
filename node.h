#ifndef NODE_H
#define NODE_H
#include <gmTrianglesystemModule>

// gmlib
#include <gmCoreModule>
#include <gmSceneModule>
#include <gmParametricsModule>

class Node
{
public:
    GMlib::TSVertex<float>* _vt;
public:
    Node();
    Node(GMlib::TSVertex<float> &nodeVert);

    bool isThis(GMlib::TSVertex<float>* thisvt);
    GMlib::Array<GMlib::TSTriangle<float>*> getTriangles();
    GMlib::TSEdge<float>* neighboor(Node& n);
    void setZ(float z);


};

#endif // NODE_H
