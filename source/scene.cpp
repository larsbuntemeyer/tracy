//scene.cpp

#include "cube.h"
#include "scene.h"
#include "sphere.h"
#include "torus.h"
#include "plane.h"
#include "primitive.h"
#include "hyperboloid.h"
#include "cylinder.h"
#include "light.h"
#include "implicit.h"
#include <iostream>
#include <cmath>

using namespace std;

scene::scene() {
        mTimeStep = 0;
        mStartFrame = 0;
        mEndFrame = 100;
	m_Primitives = new primitive*[100];
	mLights = new light*[100];
//geometry	
	m_Primitives[0] = new plane(vector3d(0,0,0),vector3d(0,1,0),100,100);
	m_Primitives[0]->getMaterial()->setColor(color(1.0f,1.0f,0.0f));
	m_Primitives[0]->getMaterial()->setDiffuse(1.0f);
	m_Primitives[0]->getMaterial()->setSpecular(0.2f);
	m_Primitives[0]->getMaterial()->setReflect(0.2f);
        m_Primitives[0]->translate(0,-1.0f,0);
        m_Primitives[0]->rotate(0,0,0);
        m_Primitives[0]->scale(1,1,1);
        m_Primitives[0]->getMaterial()->setTexture();

//	m_Primitives[1] = new torus(vector3d(0.0f,1.0f,0.0f),1.0f,2.0f);
//	m_Primitives[1]->getMaterial()->setColor(color(0.0f,0.0f,1.0f));
//	m_Primitives[1]->getMaterial()->setDiffuse(1.0f);
//	m_Primitives[1]->getMaterial()->setSpecular(0.0f);
//	m_Primitives[1]->getMaterial()->setReflect(0.0f);
//        m_Primitives[1]->translate(0,0,0);
//        m_Primitives[1]->rotate(0,0,0);
//        m_Primitives[1]->scale(1,1,1);

//	m_Primitives[1] = new sphere(vector3d(0.0f,1.0f,0.0f),1.0f);
//	m_Primitives[1]->getMaterial()->setColor(color(1.0f,1.0f,0.0f));
//	m_Primitives[1]->getMaterial()->setDiffuse(1.0f);
//	m_Primitives[1]->getMaterial()->setSpecular(0.6f);
//	m_Primitives[1]->getMaterial()->setReflect(0.2f);
//        m_Primitives[1]->translate(0,0,0);
//        m_Primitives[1]->rotate(0,0,0);
//        m_Primitives[1]->scale(1,1,1);

//	m_Primitives[1] = new cylinder(vector3d(0.0f,0.0f,0.0f),0.75f,2.0f);
//	m_Primitives[1]->getMaterial()->setColor(color(0.0f,0.0f,1.0f));
//	m_Primitives[1]->getMaterial()->setDiffuse(1.0f);
//	m_Primitives[1]->getMaterial()->setSpecular(0.6f);
//	m_Primitives[1]->getMaterial()->setReflect(0.2f);
//        m_Primitives[1]->translate(0,1.0f,0);
//        m_Primitives[1]->rotate(70.0f,0.0f,0.0f);
//        m_Primitives[1]->rotate(0.0f,30.0f,0.0f);
////        m_Primitives[1]->rotate(0,45.0f,0.0f);
//        m_Primitives[1]->scale(1.0f,1.0f,
    m_Primitives[1] = new implicit(vector3d(0.0f,0.0f,0.0f));
    m_Primitives[1]->getMaterial()->setColor(color(0.0f,0.0f,1.0f));
    m_Primitives[1]->getMaterial()->setDiffuse(1.0f);
    m_Primitives[1]->getMaterial()->setSpecular(1.0f);
    m_Primitives[1]->getMaterial()->setReflect(0.0f);
////
	setNrOfPrimitives(2);

//lights
	mLights[0] = new light(vector3d(3.0f,10.0f,-10.0f), color(1.0f,1.0f,1.0f), 0.5f);
        mLights[1] = new light(vector3d(-3.0f,4.0f,-20.0f), color(1.0f,1.0f,1.0f), 0.5f);

        setNrOfLights(2);

}


