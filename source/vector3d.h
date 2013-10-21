//vector3d.h

#ifndef _VECTOR3D_
#define _VECTOR3D_

#include <iostream>

class vector3d	{
  public:
    vector3d(void);
    vector3d(float x_in, float y_in, float z_in);
    ~vector3d();
    float getLength();
    void Normalize();
    static float Dot(vector3d x, vector3d y);
    vector3d getNormalVector();

    float getX(){return x;};
    float getY(){return y;};
    float getZ(){return z;};

    float Dot(vector3d a);
    void setCoordinates(float x_in, float y_in, float z_in);
    void print(std::string name); 

    void operator+=(vector3d A);
    void operator-=(vector3d A);
    void operator*=(float a);

    friend vector3d operator + (vector3d A, vector3d B);
    friend vector3d operator - (vector3d A, vector3d B);
    friend float operator * (vector3d A, vector3d B);
    friend vector3d operator * (float a, vector3d B);

    float x,y,z;

  private:

};

#endif
