//
//  ObserverCore.h
//  SceneGraph
//
//  Created by Lukas on 28.04.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef _OBSERVER_CORE_H_
#define _OBSERVER_CORE_H_

#include "Geometry.h"
#include "Transformation.h"
#include <vector.h>

namespace sg {

typedef struct GeomTrans {
    const Geometry* geom;
    Transformation* trans;
} GeomTrans_t;
    

class ObserverGeometry : public Geometry
{
public:
    ObserverGeometry(char* labelStr);
    virtual ~ObserverGeometry();
    
    static void updateAll();
    void update();
    virtual void addGeometryForObservation(const Geometry* geom);
    
protected:
    std::vector<GeomTrans_t> geomList;
private:
    static std::vector<ObserverGeometry*> observerList;
    
};

}

#endif