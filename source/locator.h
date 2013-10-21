//locator.h

#ifndef _LOCATOR_
#define _LOCATOR_

#include "vector3d.h"
#include "matrix.h"

class locator{

  public:
    locator();
    locator(vector3d position_in);
    vector3d getPosition() {return mPosition;};
    vector3d setPosition(vector3d aPosition) {mPosition=aPosition;};
    void translate(float x, float y, float z);
    void rotate(float x, float y, float z);
    void scale(float l, float m, float n);
    matrix getTranslation(){return mTranslate;};
    matrix getInverseTranslation();
    matrix getRotation(){return mRotate;};
    matrix getInverseRotation();
    matrix getScaling(){return mScaling;};
    matrix getInverseScaling();
    vector3d transformPosition(vector3d p);
    vector3d transformNormal(vector3d d);
    vector3d transformDirection(vector3d d);
    
  private:
    vector3d mPosition;
    matrix   mtrafo;
    matrix   mTranslate;
    matrix   mRotate;
    matrix   mScaling;
};

#endif
