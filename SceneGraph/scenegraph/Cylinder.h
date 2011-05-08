#ifndef CYLINDER_H_
#define CYLINDER_H_

#include "Geometry.h"

namespace sg {
/**
 * Concrete geometry core implementation. It represents a cylinder geometry. 
 */
class Cylinder : public Geometry
{
public:
	/** Simple constructor */
	Cylinder();
	/** Simple destructor */
	virtual ~Cylinder();
	
	/**
	 * Calls GLU methods to create the cylinder.
	 */
	virtual void draw();
};

}
#endif /*CYLINDER_H_*/
