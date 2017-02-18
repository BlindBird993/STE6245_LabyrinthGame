#include "node.h"

Node::Node()
{

}

Node::Node(GMlib::TSVertex<float> &nodeVert)
{
    _vt = &nodeVert;
}

bool Node::isThis(GMlib::TSVertex<float>* thisvt)
{
  if (thisvt == this->_vt){
      return true;
  }
  return false;
}

GMlib::Array<GMlib::TSTriangle<float> *> Node::getTriangles()
{
    return this->_vt->getTriangles();
}

GMlib::TSEdge<float> *Node::neighboor(Node& n)
{

    GMlib::Array<GMlib::TSEdge<float>*> edg = _vt->getEdges();

    for(int i=0;i<edg.size();i++){

        if (n.isThis(edg[i]->getOtherVertex(*_vt)))

            return edg[i];
    }
    return NULL;
}

void Node::setZ(float z)
{
    this->_vt->setZ(z);
}
