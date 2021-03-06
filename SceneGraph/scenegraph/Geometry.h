#ifndef GEOMETRY_H_
#define GEOMETRY_H_
//#include <GL/gl.h>
#import <OpenGL/OpenGL.h>
#import <GLUT/glut.h>
//#include <GL/glut.h>
#include <iostream>

#include "VCore.h"
#include "Material.h"
#include "CoordSys.h"
#include "Transformation.h"


namespace sg {

class Geometry : public VCore
{
/**
 * Implementation of a geometry core. This core contains a pointer to Material object 
 * which specifies the appearance of the object.
 */	
public:
	/** Simple constructor */
	Geometry(char* labelStr);
	/** Simple destructor */
	virtual ~Geometry();
	
	/**
	 * Applies the setting of the material attributes and calls then the method draw(). 
	 */
	void drawWithMaterial();
	
	/**
	 * Is used to draw the concrete object. Has to be implemented within a concrete 
	 * subclass.
	 */
	virtual void draw()=0;
	
	/**
	 * Set the member material to the parameter's value.
	 */
	void setMaterial(Material*);
	
	/**
	 * Returns the member material.
	 */
	Material* getMaterial();
	
	/**
	 * Calls the method `visit` of the given Traverser object.
	 */
	virtual void accept(Traverser& t);
    
    //void update(Transformation* trans);

private:
	Material* material; ///< contains information about appearance of the object
    CoordSys* coordSys; // visual representation of a coordiante system TODO: Better use a static method to draw the CoordSys as instantiate for each Geometry one of its own. 

//protected:
//    Transformation* transToRemote;
};

}// namespace sg
#endif /*GEOMETRY_H_*/
