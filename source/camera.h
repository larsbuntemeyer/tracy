//camera.h

#ifndef _CAMERA_
#define _CAMERA_

#include "vector3d.h"
#include "frame.h"
#include "ray.h"
#include "matrix.h"
#include "locator.h"

class camera : public locator{
  public:
    camera();
    camera(vector3d position_in, vector3d direction_in, int angle_in);
    vector3d getPosition() {return position;};
    vector3d getDirection() {return direction;};
    frame* getFrame() {return &mFrame;};
    int getAngle() {return angle;};
    ray getShootRay(float x, float y);
    void setWidth(int width);
    void setHeight(int height);
    void translate(float x, float y, float z);
    void rotate(float x, float y, float z);
    void setPosition(vector3d aPosition) {position = aPosition;};

  private:
    vector3d position;
    vector3d direction;
    int angle;
    frame mFrame;
};

#endif
