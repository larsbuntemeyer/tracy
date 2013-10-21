//sphere.h

#ifndef _SPHERE_
#define _SPHERE_

#include "vector3d.h"
#include "primitive.h"
#include "locator.h"

class sphere : public primitive {
  public:
    sphere();
    sphere(vector3d position_in, float radius);
    float intersect(ray ray);
    vector3d getNormal(vector3d p);
    float getRadius() {return m_radius;};
  private:
    float m_radius;
};

#endif
