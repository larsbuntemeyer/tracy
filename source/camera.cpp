//camera.cpp

#include "camera.h"

using namespace std;

camera::camera() {
  cout << "creating camera...\n";
  position.setCoordinates(0.0f,0.0f,0.0f);
  translate(0.0f,2.0f,-5.0f);
    rotate(0.0,0.0,0.0);
  direction.setCoordinates(0.0f,0.0f,1.0f);
  direction.Normalize();
  angle = 0.0f;
  mFrame.setPosition(position + 1.0f * direction);
  
}

camera::camera(vector3d position_in, vector3d direction_in,
			   int angle_in) {
  position.setCoordinates(0.0f,0.0f,0.0f);
  translate(position_in.getX(),position_in.getY(),position_in.getZ());
  direction_in.Normalize();
  angle = angle_in;
  mFrame.setPosition(position + 1.0f * direction_in);
}

ray camera::getShootRay(float x, float y)
{
  ray ray;
  int resX = mFrame.getWidth();
  int resY = mFrame.getHeight();
  vector3d ex = mFrame.getUnitVecX();
  vector3d ey = mFrame.getUnitVecY();

  ray.setOrigin(position);
  vector3d pixelPosition;
  pixelPosition = mFrame.getLeftUp()  + 
                  ((float)x/resX) * 1 * ex +
                  ((float)y/resY) * 1 * ey;
  vector3d dir = pixelPosition - position;
  dir.Normalize();
  ray.setDirection(dir);
  return ray;
}

void camera::setWidth(int width) {
  mFrame.setWidth(width);
}

void camera::setHeight(int height) {
  mFrame.setHeight(height);
}

void camera::translate(float x, float y, float z) {
  locator::translate(x,y,z);  
  position = position + vector3d(x,y,z);
  position.print("camera position");
  mFrame.translate(x,y,z);
}

void camera::rotate(float x, float y, float z) {
  locator::rotate(x,y,z);
  mFrame.rotate(x,y,z); 
}
