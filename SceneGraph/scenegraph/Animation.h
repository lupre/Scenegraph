#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <vector>
#include "Transformation.h"
#include "VCore.h"

using namespace std;

namespace sg {
/**
 * This class extends the transformation core to be an time variing animation. This class
 * is abstract because it declares an abstract method update which performs the update of
 * the inherited transformation after a given time.
 * All Animations are stored in a static list and can be access easily this way.
 */
class Animation : public Transformation
{
public:
	/**
	 * A simple constructor which adds a pointer to itself to the vector allAnimations.
	 */
	Animation();
	
	/** Simple destructor */
	virtual ~Animation();
	
	/**
	 * Applies the update method to all Animation objects stored in allAnimation. 
	 * @param time the elapsed time since the last call
	 */
	static void updateAllAnimation(double time);
	
	/**
	 * abstract method which is used to update the transformation for a given time step.
	 * @param time the elapsed time since the last call
	 */
	virtual void update(double time)=0;
	
	static vector<Animation*> allAnimations;///< contains all created Animation objects
};

}
#endif /*ANIMATION_H_*/
