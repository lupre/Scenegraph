//
//  TransformTraverser.cpp
//  SceneGraph
//
//  Created by Lukas on 20.04.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "TransformTraverser.h"

namespace sg {

    TransformTraverser::TransformTraverser(const Geometry *ref, const Geometry *obj)
    : ref(ref)
    , obj(obj)
    , Traverser()
    {
        foundObj = false;
        foundRef = false;
        //transToObj = new Transformation();
        //invTransToRef = new Transformation();
        //memset(transMat, 0, sizeof(transMat));
        //memset(transInvMat, 0, sizeof(transInvMat));
    }
    
    TransformTraverser::~TransformTraverser()
    {
        ref = NULL;
        obj = NULL;
        /*if (transToObj) {
            delete transToObj;
            transToObj = NULL;
        }
        if (invTransToRef) {
            delete invTransToRef;
            invTransToRef = NULL;
        }*/
    }
    
    void TransformTraverser::visit(Transformation *trans)
    {
        if (!foundRef) {
            multInvMat( trans->getInvMatrix() );
        }
        if (!foundObj) {
            multMat(trans->getMatrix());
        }
        traverseChildrenNodes(tmpNode);
        if(!foundRef) {
            multInvMat( trans->getMatrix() );	
        }
        if(!foundObj) {
            multMat(trans->getInvMatrix());
        }
    }
    
    void TransformTraverser::visit(Geometry *geom)
    {
        if (geom==ref) {
            foundRef = true;
        }
        if (geom==obj) {
            foundObj = true;
        }
    }
    
    void TransformTraverser::visit(Group *grp)
    {
        traverseChildrenNodes(tmpNode);
    }
    
    void TransformTraverser::multInvMat(GLdouble* currentTransform) {
		glPushMatrix();
		glLoadMatrixd(currentTransform);
		glMultMatrixd(invTransToRef.getInvMatrix());
		glGetDoublev(GL_MODELVIEW_MATRIX, invTransToRef.getInvMatrix());
		glPopMatrix();
	}
    
    void TransformTraverser::multMat(GLdouble* currentTransform) {
		glPushMatrix();
		glLoadMatrixd(transToObj.getMatrix());
		glMultMatrixd(currentTransform);
		glGetDoublev(GL_MODELVIEW_MATRIX, transToObj.getMatrix());
		glPopMatrix();
	}
    
    Transformation* TransformTraverser::getTransFromRefToObj()
    {
        Transformation *ret = new Transformation();
        ret->mult(invTransToRef.getInvMatrix());
        ret->mult(transToObj.getMatrix());
        return ret;
    }
}