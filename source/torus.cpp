//torus.cpp

#include "torus.h"
#include "ray.h"
#include <math.h>
#include <iostream>

torus::torus() {
}


//----------------------------------------------------------------------------
// the constructor 
//----------------------------------------------------------------------------

torus::torus(vector3d position_in, float radius1, float radius2) 
             : primitive(position_in) 
{
  m_radius1 = radius1;
  m_radius2 = radius2;
}

//----------------------------------------------------------------------------
// intersection routine 
//----------------------------------------------------------------------------

float torus::intersect(ray ray) {
  float t,t1,t2,t3,t4,tmin1,tmin2 = 0.0f;
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
  float R = m_radius1;
  float r = m_radius2;
  float dx4 = pow(dx,4);
  float dx3 = pow(dx,3);
  float dx2 = pow(dx,2); 
  float dy4 = pow(dy,4);
  float dy3 = pow(dy,3);
  float dy2 = pow(dy,2); 
  float dz4 = pow(dz,4);
  float dz3 = pow(dz,3);
  float dz2 = pow(dz,2); 
  float ox4 = pow(ox,4);
  float ox3 = pow(ox,3);
  float ox2 = pow(ox,2); 
  float oy4 = pow(oy,4);
  float oy3 = pow(oy,3);
  float oy2 = pow(oy,2); 
  float oz4 = pow(oz,4);
  float oz3 = pow(oz,3);
  float oz2 = pow(oz,2);
  float R2 = R*R;
  float R4 = R2*R2;
  float r2 = r*r;
  float r4 = r2*r2; 
// Koeffizienten des quartischen Polynoms
  float A =  dx4+dy4+dz4 + 2*dx2*dy2 + 2*dx2*dz2 + dy2*dz2;
  float B =  4*dx3*ox + 4*dy3*oy + 4*dz3*oz
            +4*dx2*dy*oy + 4*dx2*dz*oz + 4*dx*ox*dy2
            +4*dy2*dz*oz + 4*dx*ox*dz2 + 4*dy*oy*dz2;
  float C = -2*R2*dx2 - 2*R2*dy2 + 2*R2*dz2 
            -2*r2*dx2 - 2*r2*dy2 - 2*r2*dz2
            +6*dx2*ox2 + 2*ox2*dy2 + 8*dx*ox*dy*oy +2*dx2*oy2 
            +6*dy2*oy2 + 2*ox2*dz2 + 2*oy2*dz2 + 8*dx*ox*dz*oz
            +8*dy*oy*dz*oz + 2*dx2*oz2 + 2*dy2*oz2 + 6*dz2*oz2;
  float D = -4*R2*dx*ox - 4*R2*dy*oy + 4*R2*dz*oz 
            -4*r2*dx*ox - 4*r2*dy*oy - 4*r2*dz*oz
            +4*dx*ox3 + 4*ox2*dy*oy + 4*dx*ox*oy2
            +4*dy*oy3 + 4*ox2*dz*oz + 4*oy2*dz*oz 
            +4*dx*ox*oz2 + 4*dy*oy*oz2 + 4*dz*oz3; 
  float E =  R4 - 2*R2*ox2 - 2*R2*oy2 + 2*R2*oz2 + r4 - 2*r2*R2
            -2*r2*ox2 - 2*r2*oy2 - 2*r2*oz2 + ox4 + oy4 + oz4
            +2*ox2*oy2 + 2*ox2*oz2 + 2*oy2*oz2;
// normalize and reduce
  float alpha = -(3*pow(B,2))/(8*pow(A,2)) + C/A;
  float beta  =  pow(B,3)/(8*pow(A,3)) - B*C/(2*pow(A,2)) + D/A;
  float gamma = -(3*pow(B,4))/(256*pow(A,4)) + pow(B,2)*C/16*pow(A,3) - B*D/(4*pow(A,2)) + E/A;
  
  float P = -(pow(alpha,2))/12 - gamma;
  float Q = -(pow(alpha,3))/108 + alpha*gamma/3 - pow(beta,2)/8;
   
  float y = -5/6 * alpha;

  if (P == 0) 
  { 
    y = y - pow(Q,1/3);
  }
  else 
  { 
    float U = pow(-Q/2+sqrt(Q*Q/4+pow(P,3)/27),1/3); 
    y = y + P/(3*U)-U; 
  }
  
  float w = sqrt(alpha+2*y);
  float z = beta/(2*w);

// Nullstellen des Polynoms
  float diskriminante = (-(alpha+2*y)-2*(alpha+beta/w));
  if (diskriminante >= 0)
  {
    t1 = -B/(4*A) + 0.5f * ( w+sqrt(diskriminante));
    t2 = -B/(4*A) + 0.5f * (-w+sqrt(diskriminante));
    if ((t1>0.01f) && (t2>0.01f))
    {
    if (t1<t2) tmin1=t1; else tmin1=t2;
    } else tmin1=-1;
  }
  diskriminante = (-(alpha+2*y)-2*(alpha-beta/w));
  if (diskriminante >= 0)
  {
    t3 = -B/(4*A) + 0.5f * ( w+sqrt(diskriminante));
    t4 = -B/(4*A) + 0.5f * (-w+sqrt(diskriminante));
    if ((t3>0.01f) && (t4>0.01f))
    {
    if (t3<t4) tmin2=t3; else tmin2=t4;
    } else tmin2=-1;
  }
  if ((tmin1==-1) && (tmin2==-1)) t = -1;
  else
  {
    if (tmin1<tmin2) t=tmin1; else t=tmin2;
  }
  return t;
}

//----------------------------------------------------------------------------
// getNormal
//----------------------------------------------------------------------------

vector3d torus::getNormal(vector3d ap) {

//----------------------------------------------------------------------------
// returns the normal at the position p
//----------------------------------------------------------------------------

  //analytically
  vector3d p = getPosition();//transformPosition(ap); 
  vector3d normal = ap-p;// - getPosition();
  normal.Normalize();
  //normal = transformNormal(normal); 

  float r = getRadius1(); 
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
