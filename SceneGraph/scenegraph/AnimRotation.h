/** The Scenegraph namespace.
 * sg: The Scenegraph namespace. Contains all classes required for building and dynamic
 * and interactive scenegraph.
 */
#ifndef ANIMROTATION_H_
#define ANIMROTATION_H_
#include "Animation.h"
#include "../vecalg/Vector3d.h"

namespace sg {
/**
 * This class is a concrete implementation of the Animation class. It implements a 
 * rotation animation.
 */
class AnimRotation : public Animation
{
public:
	/**
	 * The constructor for the class AnimRotation. It sets the corresoponding members to
	 * the parameter values.
	 * @param speed is the rotational speed
	 * @parama axis is the axis to rotate around
	 */
	AnimRotation(double speed, Vector3d axis);
	
	/** Simple destructor */
	virtual ~AnimRotation();
	
	/**
	 * Applies the changings to the inherited transformation to perform a rotation.
	 */
	void update(double time);

private:
	double lastAngle; ///< the last angle computed while the last call of update
	double speed; ///< rotational speed
	Vector3d axis; ///< axis to rotate around
};
}
#endif /*ANIMROTATION_H_*/
