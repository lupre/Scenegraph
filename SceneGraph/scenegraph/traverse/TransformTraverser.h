//
//  TransformTraverser.h
//  SceneGraph
//
//  Created by Lukas on 20.04.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef _TRANSFORM_TRAVERSER_H_
#define _TRANSFORM_TRAVERSER_H_

#include "../VCore.h"
#include "Geometry.h"
#include "Transformation.h"

#define MAT_SIZE 16

namespace sg {
    class TransformTraverser : public Traverser
    {
    public:
        TransformTraverser(const Geometry *ref, const Geometry *obj);
        virtual ~TransformTraverser();
        
        /**
         * This method overrides the method `visit(Transformation*)` from the class 
         * Traverser. It stores the inverse transformation within a matrix. 
         */
        void visit(Transformation*);
        /**
         * This method overrides the method `visit(Geometry*)` from the class Traverser.
         * It initiates the drawing of the given Geometry object.
         */
        void visit(Geometry*);
        /**
         * This method overrides the method `visit(Group*)` from the class Traverser.
         * It calls the method `traverseChildrenNodes(Node*)` to continue the traversion.
         */
        void visit(Group*);
        
        void multMat(GLdouble* currentTransform);
        void multInvMat(GLdouble* currentTransform);
        Transformation* getTransFromRefToObj();
        
    private:
        bool foundRef;
        bool foundObj;
        Transformation invTransToRef;
        Transformation transToObj;
        const Geometry* obj;
        const Geometry* ref;
        //double transMat[MAT_SIZE];
        //double transInvMat[MAT_SIZE];
    };
}

#endif