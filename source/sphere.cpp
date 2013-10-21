//sphere.cpp

#include "sphere.h"
#include "ray.h"
#include <math.h>
#include <iostream>

sphere::sphere() {
}


//----------------------------------------------------------------------------
// the constructor 
//----------------------------------------------------------------------------

sphere::sphere(vector3d position_in, float radius) : primitive(position_in) {
  m_radius = radius;
}

//----------------------------------------------------------------------------
// intersection routine 
//----------------------------------------------------------------------------

float sphere::intersect(ray ray) {
  float t,t1,t2 = 0;
  vector3d o = ray.getOrigin();transformPosition(ray.getOrigin());
  vector3d d = ray.getDirection();//transformDirection(ray.getDirection());
  vector3d p = getPosition();
  float r = m_radius;
  float a = 2*(o*d-p*d)/(d*d);
  float b = ((o-p)*(o-p)-(r*r))/(d*d);
  float diskriminante = (a*a)/4 - b;

  if (diskriminante > 0)
  {
    t1 = -a/2 + sqrt(diskriminante);
    t2 = -a/2 - sqrt(diskriminante);
    if ((t1>0.01f) && (t2>0.01f))
    {
    if (t1<t2) t=t1; else t=t2;
    } else t=-1;
  } else t=-1;

  return t;
}

//----------------------------------------------------------------------------
// getNormal
//----------------------------------------------------------------------------

vector3d sphere::getNormal(vector3d ap) {

//----------------------------------------------------------------------------
// returns the normal at the position p
//----------------------------------------------------------------------------

  //analytically
  vector3d p = getPosition();//transformPosition(ap); 
  vector3d normal = ap-p;// - getPosition();
  normal.Normalize();
  //normal = transformNormal(normal); 

  float r = getRadius(); 
  float h = 0.01f;
  float x = p.getX();
  float y = p.getY();
  float z = p.getZ();
  float px = 0;//getPosition().getX();
  float py = 0;//getPosition().getY();
  float pz = 0;//getPosition().getZ();

  //numerically
//  float dfdx = ((x-px+h)*(x-px+h)-(x-px)*(x-px))/h;
//  float dfdy = ((y-py+h)*(y-py+h)-(y-py)*(y-py))/h;
//  float dfdz = ((z-pz+h)*(z-pz+h)-(z-pz)*(z-pz))/h;
//  vector3d normal1(dfdx,dfdy,dfdz);
//  normal1 = transformNormal(normal1); 

  return normal;
}
