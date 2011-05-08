//
//  Universe.cpp
//  SceneGraph
//
//  Created by Lukas on 28.04.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef _UNIVERSE_H_
#define _UNIVERSE_H_

#include "Universe.h"
#include "TransformTraverser.h"
#include "Renderer.h"


namespace sg {
    Universe* Universe::instance(0);
    
    Universe::Universe()
    {
    }
    
    Universe::~Universe()
    {
    }
    
    const Universe* Universe::getUniverseInstance()
    {
        if (!instance) {
            instance = new Universe;
        }
        return instance;
    }
    
    Transformation* Universe::getTransTo(const Geometry *observer, 
                                         const Geometry *observedObj) const
    {
        Node* root = Renderer::getRoot();
        //Traverser* t = new TransformTraverser(observer, observedObj);
        TransformTraverser t(observer, observedObj);
        t.Traverser::visit(root);
        // ToDo: check if this casting stuff is really neccessary
        //return dynamic_cast<TransformTraverser*>(t)->getTransFromRefToObj();
        return t.getTransFromRefToObj();
    }
}

#endif