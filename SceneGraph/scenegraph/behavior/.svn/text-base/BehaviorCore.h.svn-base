#ifndef NODEBEHAVIOR_H_
#define NODEBEHAVIOR_H_

#include <vector>
#include "../Transformation.h"
#include "SGInput.h"

namespace sg
{

/**
 * This class implements the transformation behavior for specified input events.
 * That means if a key is pressed and an instance of this class is configured to
 * react to that event, the matrix, which represents the transformation, is updated 
 * to the new status.
 * This class is abstract and defines just the rack for a controlable Transformation
 * class. 
 * \see sg::Transformation
 */
class BehaviorCore : public sg::Transformation
{
	
	
public:
	/**
	 * A simple constructor which adds a pointer to itself to the member allBehaviors.
	 */
	BehaviorCore();
	virtual ~BehaviorCore();
	
	/**
	 * Performs an update of the Transformation regarding the input parameters. This
	 * method has to be implemented in a concrete sub class.
	 * \param inp Pointer of type SGInput, which contains all the pressed keys.
	 * \param time The time since the last update.
	 */
	virtual void update(SGInput* inp, double time)=0;
	
	/**
	 * Applies for all BehaviorCore-objctes included in allBehavior the update() method.
	 * @param inp a point to an SGInput object which contains the pressed keys.
	 * @param time the elapsed time since the last call
	 */
	static void updateAllBehaviors(SGInput* inp, double time);
	
	static vector<BehaviorCore*> allBehavior;/**< a vector which holds a pointer to every 
													existing BehaviorCore-Object */
};

}

#endif /*NODEBEHAVIOR_H_*/
