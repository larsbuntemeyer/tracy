//hyperboloid.h

#ifndef _HYPERBOLOID_
#define _HYPERBOLOID_

#include "vector3d.h"
#include "primitive.h"

class hyperboloid : public primitive {
  public:
    hyperboloid();
    hyperboloid(vector3d position_in, float radius, float height,
                float alpha, float beta, float gamma);
    float intersect(ray ray);
    vector3d getNormal(vector3d p);
    float getRadius() {return m_radius;};
  private:
    float m_radius;
    float mAlpha,mBeta,mGamma;
    float mHeight;
};

#endif
