#include "Animation.h"
#include <iostream> 

namespace sg {

vector<Animation*> Animation::allAnimations;

Animation::Animation() : Transformation()
{
}

Animation::~Animation()
{
}

void Animation::updateAllAnimation(double time) {
	vector<Animation*>::iterator iter;
	
	for(iter = allAnimations.begin(); iter < allAnimations.end(); iter++) {
		(*iter)->update(time);	
	}
}

}
