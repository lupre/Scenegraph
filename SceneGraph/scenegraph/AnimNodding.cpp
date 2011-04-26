//
//  AnimNodding.cpp
//  SceneGraph
//
//  Created by Daniel on 4/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "AnimNodding.h"
#include <iostream>
#include "math.h"

namespace sg {
	
    using namespace std;
	
    AnimNodding::AnimNodding(double speed, Vector3d axis, double angleRange, double angleOffset) : Animation(), speed(speed), axis(axis), angleRange(angleRange), angleOffset(angleOffset)
    {
        allAnimations.push_back(this);
    }
    
    AnimNodding::~AnimNodding()
    {
    }
    
    void AnimNodding::update(double time) {
        double currentAngle = lastAngle + time * speed;	
        setIdentity();
//        rotate(currentAngle, axis.x, axis.y, axis.z);
        double noddingAngle = sin(currentAngle) * angleRange + angleOffset;
        rotate(noddingAngle, axis.x, axis.y, axis.z);

        if(currentAngle >= 360) {
            currentAngle -= 360;	
        } else if (currentAngle < -360) {
            currentAngle += 360;
        }
        lastAngle = currentAngle;
    }
    
}