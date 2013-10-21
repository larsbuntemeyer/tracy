//texture.cpp

#include "texture.h"
#include <cmath>

using namespace std;

texture::texture() {
  mColor1.setRGB(1,1,1);
  mColor2.setRGB(0,0,0);
  mWidth = 6.0f;
} 

color texture::getColor(vector3d intersecPos) {
  color output(0,0,0);
  float w = mWidth;
  float x = sin(w*intersecPos.getX());
  float y = cos(w*intersecPos.getZ());
  int n = int(intersecPos.getX()/getWidth());
  int m = int(intersecPos.getZ()/getWidth());
  if ((x+y) > 0) output = mColor2;
  else output = mColor1;
  //output = (x + y) * mColor2;
  return output;
}
/*
int texture::mod(float a, int b) {
  return (abs(a)-(int(abs(a)/b))*b);
}*/
