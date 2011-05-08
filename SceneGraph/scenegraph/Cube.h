#ifndef CUBE_H_
#define CUBE_H_

#include "Geometry.h"

/** \define size of the cube */
#define SIZE 1

namespace sg {
/**
 * Concrete geometry core implementation. It represents a cube geometry. 
 */
class Cube : public Geometry
{
public:
	/** Simple constructor */
	Cube(char* labelStr);
	/** Simple destructor */
	virtual ~Cube();
	
	/**
	 * Calls the method glutSolidCube() with the specified makros.
	 */
	virtual void draw();
};
}
#endif /*CUBE_H_*/
