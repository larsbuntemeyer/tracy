//matrix.cpp

#include <iostream>
#include <cmath>
#include "matrix.h"
#include "const.h"

using namespace std;

matrix::matrix() {
  
  setNumRows(4);
  setNumCols(4);

  mMatrix[0][0] = 0; mMatrix[0][1] = 0; mMatrix[0][2] = 0; mMatrix[0][3] = 0;  
  mMatrix[1][0] = 0; mMatrix[1][1] = 0; mMatrix[1][2] = 0; mMatrix[1][3] = 0;  
  mMatrix[2][0] = 0; mMatrix[2][1] = 0; mMatrix[2][2] = 0; mMatrix[2][3] = 0;  
  mMatrix[3][0] = 0; mMatrix[3][1] = 0; mMatrix[3][2] = 0; mMatrix[3][3] = 0;  

}

matrix::matrix(int numRows, int numCols) {
  
  setNumRows(numRows);
  setNumCols(numCols);

  mMatrix[0][0] = 0; mMatrix[0][1] = 0; mMatrix[0][2] = 0; mMatrix[0][3] = 0;  
  mMatrix[1][0] = 0; mMatrix[1][1] = 0; mMatrix[1][2] = 0; mMatrix[1][3] = 0;  
  mMatrix[2][0] = 0; mMatrix[2][1] = 0; mMatrix[2][2] = 0; mMatrix[2][3] = 0;  
  mMatrix[3][0] = 0; mMatrix[3][1] = 0; mMatrix[3][2] = 0; mMatrix[3][3] = 0;  

}

matrix::matrix(int numRows, int numCols,
               float a00, float a01, float a02, float a03,
               float a10, float a11, float a12, float a13,
               float a20, float a21, float a22, float a23,
               float a30, float a31, float a32, float a33) {

  setNumRows(numRows);
  setNumCols(numCols);

  mMatrix[0][0] = a00; mMatrix[0][1] = a01; mMatrix[0][2] = a02; mMatrix[0][3] = a03;  
  mMatrix[1][0] = a10; mMatrix[1][1] = a11; mMatrix[1][2] = a12; mMatrix[1][3] = a13;  
  mMatrix[2][0] = a20; mMatrix[2][1] = a21; mMatrix[2][2] = a22; mMatrix[2][3] = a23;  
  mMatrix[3][0] = a30; mMatrix[3][1] = a31; mMatrix[3][2] = a32; mMatrix[3][3] = a33;  

}

vector3d matrix::operator * (vector3d x) {
  vector3d y(0,0,0);

  y.x = mMatrix[0][0]*x.x+mMatrix[0][1]*x.y+mMatrix[0][2]*x.z+mMatrix[0][3];
  y.y = mMatrix[1][0]*x.x+mMatrix[1][1]*x.y+mMatrix[1][2]*x.z+mMatrix[1][3];
  y.z = mMatrix[2][0]*x.x+mMatrix[2][1]*x.y+mMatrix[2][2]*x.z+mMatrix[2][3];

  return y;
};

matrix matrix::operator * (matrix B) {
  matrix product(4,4);
  for (int i=0; i<4; i++)
    for (int j=0; j<4; j++)
    {
      for (int k=0; k<4; k++)
      {
        float add = getEntry(j,k) * B.getEntry(k,i);
        product.setEntry(j,i,product.getEntry(j,i)+add); 
      }
    }  
  return product;
};

matrix matrix::getTranslationMatrix(float x, float y, float z) {
  matrix translation(4,4,
                     1.0f, 0.0f, 0.0f,   x,
                     0.0f, 1.0f, 0.0f,   y,
                     0.0f, 0.0f, 1.0f,   z,
                     0.0f, 0.0f, 0.0f, 1.0f);
  return translation;
}

matrix matrix::getRotateXMatrix(float alpha) {
  float cosAlpha = cos(alpha/180*PI);
  float sinAlpha = sin(alpha/180*PI);
  if (cosAlpha < 1.e-10) cosAlpha=0;
  if (sinAlpha < 1.e-10) sinAlpha=0;
  matrix rotateX(4,4,
                 1.0f,    0.0f,     0.0f, 0.0f,
                 0.0f,cosAlpha,-sinAlpha, 0.0f,
                 0.0f,sinAlpha, cosAlpha, 0.0f,
                 0.0f,    0.0f,     0.0f, 1.0f);
  return rotateX;
}

matrix matrix::getRotateYMatrix(float alpha) {
  float cosAlpha = cos(alpha/180*PI);
  float sinAlpha = sin(alpha/180*PI);
  if (cosAlpha < 1.e-10) cosAlpha=0;
  if (sinAlpha < 1.e-10) sinAlpha=0;
  matrix rotateY(4,4,
                 cosAlpha,  0.0f, sinAlpha, 0.0f,
                 0.0f,      1.0f,     0.0f, 0.0f,
                 -sinAlpha, 0.0f, cosAlpha, 0.0f,
                 0.0f,      0.0f,     0.0f, 1.0f);
  return rotateY;
}

matrix matrix::getRotateZMatrix(float alpha) {
  float cosAlpha = cos(alpha/180*PI);
  float sinAlpha = sin(alpha/180*PI);
  if (cosAlpha < 1.e-10) cosAlpha=0;
  if (sinAlpha < 1.e-10) sinAlpha=0;
  matrix rotateZ(4,4,
                 cosAlpha,-sinAlpha, 0.0f, 0.0f,
                 sinAlpha, cosAlpha, 0.0f, 0.0f,
                     0.0f,     0.0f, 1.0f, 0.0f, 
                     0.0f,     0.0f, 0.0f, 1.0f);
  return rotateZ;
}

matrix matrix::getScalingMatrix(float l, float m, float n) {
  matrix rotateZ(4,4,
                    l, 0.0f, 0.0f, 0.0f,
                 0.0f,    m, 0.0f, 0.0f,
                 0.0f, 0.0f,    n, 0.0f,
                 0.0f, 0.0f, 0.0f, 1.0f);
  return rotateZ;
}

matrix matrix::getIdentityMatrix() {
  matrix identity(4,4,
                  1,0,0,0,
                  0,1,0,0,
                  0,0,1,0,
                  0,0,0,1);
  return identity;
}

matrix matrix::transpose() {
  matrix transpose(getNumRows(),getNumCols());
  for (int i=0;i<getNumRows();i++)
    for (int j=0;j<getNumCols();j++)
      transpose.setEntry(i,j,getEntry(j,i));
  return transpose;
}

void matrix::print(string name) {
  cout << "matrix " << name << " : " << endl;
  for (int i=0; i<getNumRows(); i++)
   for (int j=0; j<getNumCols(); j++)
   { 
     if ((j!=0) && j%(getNumCols()-1)==0)
       cout << getEntry(i,j) << endl;
     else cout << getEntry(i,j) << " ";
   }
}
