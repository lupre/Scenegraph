//
//  iPhone.h
//  SceneGraph
//
//  Created by Daniel on 4/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef IPHONE_H_
#define IPHONE_H_

#include "Geometry.h"

namespace sg {
    /**
     * Concrete geometry core implementation. It represents a cube geometry. 
     */
    class iPhone : public Geometry
    {
    public:
        /** Simple constructor */
        iPhone(char* labelStr);
        /** Simple destructor */
        virtual ~iPhone();
        
        /**
         * Calls the method glutSolidCube() with the specified makros.
         */
        virtual void draw();
    };
}
#endif /*IPHONE_H_*/
