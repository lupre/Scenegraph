#ifndef LIGHT_H_
#define LIGHT_H_

//#include <GL/gl.h>
//#include <GL/glut.h>
#import <OpenGL/OpenGL.h>
#import <GLUT/glut.h>

#include "VCore.h"

#define NUM_LIGHT_IDS 8
#define COLOR_SIZE 4
#define POS_SIZE 4


namespace sg {
/**
 * Implementation of a light core. Abstract class for concrete subclasses like PointLight.
 */
class Light : public VCore
{
public:
	/**
	 * Constructor. Initializes the light color to white and allocates a free light 
	 * number. Only 8 Lights are possible!
	 */
	Light();
	/** Simple destructor */
	virtual ~Light();
	
	/**
	 * This method is used apply the light settings to the OpenGL state machine.
	 */
	virtual void enable()=0;
	
	/**
	 * This method is used to draw a white sphere at the place of the light.
	 */
	virtual void drawLightGeom();
	
	/**
	 * Sets the ambient color to color; Expects an array with four fields.
	 */
	void setColorAmbient(float* color);
	
	/**
	 * Copies the ambient color to color; Expects an array with four fields.
	 */
	void getColorAmbient(float* color);
	
	/**
	 * Sets the diffuse color to color; Expects an array with four fields.
	 */
	void setColorDiffuse(float* color);
	
	/**
	 * Copies the diffuse color to color; Expects an array with four fields.
	 */
	void getColorDiffuse(float* color);
	
	/**
	 * Sets the specular color to color; Expects an array with four fields.
	 */
	void setColorSpecular(float* color);
	
	/**
	 * Copies the specular color to color; Expects an array with four fields.
	 */
	void getColorSpecular(float* color);
	
	/**
	 * Sets the attenuation to value.
	 */
	void setAttenuation(float value);
	
	/**
	 * Returns the attenuation.
	 */
	float getAttenuation();
	
	/**
	 * Sets the member position to position; Expects an array with four fields.
	 */
	void setPosition(float* position);
	
	/**
	 * Copies the member position to position; Expects an array with four fields.
	 */
	void getPosition(float* position);
	
	/**
	 * Calls the method `visit` of the given Traverser object.
	 */
	virtual void accept(Traverser& t);
	
private:
	/**
	 * Initializes arr with value. Length of arr is defiend by size.
	 */
	void initialize(float* arr, int size, float value);
	
	static unsigned int counter; ///< current light id counter
	
	static unsigned int lightIDs[]; ///< possible light ids

protected:	
	unsigned int num; ///< light number for OpenGL
	float attenuation; ///< atteanaution
	float diffuse[COLOR_SIZE]; ///< diffuse color
	float ambient[COLOR_SIZE]; ///< ambient color
	float specular[COLOR_SIZE]; ///< specular color
	float position[POS_SIZE]; ///< position
};
}
#endif /*LIGHT_H_*/
