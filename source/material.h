//material.h

#ifndef _MATERIAL_
#define _MATERIAL_

#include "color.h"
#include "material.h"
#include "vector3d.h"
#include "texture.h"

class material {

  public:
    material();
    material(color aColor);
    color getColor(){return mColor;};
    color getColor(vector3d intersecPos);
    float getSpecular(){return mKSpecular;};
    float getDiffuse(){return mKDiffuse;};
    float getAmbient(){return mKAmbient;};
    float getReflect(){return mReflect;};
    float getRefract(){return mRefract;};
    float getRefrIndex(){return mRefrIndex;};
    texture* getTexture() {return mTexture;};
    void setColor(color aColor){mColor=aColor;};
    void setDiffuse(float aKDiff){mKDiffuse=aKDiff;};
    void setSpecular(float aKSpec){mKSpecular=aKSpec;};
    void setAmbient(float aKAmb){mKAmbient=aKAmb;};
    void setReflect(float aReflect){mReflect=aReflect;};
    void setRefract(float aRefract){mRefract=aRefract;};
    void setRefrIndex(float aRefrIndex){mRefrIndex = aRefrIndex;};
    void setTexture() {mTexture = new texture();};

  private:
    color mColor;
    float mKDiffuse,mKSpecular,mKAmbient;
    float mReflect,mRefract;
    float mRefrIndex;
    texture* mTexture;
    
};

#endif
