//scene.h

#ifndef _SCENE_
#define _SCENE_

#include "primitive.h"
#include "camera.h"
#include "sphere.h"
#include "light.h"

class scene {
  public:
    scene();
    void initScene();
    camera* getCamera() {return &m_Camera;};
    primitive* getPrimitive(int index) {return m_Primitives[index];};
    light* getLight(int index) {return mLights[index];};
    int getNrOfPrimitives() {return mNrOfPrimitives;};
    void setNrOfPrimitives(int n) {mNrOfPrimitives = n;};
    int getNrOfLights() {return mNrOfLights;};
    void setNrOfLights(int n) {mNrOfLights = n;};
    void addPrimitive();
    void addLight();
    void setTimeStep(int aStep){mTimeStep=aStep;updateClock();};
    int  getTimeStep(){return mTimeStep;};
    void setStartFrame(int start){mStartFrame=start;};
    void setEndFrame(int end){mEndFrame=end;};
  private:
    void updateClock();
    primitive** m_Primitives;
    light** mLights;
    int mNrOfPrimitives;
    int mNrOfLights;
    camera m_Camera;
    float clock;
    int mTimeStep,mStartFrame,mEndFrame;
};

#endif
