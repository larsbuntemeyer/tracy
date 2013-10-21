//light.cpp

#include "vector3d.h"
#include "light.h"

light::light() {
  mPosition = vector3d(0,0,0);
  mColor = color(1.0f,1.0f,1.0f);
  mIntensity = 1.0;
}

light::light(vector3d position, color c, float intensity) {
  mPosition = position;
  mColor = c;
  mIntensity = intensity;
}

float light::getIntensity(vector3d position) {
  //vector3d d = position - mPosition;
  return mIntensity;
}
