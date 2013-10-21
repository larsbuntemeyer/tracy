//transformation.h

#ifndef _TRANSFORMATION_
#define _TRANSFORMATION_

#include "matrix.h"


class transformation {
  public:
    transformation();
    matrix getTrafoMatrix() {return m_trafoMatrix;};
    void addTrafo(matrix trafo);
    matrix getInversTrafoMatrix();

  private:
    matrix m_trafoMatrix;
    matrix m_inversTrafoMatrix;
    matrix *trafos[100];
    int numTrafo; 
};


#endif
