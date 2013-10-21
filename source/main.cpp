// main.cpp 

//system classes
#include <iostream>  
#include <fstream>
#include <cstring>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <stdexcept>

//raytracer classes
#include "const.h"
#include "frame.h"
#include "camera.h"
#include "scene.h"
#include "raytracer.h"
#include "matrix.h"
#include "transformation.h"

//grafic interfaces
#include "CImg.h"
#include "quickcg.h"

#define resX 720 
#define resY 576
#define traceDepth 3 
#define antiAlias 0
#define startFrame 0
#define endFrame 1000
#define SubStartFrame 0
#define SubEndFrame 0
#define filename "test"
#define suffix ".png"

using namespace std;

//global procedures
void testAlgebra();
void testTrigonometry();
void renderSeq();
void view();
void testRender();
string stringify(double x);


int main(int /*argc*/, char */*argv*/[])
{
  cout << "          ==========================================================================\n";
  cout << "          =                   __________  ___   ________  __                       =\n";
  cout << "          =                  /_  __/ __ \\/   | / ____/\\ \\/ /                       =\n";
  cout << "      ____=__________________ /_/_/_/_/_/_/|_|/_/______\\__/________________________=________\\ \n";
  cout << "          =                  / / / _, _/ ___ / /___    / /                         =        /\n";
  cout << "          =                 /_/ /_/ |_/_/  |_\\____/   /_/                          =\n"; 
  cout << "          =                                                   a simple raytracer   =\n";
  cout << "          ==========================================================================\n";


  //test
  //testAlgebra();

  //test
  //testTrigonometry();

  //start render
  //renderSeq();
  testRender();
  return 0;
}

void testRender() {
  using namespace cimg_library;

  cout << "create image...\n";
  CImg<unsigned char>MyImage(resX,resY,1,3,0);
  unsigned width = MyImage.dimx();  // access image width
  unsigned height = MyImage.dimy(); // access image height

  //create the scene
  cout << "creating scene...\n";
  scene testScene;
//  testScene.initScene();
  testScene.setStartFrame(startFrame);
  testScene.setEndFrame(endFrame);
 
  //construct the raytracer
  cout << "constructing raytracer...\n";
  raytracer testTracer(&testScene, resX, resY);
  cout << "constructing raytracer... done\n";
  testTracer.setTraceDepth(traceDepth);
  testTracer.setAntiAlias(antiAlias);
 
  string test = "test_" + stringify(100) + ".png";
  //begin raytracing
  float nrPixels = resX*resY;
  
  int renderedPixels = 0;
  MyImage.fill(0.0f);
  cout << "-------------------------------------------------\n";
  cout << "starting rendering...\n";
  for (unsigned y=0; y < height; y++) {
     for (unsigned x=0; x < width; x++) {
       color pixelColor;
       pixelColor = testTracer.renderPixel(x,y);
       MyImage(x,y,0) = pixelColor.getR()*255;
       MyImage(x,y,1) = pixelColor.getG()*255;
       MyImage(x,y,2) = pixelColor.getB()*255;
       renderedPixels++;
       float percentage = renderedPixels*100/nrPixels;
       if (percentage - int(renderedPixels*100/nrPixels) == 0) 
       {
         std::cout << percentage << " percent done...\n";
       }
     }
  }
  MyImage.save(filename);
  MyImage.display();
}

void renderSeq() {
  using namespace cimg_library;

  cout << "create image...\n";
  CImg<unsigned char>MyImage(resX,resY,1,3,0);
  unsigned width = MyImage.dimx();  // access image width
  unsigned height = MyImage.dimy(); // access image height

  //create the scene
  cout << "creating scene...\n";
  scene testScene;
  testScene.initScene();
  testScene.setStartFrame(startFrame);
  testScene.setEndFrame(endFrame);
 
  //construct the raytracer
  cout << "constructing raytracer...\n";
  raytracer testTracer(&testScene, resX, resY);
  cout << "constructing raytracer... done\n";
  testTracer.setTraceDepth(traceDepth);
  testTracer.setAntiAlias(antiAlias);
 
  string test = "test_" + stringify(100) + ".png";
  //beging raytracing
  float nrPixels = resX*resY;
  
  for (int i=SubStartFrame; i<=SubEndFrame; i++) {
    string file = filename + stringify(i) + suffix;
    int renderedPixels = 0;
    testScene.setTimeStep(i);
    testScene.initScene();
    MyImage.fill(0.0f);
    cout << "-------------------------------------------------\n";
    cout << "frame "<<i<<"\n";
    cout << "starting rendering...\n";
    for (unsigned y=0; y < height; y++) {
       for (unsigned x=0; x < width; x++) {
         color pixelColor;
         pixelColor = testTracer.renderPixel(x,y);
         MyImage(x,y,0) = pixelColor.getR()*255;
         MyImage(x,y,1) = pixelColor.getG()*255;
         MyImage(x,y,2) = pixelColor.getB()*255;
         renderedPixels++;
         float percentage = renderedPixels*100/nrPixels;
         if (percentage - int(renderedPixels*100/nrPixels) == 0) 
         {
           std::cout << percentage << " percent done...\n";
         }
       }
    }
    char *name = new char[file.length()+1];
    std::strcpy(name, file.c_str());   
    MyImage.save(name);
    //MyImage.display();
  }
}

