#ifndef MOVEINPLANE_H_
#define MOVEINPLANE_H_

#include "BehaviorCore.h"
#include "SGInput.h"

#define NUM_KEYS 4

namespace sg
{
	
/**
 * This class implements the moving within a level or plane. Possible movements are
 * going ahead and back, and turning left and right. The movement happens within the
 * x-z-plane where the y-coordinate points up. To move within other planes appropriate
 * Transformations has to be done previously. 
 * Four keys are required control. 
 */
class MoveInPlane : public sg::BehaviorCore
{
public:
	/**
	 * Constructor of class MoveInPlane
	 * \param keys		Keys which are used to control this class transformation. 
	 * \see setKeys()
	 * \param speed 	The speed for moving ahead and back.
	 * \param aSpeed 	The angle speed for turning left and right. 
	 */
	MoveInPlane(Input* keys, float speed, float aSpeed);
	
	/**
	 * virtual Destuctor
	 */
	virtual ~MoveInPlane();
	
	/**
	 * This method is an ordinary setter-method for the member keys. The array has to
	 * have four elements.
	 * 
	 * \param keys  Awaits an array of 4 Input-objects which on their part contain
	 * 				a ASCII- or special key. The order of the keys is important because
	 * 				the first and second key are used to move ahead and back, and the
	 * 				third and fourth key are used to turn left and right.
	 */
	void setKeys(Input* keys);
	
	/**
	 * This method updates the transformation inherited from BehaviorCore in conjunction 
	 * with the pressed keys containd in the given SGInput object.
	 * @param inp a pointer to an SGInput object which contains all pressed keys
	 * @param time elapsed time since the last call.
	 */
	void update(SGInput* inp, double time);

private:
	Input keys[NUM_KEYS]; ///< the specified keys for controlling the movement
	float speed; ///< speed for moving forward or backward
	float angleSpeed; ///< speed for turning left or right
};

}

#endif /*MOVEINPLANE_H_*/
