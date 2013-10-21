//plane.h

#ifndef _PLANE_
#define _PLANE_

#include "vector3d.h"
#include "primitive.h"

class plane : public primitive {
	public:
		plane();
		plane(vector3d position, vector3d normal,
				float length, float width);
		float intersect(ray ray);
		float getLength(){return mLength;};
		float getWidth(){return mWidth;};
		vector3d getNormal(vector3d p);
	private:
		vector3d mNormal;
		float mLength, mWidth;
};

#endif
