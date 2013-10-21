//vector3d

#include <iostream>
#include "vector3d.h"
#include "math.h"

using namespace std;

//Konstruktor
vector3d::vector3d(void) {
	x = 0;
	y = 0;
	z = 0;
}

//Konstruktor
vector3d::vector3d(float x_in, float y_in, float z_in) {
	x = x_in;
	y = y_in;
	z = z_in;
}

//Desktruktor
vector3d::~vector3d() {
}

//gibt die Länge des Vektors zurück
float vector3d::getLength() {
	return sqrt(x*x+y*y+z*z);
}

//normalisiert den Vektor auf die Länge 1
void vector3d::Normalize() {
	float length = getLength();
	if (length != 0) {
		x /= length;
		y /= length;
		z /= length;
	}
}

//setze die Koordinaten
void vector3d::setCoordinates(float x_in, float y_in, float z_in) {
	x = x_in;
	y = y_in;
	z = z_in;
}

//schreibt einen Vektor auf die Konsole
void vector3d::print(string name) {
  cout << "vector " << name << " : " << x << " " << y << " " << z << "\n";
}
 
//skalarprodukt static
float vector3d::Dot(vector3d a, vector3d b) {
	return (a.x*b.x+a.y*b.y+a.z*b.z);
}

//skalarprodukt
float vector3d::Dot(vector3d a) {
	return (x * a.x + y * a.y + z * a.z);
}

vector3d vector3d::getNormalVector() {
	return vector3d(x, (-pow(x,2)-pow(z,2))/y, z);
}

void vector3d::operator +=(vector3d A) {
	x += A.x;
	y += A.y;
	z += A.z;
}

void vector3d::operator -=(vector3d A) {
	x -= A.x;
	y -= A.y;
	z -= A.z;
}


void vector3d::operator *=(float a) {
	x *= a;
	y *= a;
	z *= a;
}

vector3d operator +(vector3d A, vector3d B) {
	return vector3d(A.x + B.x, A.y + B.y, A.z + B.z);
}

vector3d operator -(vector3d A, vector3d B) {
	return vector3d(A.x - B.x, A.y - B.y, A.z - B.z);
}

float operator *(vector3d A, vector3d B) {
	return (A.x * B.x + A.y * B.y + A.z * B.z);
}

vector3d operator *(float a, vector3d B) {
	return vector3d(a * B.x, a * B.y, a * B.z);
}

