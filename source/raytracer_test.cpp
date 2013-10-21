// raytracer_project_test.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

//#include "stdafx.h"
#include "vector3d.h"
#include "frame.h"
#include "ray.h"
#include "camera.h"
#include "sphere.h"
#include "scene.h"
#include "raytracer.h"
#include <iostream>
using namespace std;

int main(int argc, const char* argv[])
{
	int i,j;
	vector3d v(1,2,3);
	vector3d u(2,-2,5);
	vector3d w = v + u;
	vector3d x = v;
	x *= 2;
	cout << "\n v " << v.x << " " << v.y << " " << v.z;
	cout << "\n u " << u.x << " " << u.y << " " << u.z;
	cout << "\n w " << w.x << " " << w.y << " " << w.z;
	cout << "\n x " << x.x << " " << x.y << " " << x.z;
	cout << "\n u*v " << u*v;
	cout << "\n 5*v " << (5*v).x << " " << (5*v).y << " " << (5*v).z;
	x.Normalize();
	cout << "\n v " << x.x << " " << x.y << " " << x.z;
	
	vector3d normal = u.getNormalVector();
	cout << "\n normal to u " << normal.x << " " << normal.y << " " << normal.z;
	cout << "\n normal*u " << normal*u;

	//sphere Sphere(u,1);
	camera myCam;
	//myScreen.setHeight(1000);
	myCam.setHeight(1024);

	scene testScene;
	testScene.initScene();
	raytracer testTracer(&testScene, 100, 50);
	int maxi = testTracer.getResX();
	int maxj = testTracer.getResY();

	for (i=0; i<maxi; i++)
		{
			for (j=0; j<maxj; j++)
			{
				color pixelColor;
				pixelColor = testTracer.renderPixel(i,j);
//				cout << "\n i,j " << i << " " << j << " colorR " << pixelColor.getR();
			}
		}

	cin >> i;
	return 0;
}

