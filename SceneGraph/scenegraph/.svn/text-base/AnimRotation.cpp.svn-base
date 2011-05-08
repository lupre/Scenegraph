#include "AnimRotation.h"
#include <iostream>

namespace sg {
	
using namespace std;
	
AnimRotation::AnimRotation(double speed, Vector3d axis) : Animation(), speed(speed), axis(axis)
{
	allAnimations.push_back(this);
}

AnimRotation::~AnimRotation()
{
}

void AnimRotation::update(double time) {
	double currentAngle = lastAngle + time * speed;	
	setIdentity();
	rotate(currentAngle, axis.x, axis.y, axis.z);
	if(currentAngle >= 360) {
		currentAngle -= 360;	
	} else if (currentAngle < -360) {
		currentAngle += 360;
	}
	lastAngle = currentAngle;
}

}