#ifndef MATERIAL_H_
#define MATERIAL_H_

//#include <GL/gl.h>
//#include <GL/glut.h>
#import <OpenGL/OpenGL.h>
#import <GLUT/glut.h>


#define NUM_OF_FIELDS 4
namespace sg {
/**
 * Material class. Contains information about the color-parts and the shininess.
 */	
class Material
{
	float diffuse [NUM_OF_FIELDS]; ///< diffuse part of color
	float ambient [NUM_OF_FIELDS]; ///< ambient part of color
	float specular [NUM_OF_FIELDS]; ///< specular part of color
	float emission  [NUM_OF_FIELDS]; ///< emissive part of color
	float shininess; ///< shininess of material
	
	/**
	 * Copies the values of one array to another.
	 */
	void copyFields(float*, float*, int);
	
	/**
	 * Initilizes a float array of a given size with a given float value.
	 */
	void initialize(float*, float, int);
	
public:
	/** Simple constructor */
	Material();
	
	/** Simple destructor */
	virtual ~Material();
	
	/**
	 * Applies the spedified values to the OpenGL state machine
	 */
	void apply();
	
	/**
 	* Expects an float array with four fields. 
 	*/
	void setDiffuse(float* color);
	
	/**
 	* Expects an float array with four fields. 
 	*/
	void getDiffuse(float* color);
	
	/**
 	* Expects an float array with four fields. 
 	*/
	void setAmbient(float* color);
	
	/**
 	* Expects an float array with four fields. 
 	*/
	void getAmbient(float* color);
	
	/**
 	* Expects an float array with four fields. 
 	*/
	void setSpecular(float* color);
	
	/**
 	* Expects an float array with four fields. 
 	*/
	void getSpecular(float* color);
	
	/**
 	* Expects an float array with four fields. 
 	*/
	void setEmission(float* color);
	
	/**
 	* Expects an float array with four fields. 
 	*/
	void getEmission(float* color);
	
	/**
	 * Exponent for the specular part.
	 */
	void setShininess(float value);
	
	/**
	 * Returns the exponent for the specular part.
	 */
	float getShininess();
};
}

#endif /*MATERIAL_H_*/
