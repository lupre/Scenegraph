//
//  ObserverGeometry.cpp
//  SceneGraph
//
//  Created by Lukas on 28.04.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "ObserverGeometry.h"
#include "Universe.h"

namespace sg {
    
    std::vector<ObserverGeometry*> ObserverGeometry::observerList;
    
    ObserverGeometry::ObserverGeometry(char* labelStr):Geometry(labelStr)
    {
        observerList.push_back(this);
    }
    
    ObserverGeometry::~ObserverGeometry()
    {
        std::vector<ObserverGeometry*>::iterator it = observerList.begin();
        for ( ; it!=observerList.end(); it++ )
        {
            if (*it == this) 
            {
                break;
            }
        }
        if (it!=observerList.end()) 
        {
            observerList.erase(it);
        } 
        else
        {
            // this should never happen
            // TODO: add appropriate error mechanism; to be defined 
        }
    
        std::vector<GeomTrans_t>::iterator itG = geomList.begin();
        for ( ; itG!=geomList.end(); itG++ ) {
            delete itG->trans;
            itG->trans = NULL;
            itG->geom = NULL;
        }
        geomList.clear();
    }
    
    void ObserverGeometry::updateAll()
    {
        std::vector<ObserverGeometry*>::iterator it = observerList.begin();
        for ( ; it!=observerList.end(); it++ )
        {    
            (*it)->update();
        }
    }

    void ObserverGeometry::update()
    {
        // ToDO: add implementation 
        const Universe* universe = Universe::getUniverseInstance();
        std::vector<GeomTrans_t>::iterator it = geomList.begin();
        for ( ; it!=geomList.end(); it++ )
        {
            delete it->trans;
            it->trans = NULL;
            it->trans = universe->getTransTo(this, it->geom);
        }
    }

    void ObserverGeometry::addGeometryForObservation(const Geometry *geom)
    {
        GeomTrans_t gt;
        gt.geom = geom;
        gt.trans = new Transformation();
        geomList.push_back(gt);
    }
}
