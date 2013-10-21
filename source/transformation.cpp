//transformation.cpp

#include "transformation.h"
#include "matrix.h"

//constructor
transformation::transformation() {
  m_trafoMatrix = matrix::getIdentityMatrix();
  numTrafo = 0;
}

void transformation::addTrafo(matrix trafo) {
  m_trafoMatrix = trafo * m_trafoMatrix;
  numTrafo++;
  trafos[numTrafo] = &trafo;
}
