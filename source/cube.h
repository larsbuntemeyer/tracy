//cube.h

#ifndef _CUBE_
#define _CUBE

#include "vector3d.h"
#include "primitive.h"
#include "plane.h"

class cube : public primitive {

  public:
    cube();
    cube(vector3d position_in);
    float intersect(ray ray);
    vector3d getNormal(vector3d p);
    void setMaterial(material aMaterial);
    void translate(float x, float y, float z);
    void rotate(float x, float y, float z);
    void scale(float l, float m, float n);
  private:
    void updateFacesMaterial();
    plane** mFaces;
    int hitFaceIndex;

};

#endif
