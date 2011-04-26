//
//  CoordSys.h
//  SceneGraph
//
//  Created by Daniel on 4/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef COORDSYS_H_
#define COORDSYS_H_

//#include "Geometry.h"
#import <OpenGL/OpenGL.h>
#import <GLUT/glut.h>


namespace sg {
    /**
     * Concrete geometry core implementation. It represents a cylinder geometry. 
     */
    class CoordSys
    {
    public:
        /** Simple constructor */
        CoordSys(char* str);
        /** Simple destructor */
        virtual ~CoordSys();
        
        /**
         * Calls GLU methods to create the cylinder.
         */
        virtual void draw();
    private:
        /*
         Draw text in the x-y plane
         The x,y,z coordinate is the bottom left corner (looking down -ve z axis)
         */
        void drawTextXY(double x, double y, double z, double scale, char* s);
        char* labelStr; // holds label String which describes whose coordSys this is. 
    };
    
}
#endif /*COORDSYS_H_*/