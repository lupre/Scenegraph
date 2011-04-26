//
//  CodeMarker.h
//  SceneGraph
//
//  Created by Daniel on 4/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef CODEMARKER_H_
#define CODEMARKER_H_

#include "Geometry.h"

namespace sg {
    /**
     * Concrete geometry core implementation. It represents a cube geometry. 
     */
    class CodeMarker : public Geometry
    {
    public:
        /** Simple constructor */
        CodeMarker(char* labelStr);
        /** Simple destructor */
        virtual ~CodeMarker();
        
        /**
         * Calls the method glutSolidCube() with the specified makros.
         */
        virtual void draw();
    };
}
#endif /*CODEMARKER_H_*/
