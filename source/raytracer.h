//raytracer.h

#ifndef _RAYTRACER_
#define _RAYTRACER_

#include "vector3d.h"
#include "scene.h"

class raytracer {

  public:
    raytracer();
    raytracer(scene* scene, int resX, int resY);
    scene* getScene() {return m_scene;};
    color  renderPixel(int x, int y);
    int    getResX() {return m_resX;};
    int    getResY() {return m_resY;};
    void   renderScene();
    void   setScene(scene* aScene) {m_scene=aScene;};
    void   setAmbience(float aAmbience) {ambience=aAmbience;};
    void   setEnvironmentColor(color aColor) {environmentColor=aColor;};
    void   setTraceDepth(int aTraceDepth) {traceDepth=aTraceDepth;};
    void   setGlobalRefrIndex(float aGlobalRefrIndex) {globalRefrIndex=aGlobalRefrIndex;};
    void   setAmbientColor(color aColor) {ambientColor=aColor;};
    void   setAntiAlias(int n) {mAntiAlias = n;};

  private:
    //member variables
    scene* m_scene;
    int mAntiAlias; //the order of the Anti-Alias calculation
    int m_resX, m_resY, traceDepth;
    float t;  //for the ray parameterization
    float ambience;
    color environmentColor,ambientColor;
    float globalRefrIndex;

    //member methods		
    color raytrace(ray shootRay, int traceDepth);
    color getColorAtIntersecPos(primitive* hitObject, vector3d intersecPos, 
                                ray shootRay, light* actLight);
    primitive* getNearestObjectInRay(ray shootRay);
    

};

#endif
