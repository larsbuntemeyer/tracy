//ray.cpp

#include "ray.h"

ray::ray() {
	origin.setCoordinates(0,0,0);
	direction.setCoordinates(0,0,1);
}

ray::ray(vector3d origin_in, vector3d direction_in) {
	origin = origin_in;
	direction = direction_in;
}

ray::~ray() {
}
		
void ray::setOrigin(vector3d origin_in) {
	origin = origin_in;
}

void ray::setDirection(vector3d direction_in) {
	direction = direction_in;
}

vector3d& ray::getOrigin() {
	return origin;
}

vector3d& ray::getDirection() {
	return direction;
}
