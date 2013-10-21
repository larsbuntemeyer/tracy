//material.cpp

#include "material.h"
#include <iostream>

material::material() {
	mColor = color(1,1,1);
	mKDiffuse = 1.0f;
	mKSpecular = 0.0f;
	mKAmbient = 0.0f;
        mReflect = 0.0f;
        mRefract = 0.0f;
        mRefrIndex = 1.0f;
        mTexture = NULL;//new texture();
}

material::material(color aColor) {
	mColor = aColor;
	mKDiffuse = 1.0f;
	mKSpecular = 0.0f;
	mKAmbient = 0.0f;
        mReflect = 0.0f;
        mRefract = 0.0f;
        mRefrIndex = 1.0f;
        mTexture = NULL;//new texture();
}

color material::getColor(vector3d intersecPos) {
  color output = mColor;
  if (mTexture != NULL) output = mTexture->getColor(intersecPos);
  return output;
}
