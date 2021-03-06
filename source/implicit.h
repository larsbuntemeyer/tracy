//implicit.h

#ifndef _IMPLICIT_
#define _IMPLICIT_

#include "vector3d.h"
#include "primitive.h"
#include "ray.h"
#include <iostream>

using namespace std;

class implicit : public primitive {
  public:
    implicit();
    implicit(vector3d position_in);
    float intersect(ray ray);
    vector3d getNormal(vector3d p);
  private:
    double func(double t);
    double implicitSurface(vector3d p);
    double zbrent(double x1, double x2, double tol);
    ray searchRay;
};

#endif
