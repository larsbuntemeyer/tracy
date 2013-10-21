//hyperboloid.cpp

#include "hyperboloid.h"
#include "ray.h"
#include <math.h>
#include <iostream>
using namespace std;

hyperboloid::hyperboloid() {
}

hyperboloid::hyperboloid(vector3d position_in, float radius, float height,
        float alpha, float beta, float gamma) : primitive(position_in) {

  m_radius = radius;
  mAlpha = alpha;
  mBeta = beta;
  mGamma = gamma;
  mHeight = height;
}

float hyperboloid::intersect(ray ray) {
  float t,t1,t2 = 0;
  vector3d o = transformPosition(ray.getOrigin());//ray.getOrigin();
  vector3d d = transformDirection(ray.getDirection());
  vector3d p(0,0,0);//getPosition();
  float ox = o.getX();
  float oz = o.getY();
  float oy = o.getZ();
  float dx = d.getX();
  float dz = d.getY();
  float dy = d.getZ();
  float px = p.getX();
  float pz = p.getY();
  float py = p.getZ();
  float r = m_radius;

  float a = pow(dx/mAlpha,2)+pow(dy/mBeta,2)-pow(dz/mGamma,2);
  float b = 2*((dx/pow(mAlpha,2))*(ox-px)+
               (dy/pow(mBeta,2)) *(oy-py)-
               (dz/pow(mGamma,2))*(oz-pz));
  float c = pow((ox-px)/mAlpha,2)+
            pow((oy-py)/mBeta,2)-
            pow((oz-pz)/mGamma,2)-r*r;

  float diskriminante = b*b - 4*a*c;

  if (diskriminante >= 0)
  {
    t1 = (-b - sqrt(diskriminante))/(2*a);
    t2 = (-b + sqrt(diskriminante))/(2*a);
    if (t2<t1)
    {
      float t3=t1;
      t1=t2;
      t2=t3; 
    }
      if ((t1>0.01f) && (t2>0.01f))
      {
        vector3d intersecPos1 = o + t1*d;
        vector3d intersecPos2 = o + t2*d;
        vector3d distance1 = intersecPos1 - p;
        vector3d distance2 = intersecPos2 - p;
        if ((sqrt(pow(distance1.getY(),2)) < mHeight/2)) t=t1;
        else
          if ((sqrt(pow(distance2.getY(),2)) < mHeight/2)) t=t2;
          else t=-1;
      } else t=-1;
  } else t=-1;
  
  return t;
}

vector3d hyperboloid::getNormal(vector3d p) {

  vector3d tp = transformPosition(p);
  float r = getRadius(); 
  float h = 0.1f;
  float x = tp.getX();
  float y = tp.getY();
  float z = tp.getZ();
  float px = 0;//getPosition().getX();
  float py = 0;//getPosition().getY();
  float pz = 0;//getPosition().getZ();

  //numerically
  float dfdx = 2*x/pow(mAlpha,2);//((x-px+h)*(x-px+h)-(x-px)*(x-px))/(h*pow(mAlpha,2));
  float dfdy = 2*y/pow(mAlpha,2);//((y-py+h)*(y-py+h)-(y-py)*(y-py))/(h*pow(mBeta,2));
  float dfdz = -2*z/pow(mAlpha,2);//(-1*(z-pz+h)*(z-pz+h)+(z-pz)*(z-pz))/(h*pow(mGamma,2));
  vector3d normal1(dfdx,dfdy,dfdz);
  normal1 = transformNormal(normal1);

  return normal1;
}
