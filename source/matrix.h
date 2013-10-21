//matrix.h

#ifndef _MATRIX_
#define _MATRIX_

#include <vector>
#include <iostream>
#include "vector3d.h"


class matrix {
  public:
    matrix();
    matrix(int numRows, int numCols);
    matrix(int numRows, int numCols,
           float a00, float a01, float a02, float a03,
           float a10, float a11, float a12, float a13,
           float a20, float a21, float a22, float a23,
           float a30, float a31, float a32, float a33);

    static matrix getIdentityMatrix();
    static matrix getTranslationMatrix(float x, float y, float z);
    static matrix getRotateXMatrix(float angle);
    static matrix getRotateYMatrix(float angle);
    static matrix getRotateZMatrix(float angle);
    static matrix getScalingMatrix(float l, float m, float n);
   
    vector3d operator * (vector3d x);
    matrix operator * (matrix B); 
   
    void print(std::string name);

    int getNumRows(){return numRows;};
    int getNumCols(){return numCols;};
    
    matrix transpose();
    float getEntry(int i, int j) {return mMatrix[i][j];};
    float setEntry(int i, int j, float a) {mMatrix[i][j] = a;};
    void setNumRows(int nr){numRows = nr;};
    void setNumCols(int nc){numCols = nc;};

  private:
    int numRows,numCols;
    float mMatrix[4][4];

};



#endif
