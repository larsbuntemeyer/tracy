//plane.cpp

#include "plane.h"
#include "ray.h"
#include "vector3d.h"
#include <cmath>
#include <cstdlib>

plane::plane() {
}

plane::plane(vector3d position, vector3d normal,
             float length, float width) : primitive(position) {

  mNormal = normal; 
  mLength = length;
  mWidth = width;
//  setMaterial(material(color(0,0,0)));
}

//----------------------------------------------------------------------------
// intersection routine
//----------------------------------------------------------------------------

float plane::intersect(ray ray) {
  float t = 0;
  vector3d o = getInverseScaling() * 
               getInverseRotation() * 
               getInverseTranslation() * ray.getOrigin();
  vector3d d = getInverseScaling() *
               getInverseRotation() * ray.getDirection();
  vector3d p(0,0,0);//getPosition();
  float dn = d * mNormal;
  if (dn != 0) 
  {
    t = mNormal * (p - o) / dn;
    if (t>0.01f)
    {
    vector3d distance = o + t*d - p;
    //if (distance.getLength() > getLength()) t = -1;
    if ((abs(distance.getX()) > getLength()/2) || (abs(distance.getZ()) > getWidth()/2))
      t = -1;
    } else t=-1;
  } else t=-1;
  return t;
}


//----------------------------------------------------------------------------
// getNormal
//----------------------------------------------------------------------------

vector3d plane::getNormal(vector3d p) {
  vector3d normal = mNormal;
  normal = getInverseScaling() * getRotation() * normal;
  return mNormal;
}
