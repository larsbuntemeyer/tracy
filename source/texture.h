//texture.h

#ifndef _TEXTURE_ 
#define _TEXTURE_

#include <iostream>
#include "vector3d.h"
#include "color.h"


class texture {
  public:
    texture();
    color getColor(vector3d intersecPos);
    float getWidth(){return mWidth;};
//    int mod(float a, int b); 
  private:
    //type{FILE,PROCEDURAL}
    color mColor1;
    color mColor2;
    float mWidth;
};



#endif
