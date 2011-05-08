//
//  Universe.h
//  SceneGraph
//
//  Created by Lukas on 28.04.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Transformation.h"
#include "Geometry.h"

namespace sg {
    class Universe 
    {
    private:
        Universe();
    public:
        virtual ~Universe();
        static const Universe* getUniverseInstance();
        
        Transformation* getTransTo(const Geometry* observer, const Geometry* observedObj) const;
        
    private:
        static Universe* instance;
    };
}
