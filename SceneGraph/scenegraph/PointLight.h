#ifndef POINTLIGHT_H_
#define POINTLIGHT_H_

#include "Light.h"

namespace sg {
	
/**
 * Implements a concrete light namely a point light.
 */
class PointLight : public Light
{
public:
	/**
	 * Constructor calls the counstructor of the super class and sets the last value of
	 * the position array to 1. So it is a point light.
	 */
	PointLight();
	
	/** Simple destructor */
	virtual ~PointLight();
	
	/**
	 * Applies the light settings to the OpenGL state machine.
	 */
	void enable();
};
}
#endif /*POINTLIGHT_H_*/
