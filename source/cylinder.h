//cylinder.h

#ifndef _CYLINDER__
#define _CYLINDER_

#include "vector3d.h"
#include "primitive.h"
#include "locator.h"

class cylinder : public primitive {
  public:
    cylinder();
    cylinder(vector3d position_in, float radius, float height);
    float intersect(ray ray);
    vector3d getNormal(vector3d p);
    float getRadius() {return m_radius;};
  private:
    float m_radius;
    float m_height;
};

#endif
