//
//  CoordSys.cpp
//  SceneGraph
//
//  Created by Daniel on 4/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "CoordSys.h"
#include "string.h"

namespace sg {
	
    CoordSys::CoordSys(char* str)
    {
        labelStr = str;
    }
    
    CoordSys::~CoordSys()
    {
    }
    
    void CoordSys::draw() {
        GLUquadricObj* quad;
        quad = gluNewQuadric();
        gluQuadricDrawStyle(quad, GLU_FILL);
        double radius = 0.001; // in meters ≙ 1mm
        double height = 0.02; // in meters ≙ 2cm
        double arrowRadius = radius * 1.618;
        double arrowHeight = 0.005; // in meters ≙ 5mm
        int slices = 12; // Specifies the number of subdivisions around the circle.
        int stacks = 1; // Specifies the number of subdivisions along the height.

        // Cylinder in positive x-axis:
        glColor3d(1,0,0);
        glPushMatrix();
            glRotated(90, 0, 1, 0);
            gluCylinder(quad, radius, radius, height, slices, stacks);
            glTranslated(0, 0, height);
            gluCylinder(quad, arrowRadius, 0, arrowHeight, slices, stacks);
        glColor3d(1,1,1);
        drawTextXY( -height/2, height/2, radius, 0.0001, labelStr);
        glPopMatrix();

        // Cylinder in positive y-axis:
        glColor3d(0,1,0);
        glPushMatrix();
        glRotated(-90, 1, 0, 0);
        gluCylinder(quad, radius, radius, height, slices, stacks);
        glPopMatrix();
        
        // Cylinder in positive z-axis:
        glColor3d(0,0,1);
        glPushMatrix();
        glRotated(0, 1, 0, 0);
        gluCylinder(quad, radius, radius, height, slices, stacks);
        glPopMatrix();
        gluDeleteQuadric(quad);
    }
    
    /*
     Draw text in the x-y plane
     The x,y,z coordinate is the bottom left corner (looking down -ve z axis)
     */
    void CoordSys::drawTextXY(double x,double y,double z,double scale,char *s)
    {
        int i;
        
        glPushMatrix();
            glRotated(-90, 0,1,0 );
            glTranslatef(x,y,z);
            glScalef(scale,scale,scale);
            for (i=0;i<strlen(s);i++) {
                glutStrokeCharacter(GLUT_STROKE_ROMAN,s[i]);
            }
        glPopMatrix();
    }

    
}
