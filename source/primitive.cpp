//primitive.cpp

#include "primitive.h"
#include "matrix.h"

primitive::primitive() {
}

primitive::primitive(vector3d position) {
  mPosition  = position;
  mTranslate = matrix::getIdentityMatrix();
  mRotate    = matrix::getIdentityMatrix();
  mScaling   = matrix::getIdentityMatrix();
}

void primitive::translate(float x, float y, float z) {
  mTranslate = (matrix::getTranslationMatrix(x,y,z))*mTranslate;
}

void primitive::rotate(float x, float y, float z) {
  matrix RX = matrix::getRotateXMatrix(x); 
  matrix RY = matrix::getRotateYMatrix(y); 
  matrix RZ = matrix::getRotateZMatrix(z);
  mRotate = RZ*RY*RX*mRotate; 
}

void primitive::scale(float l, float m, float n) {
  mScaling = (matrix::getScalingMatrix(l,m,n)) * mScaling;
}

matrix primitive::getInverseTranslation() {
  matrix inverse = getTranslation();
  inverse.setEntry(0,3,-inverse.getEntry(0,3));
  inverse.setEntry(1,3,-inverse.getEntry(1,3));
  inverse.setEntry(2,3,-inverse.getEntry(2,3));
  return inverse;
}

matrix primitive::getInverseRotation() {
  return getRotation().transpose();
}

matrix primitive::getInverseScaling() {
  matrix inverse = getScaling();
  inverse.setEntry(0,0,1/inverse.getEntry(0,0));
  inverse.setEntry(1,1,1/inverse.getEntry(1,1));
  inverse.setEntry(2,2,1/inverse.getEntry(2,2));
  return inverse;
}

vector3d primitive::transformPosition(vector3d p) {
  vector3d output;
  output = getInverseScaling() * 
           getInverseRotation() *
           getInverseTranslation() * p;
  return output;  
}

vector3d primitive::transformNormal(vector3d d) {
  vector3d output;
  output = getInverseScaling() * getRotation() * d;
  output.Normalize();
  return output;
}

vector3d primitive::transformDirection(vector3d d) {
  vector3d output;
  output = getInverseScaling() * getInverseRotation() * d;
  output.Normalize();
  return output;
}

color primitive::getColor(vector3d intersecPos) {
  vector3d transform;
  color output;
//  transform = getInverseScaling() *
//           getInverseRotation() *
//           getInverseTranslation() * intersecPos;
  output = getMaterial()->getColor(intersecPos);
  return output;
}
