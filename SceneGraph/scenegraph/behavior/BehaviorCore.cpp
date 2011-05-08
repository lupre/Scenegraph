#include "BehaviorCore.h"

namespace sg
{

vector<BehaviorCore*> BehaviorCore::allBehavior;

BehaviorCore::BehaviorCore() : Transformation()
{
}

BehaviorCore::~BehaviorCore()
{
}

void BehaviorCore::updateAllBehaviors(SGInput* inp, double time) {
	vector<BehaviorCore*>::iterator iter = allBehavior.begin();
	
	while( iter != allBehavior.end() ) {
		(*iter)->update(inp, time);
		iter++;	
	}	
}

}
