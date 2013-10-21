//color.h

#ifndef _COLOR_
#define _COLOR_

#include "vector3d.h"

class color{
  public:
    color(){red = 0; green = 0; blue = 0;};
    color(float r, float g, float b) {setR(r); setG(g); setB(b);};
    float getR() {return red;};
    float getG() {return green;};
    float getB() {return blue;};
    void setR(float r);
    void setG(float g);
    void setB(float b);
    void setRGB(float r, float g, float b) {setR(r);setG(g);setB(b);};
    friend color operator * (float a, color B);
    friend color operator * (color A, color B);
    friend color operator + (color A, color B);
    void operator+=(color A);
  private:
    float red,green,blue;
};

#endif
