//primitive.h
//this is basic class for a primitive geometric object

#ifndef _PRIMITIVE_
#define _PRIMITIVE_

#include "vector3d.h"
#include "color.h"
#include "ray.h"
#include "material.h"
#include "matrix.h"

class primitive{
  public:
    primitive();
    primitive(vector3d position_in);
    vector3d getPosition() {return mPosition;};
    material* getMaterial() {return &mMaterial;};
    void setMaterial(material aMaterial) {mMaterial=aMaterial;};
    void translate(float x, float y, float z);
    void rotate(float x, float y, float z);
    void scale(float l, float m, float n);
    virtual float intersect(ray ray) = 0;
    virtual vector3d getNormal(vector3d p) = 0;
    matrix getTranslation(){return mTranslate;};
    matrix getInverseTranslation();
    matrix getRotation(){return mRotate;};
    matrix getInverseRotation();
    matrix getScaling(){return mScaling;};
    matrix getInverseScaling();
    vector3d transformPosition(vector3d p);
    vector3d transformNormal(vector3d d);
    vector3d transformDirection(vector3d d);
    color getColor(vector3d intersecPos);
    
  private:
    vector3d mPosition;
    material mMaterial;
    matrix   mtrafo;
    matrix   mTranslate;
    matrix   mRotate;
    matrix   mScaling;
};

#endif
