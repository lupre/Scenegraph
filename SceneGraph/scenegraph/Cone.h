#ifndef CONE_H_
#define CONE_H_
#include "Geometry.h"

/** \define radius of the base circle */
#define BASE 0.5

/** \define height of the cone */
#define HEIGHT 1

/** \define slices of the cone */
#define SLICES 10

/** \define stacks of the cone */
#define STACKS 10

namespace sg {
/**
 * Concrete geometry core implementation. It represents a cone geometry. 
 */
class Cone : public Geometry
{
public:
	/** Simple constructor */
	Cone(char* labelStr);
	/** Simple destructor */
	virtual ~Cone();
	
	/**
	 * Calls the method glutSolidCone() with the specified makros.
	 */
	virtual void draw();
};
}
#endif /*CONE_H_*/
