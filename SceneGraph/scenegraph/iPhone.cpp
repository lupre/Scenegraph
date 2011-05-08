//
//  iPhone.cpp
//  SceneGraph
//
//  Created by Daniel on 4/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

// Already configurated in "Build-Settings:Header-Search-Path"
//#include "opencv2/opencv.hpp" 
#include "iPhone.h"
#include "Vector3d.h"
#include <iostream>

// include generated arrays
#import "./iPhone4Model.h"


using namespace std;

namespace sg {
	
    iPhone::iPhone(char* labelStr):ObserverGeometry(labelStr)
    {
    }
    
    iPhone::~iPhone()
    {
    }
    
    void iPhone::draw() {
        double imagePlaneDistance = 0.1;
        double h = imagePlaneDistance;
        double w = imagePlaneDistance * 4/3.0;
        
        //Vector3d* a = new Vector3d(+h/2.0, -w/2.0, imagePlaneDistance);
        //Vector3d* b = new Vector3d(-h/2.0, -w/2.0, imagePlaneDistance);
        //Vector3d* c = new Vector3d(-h/2.0, +w/2.0, imagePlaneDistance);
        //Vector3d* d = new Vector3d(+h/2.0, +w/2.0, imagePlaneDistance);
        Vector3d a(+h/2.0, -w/2.0, imagePlaneDistance);
        Vector3d b(-h/2.0, -w/2.0, imagePlaneDistance);
        Vector3d c(-h/2.0, +w/2.0, imagePlaneDistance);
        Vector3d d(+h/2.0, +w/2.0, imagePlaneDistance);
        
        glBegin(GL_LINES);
            // Camera center line
            glVertex3d(0,0,0);
            glVertex3d(0,0,imagePlaneDistance);
            // Camera frustum lower left line
            glVertex3d(0,0,0);
            //glVertex3d(a->x, a->y, a->z);
            glVertex3d(a.x, a.y, a.z);
            // Camera frustum lower right line
            glVertex3d(0,0,0);
            glVertex3d(b.x, b.y, b.z);
            // Camera frustum upper right line
            glVertex3d(0,0,0);
            glVertex3d(c.x, c.y, c.z);
            // Camera frustum upper left line
            glVertex3d(0,0,0);
            glVertex3d(d.x, d.y, d.z);
        
            std::vector<GeomTrans_t>::iterator it = geomList.begin();
            for ( ; it!=geomList.end(); it++) {
                GLdouble *matrix = it->trans->getMatrix();
                glVertex3d(0, 0, 0);
                glVertex3d(matrix[12], matrix[13], matrix[14]);
            }
                
//            if (transToRemote)
//            {
//                GLdouble *matrix = transToRemote->getMatrix();
//                glVertex3d(0, 0, 0);
//                glVertex3d(matrix[12], matrix[13], matrix[14]);
//            }
        glEnd();
        
        glBegin(GL_LINE_LOOP);
            glVertex3d(a.x, a.y, a.z);
            glVertex3d(b.x, b.y, b.z);
            glVertex3d(c.x, c.y, c.z);
            glVertex3d(d.x, d.y, d.z);
        glEnd();
        
        
        
            
/*
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

//        glEnable(GL_VERTEX_ARRAY);
//        glEnable(GL_NORMAL_ARRAY);
        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_NORMAL_ARRAY);
        
        // set input data to arrays
        glVertexPointer(3, GL_FLOAT, 0, iPhone4modelVerts);
        glNormalPointer(GL_FLOAT, 0, iPhone4modelNormals);
        
        glPushMatrix();
            double iPhoneHeight = 0.11515; // in meters
            double iPhoneDepth = 0.00934; // in meters
            
            // Move the iPhone4Model origin from its lower-left-back-corner location 
            // into the upper-left-front corner.
            glTranslated(0.0, -iPhoneHeight, -iPhoneDepth);
            // From there translate the origin into the eye of the camera. 
            double distCamCenter2Edge = 0.00877; // in meters
            glTranslated(-distCamCenter2Edge, distCamCenter2Edge, 0.0);

            // iPhone4Models' longest side (the height) is in the iPhone4Model.h file scaled to 1. 
            // The original height of iPhone4 is 115.15mm so scale to right size:
            // (OpenGL-Scene units are meters)
            double s = iPhoneHeight / 1.0;
            glScaled(s, s, s);
            // draw data
            glDrawArrays(GL_TRIANGLES, 0, iPhone4modelNumVerts);
        glPopMatrix();

    }
    
}
