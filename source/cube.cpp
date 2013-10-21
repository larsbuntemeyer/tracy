//cube.cpp

#include "cube.h"
#include "ray.h"
#include <math.h>
#include <iostream>

cube::cube() {
}


//----------------------------------------------------------------------------
// the constructor 
//----------------------------------------------------------------------------

cube::cube(vector3d position_in) : primitive(position_in) {
  mFaces = new plane*[6];
  mFaces[0] = new plane(vector3d(0,0,0),vector3d(-1,0,0),1,1);
  mFaces[0]->translate(-0.5,0,0);
  mFaces[1] = new plane(vector3d(0,0,0),vector3d(1,0,0),1,1);
  mFaces[1]->translate(0.5,0,0);
  mFaces[2] = new plane(vector3d(0,0,0),vector3d(0,1,0),1,1);
  mFaces[2]->translate(0,0.5,0);
  mFaces[3] = new plane(vector3d(0,0,0),vector3d(0,-1,0),1,1);
  mFaces[3]->translate(0,-0.5,0);
  mFaces[4] = new plane(vector3d(0,0,0),vector3d(0,0,1),1,1);
  mFaces[4]->translate(0,0,0.5);
  mFaces[5] = new plane(vector3d(0,0,0),vector3d(0,0,-1),1,1);
  mFaces[5]->translate(0,0,-0.5);
}

//----------------------------------------------------------------------------
// intersection routine 
//----------------------------------------------------------------------------

float cube::intersect(ray ray) {
  float t,t1=100000;
  for (int i=0; i<6; i++)
  {
    t1 = mFaces[i]->intersect(ray);
    if (t1 < 0) t=-1;
    else if ((t1>0) && (t1<t)) {t = t1;hitFaceIndex=i;}
  } 
  return t;
}

//----------------------------------------------------------------------------
// getNormal
//----------------------------------------------------------------------------

vector3d cube::getNormal(vector3d ap) {
  return (mFaces[hitFaceIndex]->getNormal(ap));
}


//----------------------------------------------------------------------------
// setMaterial
//----------------------------------------------------------------------------

void cube::setMaterial(material aMaterial) {
  primitive::setMaterial(aMaterial);
  updateFacesMaterial();
}

void cube::updateFacesMaterial() {
  for (int i=0; i<6; i++) mFaces[i]->setMaterial(*getMaterial());
}




void cube::translate(float x, float y, float z) {
  primitive::translate(x,y,z);
  for (int i=0; i<6; i++) mFaces[i]->translate(x,y,z);
}

void cube::rotate(float x, float y, float z) {
  primitive::rotate(x,y,z);
  for (int i=0; i<6; i++) mFaces[i]->rotate(x,y,z);
}

void cube::scale(float l, float m, float n) {
  primitive::scale(l,m,n);
  for (int i=0; i<6; i++) mFaces[i]->scale(l,m,n);
}
