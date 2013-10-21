// ray

#ifndef _RAY_
#define _RAY_

#include "vector3d.h"

class ray
{
	public:
		ray();
		ray(vector3d origin_in, vector3d direction_in);
		~ray();

		void setOrigin(vector3d origin_in);
		void setDirection(vector3d direction_in);
		vector3d& getOrigin();
		vector3d& getDirection();

		vector3d origin;
		vector3d direction;
	private:	
};

#endif