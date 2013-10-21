//implicit.cpp

#include "implicit.h"
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
  float t,t1,t2 = 0;
  t = -1.0;
  return t;
}

//----------------------------------------------------------------------------
// getNormal
//----------------------------------------------------------------------------

vector3d implicit::getNormal(vector3d ap) {

//----------------------------------------------------------------------------
// returns the normal at the position p
//----------------------------------------------------------------------------

  vector3d normal(0.0,0.0,0.0);
  
  return normal;
}

double implicit::func(double x) {
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