void view() {
//  CImg<unsigned char> image("lena.jpg")
  //local variables
  //read in variables
//  string test="hello";
//  char filename[128];
//  char line[1024];
//  ifstream file;
  //cout << "Dateiname:" << flush;
  //cin.getline(filename,127);
  //filename = "tracerAttributes.txt";
//  file.open("tracerAttributes.txt",ios::in);  
//  if (file.good())
//  {
//    file.seekg(0L,ios::beg);
  //  while (!file.eof())
  //  {
//      file.getline(line,1024);
  //  }
//  }

  //create the grafic window
//  QuickCG::screen(resX, resY, 0, "raytracing test");

  //create the scene
  scene testScene;
  //testScene.initScene(); 
  //construct the raytracer
  raytracer testTracer(&testScene, resX, resY);
  testTracer.setTraceDepth(traceDepth);
  testTracer.setAntiAlias(antiAlias);

  //beging raytracing
  float nrPixels = resX*resY;
  int renderedPixels = 0;
  for (int i=0; i<resX; i++)
  { 
    for (int j=0; j<resY; j++)
    {
      //cout << "begin rendering of pixel: " << i << " " << j << "\n";
      color pixelColor;
      pixelColor = testTracer.renderPixel(i,j);
     //cout << pixelColor.getR();
     QuickCG::pset(i,j,QuickCG::ColorRGB(pixelColor.getR()*255,pixelColor.getG()*255,pixelColor.getB()*255));
      renderedPixels++;
      float percentage = renderedPixels*100/nrPixels;
      if (percentage - int(renderedPixels*100/nrPixels) == 0)
        std::cout << percentage << " percent done...\n";
    }
  }
//  QuickCG::print(line,8,8);
 
  //on screen!
//  QuickCG::redraw();
//  QuickCG::sleep();

}

void testAlgebra() {
  cout << endl;
  cout << "----------vector-matrix-test-----------------" << endl;

  vector3d a(0.0f,4.0f,2.0f);
  a.print("a");
  
  matrix identity = matrix::getIdentityMatrix();
  identity.print("I");

  vector3d b = identity * a;
  b.print("b=I*a");

  matrix RX = matrix::getRotateXMatrix(70.0);
  matrix RY = matrix::getRotateYMatrix(45.0);
  matrix RZ = matrix::getRotateZMatrix(30.0);

  RX.print("RX");
  RY.print("RY");
  RZ.print("RZ");

  (RX.transpose()*RX).print("RX.transpose()*RX");

  matrix D = RZ*RY*RX;
  matrix E = RX.transpose()*RY.transpose()*RZ.transpose();
  D.print("D = RZ*RY*RX");
  E.print("RX.transpose()*RY.transpose()*RZ.transpose()");
  D.transpose().print("D.transpose()");
 
  (RX*b).print("RX*b");
  (RX.transpose()*b).print("RX.transpose()*b");
  (RX.transpose()*(RX*b)).print("RX.transpose()*(RX*b)");
  (D*b).print("D*b");
  (RZ*(RY*(RX*b))).print("RZ*(RY*(RX*b))");
  (D.transpose()*D).print("D.transpose()*D");
  (D*E).print("D*E");

  b.print("b");
  (RX.transpose()*RY.transpose()*RY*RX).print("RX.transpose()*RY.transpose()*RY*RX");

  (D.transpose()*D*b).print("b");
  
  matrix F = matrix::getTranslationMatrix(1,1,1);
  F.print("F");
  b.print("b");
  (F*b).print("F*b");

  sphere testSphere(vector3d(0,0,0),1);
  testSphere.translate(1,2,3);
  testSphere.rotate(30,45,90);
  // testSphere.scale(2,3,4);
  testSphere.getTranslation().print("testSphere Translation");
  testSphere.getInverseTranslation().print("testSphere InverseTranslation");
  testSphere.getRotation().print("testSphere Rotation");
  testSphere.getInverseRotation().print("testSphere InverseRotation");
  testSphere.getScaling().print("testSphere Scaling");
  testSphere.getInverseScaling().print("testSphere InverseScaling");

  (testSphere.getScaling() * testSphere.getInverseScaling()).print("Scaling * InverseScaling");
  
  locator testLocator;
  testLocator.getTranslation().print("testLocator Translation");
}


void testTrigonometry() {
  cout << "PI : " << PI << endl;
  cout << "cos(PI) : " << cos(PI) << endl;
  cout << "sin(PI) : " << sin(PI) << endl;
}

string stringify(double x) {
   std::ostringstream o;
   o << x;
   return o.str();
} 

