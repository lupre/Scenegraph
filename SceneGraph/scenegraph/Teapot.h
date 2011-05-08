#ifndef TEAPOT_H_
#define TEAPOT_H_

#include "Geometry.h"

namespace sg
{

/**
 * Concrete geometry core implementation. It represents a teapot geometry. 
 */
class Teapot : public Geometry
{
public:
	/** Simple constructor */
	Teapot(char* labelStr);
	/** Simple destructor */
	virtual ~Teapot();
	
	/**
	 * Calls glutSolidTeapot()
	 */
	void draw();
};

}

#endif /*TEAPOT_H_*/
