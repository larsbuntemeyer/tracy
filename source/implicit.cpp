//implicit.cpp

#include "implicit.h"
#include "vector3d.h"
#include "ray.h"
#include <math.h>
#include <stdlib.h>


implicit::implicit() {
}


//----------------------------------------------------------------------------
// the constructor 
//----------------------------------------------------------------------------

implicit::implicit(vector3d position_in) : primitive(position_in) {
}

//----------------------------------------------------------------------------
// intersection routine 
//----------------------------------------------------------------------------

float implicit::intersect(ray ray) {
    
    float t,t1,fa,fb,t2,t3,tol;
    tol = 0.0001;
    t1 = 0.01;
    t2 = t1;
    t3 = 100.0;
    float n = 1000.0;
    float dt = (t3-t1)/n;
    searchRay = ray;
    fa = func(t1);
    t = -1.0;

    for(int i=1; i<n; i++) {
        t2 = t1 + i*dt;
        fb = func(t2);
        if(fa*fb<0.0) {
            t = zbrent(t1,t2,tol);
            break;
        }
    }
    
    return t;
    
}

//----------------------------------------------------------------------------
// getNormal
//----------------------------------------------------------------------------

vector3d implicit::getNormal(vector3d ap) {

//----------------------------------------------------------------------------
// returns the normal at the position p
//----------------------------------------------------------------------------

    
    vector3d normal = ap;
    normal.Normalize();
    float x = ap.getX();
    float y = ap.getY();
    float z = ap.getZ();
    float h = 0.001;
    vector3d dpdx(x+h,y,z);
    vector3d dpdy(x,y+h,z);
    vector3d dpdz(x,y,z+h);
    float dfdx;
    float dfdy;
    float dfdz;
    dfdx = (implicitSurface(dpdx)-implicitSurface(ap))/h;
    dfdy = (implicitSurface(dpdy)-implicitSurface(ap))/h;
    dfdz = (implicitSurface(dpdz)-implicitSurface(ap))/h;
    vector3d normal1(dfdx,dfdy,dfdz);
    normal1.Normalize();
  
    return normal1;
}

double implicit::func(double t) {
    
    double f;
    vector3d o,d,p;
    o = searchRay.getOrigin();
    d = searchRay.getDirection();
    
    p = o + t*d;
  
    f = implicitSurface(p);
    
    return f;
    
}

double implicit::implicitSurface(vector3d p) {
    
    double f;
    double sinx;
    double cosz;
    double x = p.getX();
    double z = p.getZ();
    sinx = sin(2.0*p.getX());
    cosz = cos(2.0*p.getZ());
    f = sinx*sinx*cosz*cosz-p.getY();
    //f = sqrt(p*p) - 1.0;
    
    
    return f;
    
}

double implicit::zbrent(double x1, double x2, double tol)
{
double a,b,fa,fb,fc,c,d,e,tol1,xm,q,r,p,eps,s,aaa,tt;
int t,itmax,iter;
    itmax = 100;
    eps = 0.00000003;
    a = x1;
    b = x2;
    fa = func(a);
    fb = func(b);
    
    if ((fb * fa) > 0.0)
{
        cout<<"root must be bracketed for zbrent"<<endl;
    }
    fc = fb;
    for (iter = 1; iter<=itmax; iter++)
{
        if ((fb * fc) > 0.0)
{
            c = a;
            fc = fa;
            d = b - a;
            e = d;
        }
        if (fabs(fc) < fabs(fb))
{
            a = b;
            b = c;
            c = a;
            fa = fb;
            fb = fc;
            fc = fa;
        }
        tol1 = 2.0 * eps * fabs(b) + 0.5 * tol;
        xm = 0.5 * (c - b);
        if ((fabs(xm) <= tol1) || (fb == 0.0))
{
tt=b;
            return tt;
exit(1);
            
        }
        if ((fabs(e) >= tol1) && (fabs(fa) > fabs(fb)))
{
            s = fb / fa;
            if (a == c)
{
                p = 2.0 * xm * s;
                q = 1 - s;
}
            else
{
                q = fa / fc;
                r = fb / fc;
                p = s * (2.0 * xm * q * (q - r) - (b - a) * (r - 1.0));
                q = (q - 1.0) * (r - 1.0) * (s - 1.0);
            }
            if (p > 0.0) q = -q;
            p = fabs(p);
            if ((3.0 * xm * q - fabs(tol1 * q)) < fabs(e * q))
{
                aaa = 3.0 * xm * q - fabs(tol1 * q);
}
            else
{
                aaa = fabs(e * q);
            }
            if ((2.0 * p) < aaa)
{
                e = d;
                d = p / q;
}
            else
{
                d = xm;
                e = d;
            }
}
        else
{
            d = xm;
            e = d;
        }
        a = b;
        fa = fb;
        if (fabs(d) > tol1)
            b = b + d;
        else
{
if (xm>0)
t=1;
if (xm==0) 
t=0;
if (xm<0) 
t=-1;
            b = b + fabs(tol1) * t;
}
        fb = func(b);
}
tt=b;
return tt;
    cout<< "zbrent exceeding maximum iterations."<<endl;
}

