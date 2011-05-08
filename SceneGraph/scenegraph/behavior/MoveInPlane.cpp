#include "MoveInPlane.h"

#include <iostream>
//#include <GL/glut.h>
#import <GLUT/glut.h>

using namespace std;

namespace sg
{

MoveInPlane::MoveInPlane(Input* keys, float speed, float aSpeed) 
: BehaviorCore(), speed(speed), angleSpeed(aSpeed)
{
	setKeys(keys);
	allBehavior.push_back(this);
	setIdentity();
}

MoveInPlane::~MoveInPlane()
{
}

void MoveInPlane::update(SGInput* inp, double time) {
	float dist = 0;
	float angle = 0;
	if ( inp->contains(keys[0]) ) {
		dist = speed*time;	
	}
	else if ( inp->contains(keys[1]) ) {
		dist = 	-speed*time;
	}
	else {
		dist = 0;	
	}
	if ( inp->contains(keys[2]) ) {
		angle = time*angleSpeed;	
	}	
	else if ( inp->contains(keys[3]) ) {
		angle = -time*angleSpeed;	
	}
	else {
		angle = 0;	
	}
	translate(0,0,dist);
	rotate(angle,0,1,0);
}

void MoveInPlane::setKeys(Input* inpKeys) {
	for(int i = 0; i < NUM_KEYS; i++) {
		keys[i] = inpKeys[i];	
	}	
}

}
