//frame.cpp

#include <iostream>
#include "frame.h"

using namespace std;

frame::frame() {
  m_width = 720;
  m_height = 576;
  m_position.setCoordinates(0,0,0);
  float aspect = float(m_width)/float(m_height);
  mLeftUp.setCoordinates(-aspect/2,0.5,1.0);
  mRightUp.setCoordinates(aspect/2,0.5,1.0);
  mLeftDown.setCoordinates(-aspect/2,-0.5,1.0);
  mRightDown.setCoordinates(aspect/2,-0.5,1.0);
}

frame::frame(vector3d position, int width, int height) {
  m_width = width;
  m_height = height;
  m_position = position;
  float aspect = float(m_width)/float(m_height);
  mLeftUp.setCoordinates(-aspect/2,0.5,1.0);
  mRightUp.setCoordinates(aspect/2,0.5,1.0);
  mLeftDown.setCoordinates(-aspect/2,-0.5,1.0);
  mRightDown.setCoordinates(aspect/2,-0.5,1.0);
  translate(position.getX(),position.getY(),position.getZ());
}

vector3d frame::getUnitVecX() {
  ex = mRightUp - mLeftUp;
  return ex;
}

vector3d frame::getUnitVecY() {
  ey = mLeftDown - mLeftUp;
  return ey;
}

void frame::setPosition(vector3d position) {
  m_position = position;
}

void frame::updateFrameCoordinates() {
  float aspect = float(m_width)/float(m_height);
  vector3d x = ex;//getUnitVecX();
  vector3d xn = x;
  xn.Normalize();
  mLeftUp = mLeftUp + 0.5*x - aspect/2 * xn;//.Normalize(); 
  mRightUp = mRightUp - 0.5*x + aspect/2 * xn;//.Normalize(); 
  mLeftDown = mLeftDown + 0.5*x - aspect/2 * xn;//.Normalize();
  mRightDown = mRightDown - 0.5*x + aspect/2 * xn;//.Normalize();
  ex = mRightUp - mLeftUp;
  ey = mLeftDown - mLeftUp;
}

void frame::translate(float x, float y, float z) {
  locator::translate(x,y,z);
  matrix t = matrix::getTranslationMatrix(x,y,z);
  mLeftUp =  t * mLeftUp;
  mRightUp = t * mRightUp;
  mLeftDown = t * mLeftDown;
  mRightDown = t * mRightDown; 
}

void frame::rotate(float x, float y, float z) {
  mLeftUp = transformPosition(mLeftUp);
  mRightUp = transformPosition(mRightUp);
  mLeftDown = transformPosition(mLeftDown);
  mRightDown = transformPosition(mRightDown);
  locator::rotate(x,y,z);
  matrix tr = getTranslation() * getRotation();
  mLeftUp =  tr * mLeftUp;
  mRightUp = tr * mRightUp;
  mLeftDown = tr * mLeftDown;
  mRightDown = tr * mRightDown; 
}
