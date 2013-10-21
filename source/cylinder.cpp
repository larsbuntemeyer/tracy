//cylinder.cpp

#include "cylinder.h"
#include "ray.h"
#include <math.h>
#include <algorithm>
#include <iostream>

cylinder::cylinder() {
}


//----------------------------------------------------------------------------
// the constructor 
//----------------------------------------------------------------------------

cylinder::cylinder(vector3d position_in, float radius, float height) 
         : primitive(position_in) {
  m_radius = radius;
  m_height = height;
}

//----------------------------------------------------------------------------
// intersection routine 
//----------------------------------------------------------------------------

float cylinder::intersect(ray ray) {
  float t1,t2 = 0.0f;
  float t = -1;
  vector3d o = transformPosition(ray.getOrigin());
  vector3d d = transformDirection(ray.getDirection());
  vector3d p(0.0f,0.0f,0.0f);
  //cylinder is same as sphere projected in the xz-plane
  vector3d o1 = o;
  vector3d d1 = d;
  o.y = 0.0f;
  d.y = 0.0f;
  float r = m_radius;
  float h = m_height;
  float a = 2*(o*d-p*d)/(d*d);
  float b = ((o-p)*(o-p)-(r*r))/(d*d);
  float diskriminante = (a*a)/4 - b;

  if (diskriminante > 0)
  {
    t1 = -a/2 + sqrt(diskriminante);
    t2 = -a/2 - sqrt(diskriminante);
    if ((t1>0.001f) && (t2>0.001f))
    {
      //std::cout << "cylinder hit" << t1 << ", " << t2 << "\n";
      vector3d intersecPos1 = o1 + t1*d1;
      vector3d intersecPos2 = o1 + t2*d1;
      float y1 = sqrt(pow(intersecPos1.y,2));
      float y2 = sqrt(pow(intersecPos2.y,2));
      //std::cout << "cylinder hit" << y1 << ", " << y2 << "\n";
      if ((y1 > h/2) && (y2 > h/2)) t=-1;
      if ((y1 <= h/2) && (y2 <= h/2)) t=std::min(t1,t2);
      if ((y1 <= h/2) && (y2 > h/2)) t=t1;
      if ((y1 > h/2) && (y2 <= h/2)) t=t2;
    } else t=-1;
  } else t=-1;

  return t;
}

//----------------------------------------------------------------------------
// getNormal
//----------------------------------------------------------------------------

vector3d cylinder::getNormal(vector3d ap) {

//----------------------------------------------------------------------------
// returns the normal at the position p
//----------------------------------------------------------------------------

  //analytically
  vector3d normal = transformPosition(ap); 
  normal.y = 0.0f;
  normal.Normalize();
  //normal = transformNormal(normal); 

  float r = getRadius(); 
  float h = 0.01f;

  //numerically
//  float dfdx = ((x-px+h)*(x-px+h)-(x-px)*(x-px))/h;
//  float dfdy = ((y-py+h)*(y-py+h)-(y-py)*(y-py))/h;
//  float dfdz = ((z-pz+h)*(z-pz+h)-(z-pz)*(z-pz))/h;
//  vector3d normal1(dfdx,dfdy,dfdz);
//  normal1 = transformNormal(normal1); 

  return normal;
}
