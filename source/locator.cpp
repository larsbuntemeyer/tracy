//locator.cpp

#include "locator.h"
#include "matrix.h"

locator::locator() {
  mPosition.setCoordinates(0.0,0.0,0.0);
  mTranslate = matrix::getIdentityMatrix();
  mRotate    = matrix::getIdentityMatrix();
  mScaling   = matrix::getIdentityMatrix();
}

locator::locator(vector3d position) {
  mPosition  = position;
  mTranslate = matrix::getIdentityMatrix();
  mRotate    = matrix::getIdentityMatrix();
  mScaling   = matrix::getIdentityMatrix();
}

void locator::translate(float x, float y, float z) {
  mTranslate = (matrix::getTranslationMatrix(x,y,z))*mTranslate;
  setPosition(getPosition()+vector3d(x,y,z));
}

void locator::rotate(float x, float y, float z) {
  matrix RX = matrix::getRotateXMatrix(x); 
  matrix RY = matrix::getRotateYMatrix(y); 
  matrix RZ = matrix::getRotateZMatrix(z);
  mRotate = RZ*RY*RX*mRotate; 
}

void locator::scale(float l, float m, float n) {
  mScaling = (matrix::getScalingMatrix(l,m,n)) * mScaling;
}

matrix locator::getInverseTranslation() {
  matrix inverse = getTranslation();
  inverse.setEntry(0,3,-inverse.getEntry(0,3));
  inverse.setEntry(1,3,-inverse.getEntry(1,3));
  inverse.setEntry(2,3,-inverse.getEntry(2,3));
  return inverse;
}

matrix locator::getInverseRotation() {
  return getRotation().transpose();
}

matrix locator::getInverseScaling() {
  matrix inverse = getScaling();
  inverse.setEntry(0,0,1/inverse.getEntry(0,0));
  inverse.setEntry(1,1,1/inverse.getEntry(1,1));
  inverse.setEntry(2,2,1/inverse.getEntry(2,2));
  return inverse;
}

vector3d locator::transformPosition(vector3d p) {
  vector3d output;
  output = getInverseScaling() * 
           getInverseRotation() *
           getInverseTranslation() * p;
  return output;  
}

vector3d locator::transformNormal(vector3d d) {
  vector3d output;
  output = getInverseScaling() * getRotation() * d;
  output.Normalize();
  return output;
}

vector3d locator::transformDirection(vector3d d) {
  vector3d output;
  output = getInverseScaling() * getInverseRotation() * d;
  output.Normalize();
  return output;
}
