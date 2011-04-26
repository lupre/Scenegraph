//
//  CodeMarker.cpp
//  SceneGraph
//
//  Created by Daniel on 4/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "CodeMarker.h"


// Already configurated in "Build-Settings:Header-Search-Path"
//#include "opencv2/opencv.hpp" 
#include "iPhone.h"
#include "Vector3d.h"
#include <iostream>

using namespace std;

namespace sg {
	
    CodeMarker::CodeMarker(char* labelStr):Geometry(labelStr)
    {
    }
    
    CodeMarker::~CodeMarker()
    {
    }
    
    void CodeMarker::draw() {
        
        bool bits[] = {
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,1,1,0,0,0,0,
            0,0,1,1,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0,
            0,0,0,0,0,0,0,0
        };
        
        double codeMarkerWidth = 0.1; // = 10cm;
        double codeMarkerBitWidth = codeMarkerWidth / 8.0;
        double w = codeMarkerBitWidth;
        double h = codeMarkerBitWidth;
        
        
/*        glBegin(GL_QUADS);
            glColor3d(0.8,0,0);
            glNormal3d(0,1,0);
            glVertex3d(0.0, 0.0, 0.0);
            glVertex3d(0.0, 0.0, +0.1);
            glVertex3d(0.1, 0.0, +0.1);
            glVertex3d(0.1, 0.0, 0.0);
        glEnd();
*/
        glBegin(GL_QUADS);
            for (int x=0; x<8; x++) {
                for (int z=0; z<8; z++) {
                    // p: upper left corner of one square/bit of codeMarker. 
                    Vector3d* p = new Vector3d(x*w, 0, z*h);
                    Vector3d* a = new Vector3d(p->x + 0, 0.0, p->z + 0);
                    Vector3d* b = new Vector3d(p->x + 0, 0.0, p->z + h);
                    Vector3d* c = new Vector3d(p->x + w, 0.0, p->z + h);
                    Vector3d* d = new Vector3d(p->x + w, 0.0, p->z + 0);

                    double col = bits[z*8+x];
                    glColor3d(col,col,col);
                    if ( 1 == col ){
                        continue;
                    }
                    
                    glVertex3d(a->x, a->y, a->z);
                    glVertex3d(b->x, b->y, b->z);
                    glVertex3d(c->x, c->y, c->z);
                    glVertex3d(d->x, d->y, d->z);
                }
            }
        glEnd();


        /*
        double imagePlaneDistance = 0.1;
        double h = imagePlaneDistance;
        double w = imagePlaneDistance * 4/3.0;
        
        Vector3d* a = new Vector3d(+h/2.0, -w/2.0, imagePlaneDistance);
        Vector3d* b = new Vector3d(-h/2.0, -w/2.0, imagePlaneDistance);
        Vector3d* c = new Vector3d(-h/2.0, +w/2.0, imagePlaneDistance);
        Vector3d* d = new Vector3d(+h/2.0, +w/2.0, imagePlaneDistance);
        
        glBegin(GL_LINES);
        // Camera center line
        glVertex3d(0,0,0);
        glVertex3d(0,0,imagePlaneDistance);
        // Camera frustum lower left line
        glVertex3d(0,0,0);
        glVertex3d(a->x, a->y, a->z);
        // Camera frustum lower right line
        glVertex3d(0,0,0);
        glVertex3d(b->x, b->y, b->z);
        // Camera frustum upper right line
        glVertex3d(0,0,0);
        glVertex3d(c->x, c->y, c->z);
        // Camera frustum upper left line
        glVertex3d(0,0,0);
        glVertex3d(d->x, d->y, d->z);
        glEnd();
        
        glBegin(GL_LINE_LOOP);
        glVertex3d(a->x, a->y, a->z);
        glVertex3d(b->x, b->y, b->z);
        glVertex3d(c->x, c->y, c->z);
        glVertex3d(d->x, d->y, d->z);
        glEnd();
        
        glPushMatrix();
        // Move coordinate origin into center of iPhone backside camera. 
        glTranslated(0.0588/2.0 - 0.0085, 
                     -0.1109/2.0 + 0.0085, 
                     -0.009/2.0);
        glPushMatrix();
        glScaled(0.0588, 0.1109, 0.009);
        glutSolidCube(1);
        glPopMatrix();
        
        glPopMatrix();

*/
        
    }
    
}
