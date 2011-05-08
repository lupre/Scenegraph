#ifndef SPHERE_H_
#define SPHERE_H_
#include "Geometry.h"

/** \define radius of the sphere */
#define RADIUS 1
 
/** \define slices of the sphere */
#define S_SLICES 20

/** \define stacks of the sphere */
#define S_STACKS 20

namespace sg {

/**
 * Concrete geometry core implementation. It represents a sphere geometry. 
 */
class Sphere : public Geometry
{
public:
	/** Simple constructor */
	Sphere(char* labelStr);
	/** Simple destructor */
	virtual ~Sphere();
	
	/**
	 * Calls the corresponding GLU methods to draw the sphere using the specified makros.
	 */
	virtual void draw();
};
}
#endif /*SPHERE_H_*/
