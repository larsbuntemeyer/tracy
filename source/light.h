//light.h

#ifndef _LIGHT_
#define _LIGHT_

#include "vector3d.h"
#include "color.h"

class light {
  public:
    light();
    light(vector3d position, color c, float intensity);
    void setColor(color c){mColor=c;};
    void setPosition(vector3d p){mPosition=p;};
    color getColor(){return mColor;};
    vector3d getPosition(){return mPosition;};
    float getIntensity(vector3d position);
  private:
    vector3d mPosition;
    color mColor;
    float mIntensity;
};

#endif