void scene::initScene() {
	m_Primitives = new primitive*[100];

//green
	m_Primitives[3] = new sphere(vector3d(-8,2,0),1);
	m_Primitives[3]->getMaterial()->setColor(color(0.0f,1.0f,0.0f));
	m_Primitives[3]->getMaterial()->setDiffuse(1.0f);
	m_Primitives[3]->getMaterial()->setSpecular(0.0f);
	m_Primitives[3]->getMaterial()->setReflect(0.0f);
	m_Primitives[3]->translate(-8,2,0);
//red
	m_Primitives[2] = new sphere(vector3d(5.0,1.0,-3.0),1.4+0.3*sin(clock*10*3.14159));
	m_Primitives[2]->getMaterial()->setColor(color(1.0f,0.0f,0.0f));
	m_Primitives[2]->getMaterial()->setDiffuse(0.7f);
	m_Primitives[2]->getMaterial()->setSpecular(0.4f);
	m_Primitives[2]->getMaterial()->setReflect(0.2f);
        m_Primitives[2]->getMaterial()->setRefract(0.0f);
        m_Primitives[2]->getMaterial()->setRefrIndex(1.33f);
	m_Primitives[2]->translate(5.0,1.0,-3.0);
//white
	m_Primitives[0] = new sphere(vector3d(1.0,sin(clock*16*3.14159),0), 1.0);
	m_Primitives[0]->getMaterial()->setColor(color(1.0f,1.0f,1.0f));
	m_Primitives[0]->getMaterial()->setDiffuse(0.7f);
	m_Primitives[0]->getMaterial()->setSpecular(0.2f);
	m_Primitives[0]->getMaterial()->setReflect(0.1f);
	m_Primitives[0]->translate(0.0,0.0,0.0);

//plane	
	m_Primitives[1] = new plane(vector3d(0,0,0),vector3d(0,1,0),100,100);
	m_Primitives[1]->getMaterial()->setColor(color(1.0f,1.0f,0.0f));
	m_Primitives[1]->getMaterial()->setDiffuse(1.0f);
	m_Primitives[1]->getMaterial()->setSpecular(0.0f);
	m_Primitives[1]->getMaterial()->setReflect(0.0f);
        m_Primitives[1]->translate(0,-2,0);
        m_Primitives[1]->rotate(0,0,0);
        m_Primitives[1]->scale(1,1,1);
        m_Primitives[1]->getMaterial()->setTexture();

//glass
        sphere* pinkSphere = new sphere(vector3d(-4.0f,1.0f,-4.0f),1.0f);
	m_Primitives[4] = pinkSphere;
	m_Primitives[4]->getMaterial()->setColor(color(0.0f,0.0f,0.0f));
	m_Primitives[4]->getMaterial()->setDiffuse(0.2f);
	m_Primitives[4]->getMaterial()->setSpecular(0.6f);
	m_Primitives[4]->getMaterial()->setReflect(0.0f);
	m_Primitives[4]->getMaterial()->setRefract(0.6f);
	m_Primitives[4]->getMaterial()->setRefrIndex(1.4f);
	m_Primitives[4]->translate(-6.0,1.0,-6.0);

//hyperboloid
        m_Primitives[5] = new hyperboloid(vector3d(-2.0,0.0,0.0),0.5f,2, 1,1,1);
	m_Primitives[5]->getMaterial()->setColor(color(0.0f,1.0f,1.0f));
	m_Primitives[5]->getMaterial()->setDiffuse(0.6f);
	m_Primitives[5]->getMaterial()->setSpecular(0.4f);
	m_Primitives[5]->getMaterial()->setReflect(0.2f);
	m_Primitives[5]->getMaterial()->setRefract(0.0f);
	m_Primitives[5]->getMaterial()->setRefrIndex(1.3f);
	m_Primitives[5]->translate(-2.0,0.0,0.0);

//yellow 
        sphere* newSphere = new sphere(vector3d(3.5,4.0,3.0),1.3);
	m_Primitives[6] = newSphere;
	m_Primitives[6]->getMaterial()->setColor(color(1.0f,1.0f,0.0f));
	m_Primitives[6]->getMaterial()->setDiffuse(0.8f);
	m_Primitives[6]->getMaterial()->setSpecular(0.3f);
	m_Primitives[6]->getMaterial()->setReflect(0.1);
        m_Primitives[6]->getMaterial()->setRefract(0.0f);
        m_Primitives[6]->getMaterial()->setRefrIndex(1.3f);
	m_Primitives[6]->translate(3.5,4.0,3.0);

        m_Camera = camera();        
        float camClock = clock*2*3.14159;
        float x = -13*sin(camClock);
        float y = 3+sin(clock*2*3.14159)*2.0;
        float z = -13*cos(camClock);
        float r = sqrt(x*x+z*z);
        float d = sqrt(x*x+y*y+z*z);
        float alpha = 90-180*asin(r/d)/3.14159;
        vector3d(x,y,z).print("x,y,z");
        cout << "alpha: " << alpha << endl;

        getCamera()->translate(x,y,z);
        getCamera()->rotate(alpha,clock*360,0.0);
	setNrOfPrimitives(7);

	mLights = new light*[100];
	mLights[0] = new light(vector3d(3.0f,8.0f,-10.0f), color(1.0f,1.0f,1.0f), 0.5f);
        mLights[1] = new light(vector3d(-3.0f,6.0f,-20.0f), color(1.0f,1.0f,1.0f), 0.5f);
	
        setNrOfLights(2);
}

void scene::updateClock() {
  clock = float(mTimeStep)/float(mEndFrame-mStartFrame);
  cout << "clock: " << clock << "\n";
}
