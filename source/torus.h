//torus.h

#ifndef _TORUS_
#define _TORUS_

#include "vector3d.h"
#include "primitive.h"
#include "locator.h"

class torus : public primitive {
  public:
    torus();
    torus(vector3d position_in, float radius1, float radius2);
    float intersect(ray ray);
    vector3d getNormal(vector3d p);
    float getRadius1() {return m_radius1;};
    float getRadius2() {return m_radius2;};
  private:
    float m_radius1;
    float m_radius2;
};

#endif
