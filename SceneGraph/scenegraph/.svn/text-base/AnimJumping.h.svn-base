#ifndef ANIMJUMPING_H_
#define ANIMJUMPING_H_

#include "Animation.h"
#include "../vecalg/VectorAlgebra.h"
#include "../vecalg/Vector3d.h"

namespace sg {

/**
 * This class is a concrete implementation of the Animation class. It implements a 
 * jumping animation.
 */
class AnimJumping : public Animation
{
public:
	/**
	 * The constructor for the class AnimJumping. It initializes the members with 
	 * the paramter values.
	 * @param 	dir the direction to jump along
	 * @param 	boundary the boundary for the jumping; so it will jump between 0 and 
	 * 			boundary
	 */
	AnimJumping(Vector3d dir, double boundary);
	
	/** Simple destructor */
	virtual ~AnimJumping();
	
	/**
	 * Applies the changings to the inherited transformation to perform a jumping 
	 * animation.
	 */
	void update(double time);

private:
	Vector3d direction; ///< jumping direction
	double maxBoundary; ///< boundary for jumping
	double acceleration; ///< acceleration of jumping
	bool falling; ///< flag symbolizes if falling (true) or raising (false)
	double lastRatio; ///< last distance (computed while last call of update)
};
}
#endif /*ANIMJUMPING_H_*/
