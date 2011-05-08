#include "AnimJumping.h"
#include <iostream>

using namespace std;

namespace sg {
	
AnimJumping::AnimJumping(Vector3d dir,  double boundary) 
	: Animation(), direction(dir), maxBoundary(boundary)
{
	allAnimations.push_back(this);
	lastRatio = 0;
	falling = false;
}

AnimJumping::~AnimJumping()
{
}

void AnimJumping::update(double time) {
	acceleration = max((maxBoundary - lastRatio), 0.3);
	if(falling) acceleration *= -1;
	
	double currentRatio = lastRatio + time*acceleration;
	
	if (currentRatio >= maxBoundary) {
		falling = true;	
	}
	
	if (currentRatio <= 0) {
		currentRatio = 0.001;
		falling = false;	
	}
	lastRatio = currentRatio;
	Vector3d resultVec;
	VectorAlgebra::multVec3d(direction, currentRatio, resultVec);
	setIdentity();
	translate(resultVec.x, resultVec.y, resultVec.z);
}

}
