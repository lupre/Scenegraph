//
//  AnimNodding.h
//  SceneGraph
//
//  Created by Daniel on 4/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

/** The Scenegraph namespace.
 * sg: The Scenegraph namespace. Contains all classes required for building and dynamic
 * and interactive scenegraph.
 */
#ifndef ANIMNODDING_H_
#define ANIMNODDING_H_
#include "Animation.h"
#include "../vecalg/Vector3d.h"

namespace sg {
    /**
     * This class is a concrete implementation of the Animation class. It implements a 
     * rotation animation.
     */
    class AnimNodding : public Animation
    {
    public:
        /**
         * The constructor for the class AnimRotation. It sets the corresoponding members to
         * the parameter values.
         * @param speed is the rotational speed
         * @parama axis is the axis to rotate around
         */
        AnimNodding(double speed, Vector3d axis, double angleRange, double angleOffset);
        
        /** Simple destructor */
        virtual ~AnimNodding();
        
        /**
         * Applies the changings to the inherited transformation to perform a rotation.
         */
        void update(double time);
        
    private:
        double lastAngle; ///< the last angle computed while the last call of update
        double speed; ///< rotational speed
        Vector3d axis; ///< axis to rotate around
        double angleRange; // lower limit angle of nodding
        double angleOffset; // upper limit angle of nodding
    };
}
#endif /*ANIMNODDING_H_*/
