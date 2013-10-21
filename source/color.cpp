//color.cpp

#include "color.h"

color operator *(float a, color B) {
  color color(0,0,0);
  color.setR(a*B.getR());
  color.setG(a*B.getG());
  color.setB(a*B.getB());
  return color;
}

color operator *(color A, color B) {
  color color(0,0,0);
  color.setR(A.getR()*B.getR());
  color.setG(A.getG()*B.getG());
  color.setB(A.getB()*B.getB());
  return color;
}

color operator +(color A, color B) {
  color color(0,0,0);
  color.setR(A.getR()+B.getR());
  color.setG(A.getG()+B.getG());
  color.setB(A.getB()+B.getB());
  return color;
}

void color::setR(float r) {
  if (r > 1) red = 1;
  else
  if (r < 0)   red = 0;
  else
  red = r;
}

void color::setG(float g) {
  if (g > 1) green = 1;
  else
  if (g < 0)   green = 0;
  else
  green = g;
}

void color::setB(float b) {
  if (b > 1) blue = 1;
  else
  if (b < 0)   blue = 0;
  else
  blue = b;
}

void color::operator+=(color A) {
  setR(getR()+A.getR());
  setG(getG()+A.getG());
  setB(getB()+A.getB());
}
