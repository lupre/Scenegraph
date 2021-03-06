#include "Material.h"

#include <iostream>

namespace sg {
	
using namespace std;

Material::Material()
{
	// initialize the ambient part (0.2, 0.2, 0.2, 1.0)
	initialize(ambient, 0.2, NUM_OF_FIELDS);
	ambient[NUM_OF_FIELDS-1] = 1.0;
	
	// initialize the diffuse part (1.0, 1.0, 1.0, 1.0)
	initialize(diffuse, 1.0, NUM_OF_FIELDS);
	
	// initialize the speular part (1.0, 1.0, 1.0, 1.0)
	initialize(specular, 1.0, NUM_OF_FIELDS);
	
	// initialize the emission part (0.0, 0.0, 0.0, 1.0)
	initialize(emission, 0.0, NUM_OF_FIELDS);
	emission[NUM_OF_FIELDS-1] = 1.0;
	
	// set shininess to 1.0
	shininess = 5.0;
}

Material::~Material()
{	
    // TODO: Why compiler-warning: Cannot delete expression of type 'float [4]'
//	delete ambient;
}

void Material::apply() {
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_EMISSION, emission);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);	
}

void Material::getAmbient(float* color) {
	copyFields(ambient, color, NUM_OF_FIELDS);
}

void Material::setAmbient(float* color) {
	copyFields(color, ambient, NUM_OF_FIELDS);
}

void Material::setDiffuse(float* color) {
	copyFields(color, diffuse, NUM_OF_FIELDS);	
}

void Material::getDiffuse(float* color) {
	copyFields(diffuse, color, NUM_OF_FIELDS);	
}

void Material::setSpecular(float* color) {
	copyFields(color, specular, NUM_OF_FIELDS);	
}

void Material::getSpecular(float* color) {
	copyFields(specular, color, NUM_OF_FIELDS);	
}

void Material::setEmission(float* color) {
	copyFields(color, emission, NUM_OF_FIELDS);
}

void Material::getEmission(float* color) {
	copyFields(emission, color, NUM_OF_FIELDS);	
}

void Material::setShininess(float value) {
	shininess = value;	
}

float Material::getShininess() {
	return shininess;	
}

void Material::copyFields(float* from, float* to, int num) {
	for(int i = 0; i < num; i++) {
		to[i] = from[i];	
	}
}

void Material::initialize(float* arr, float value, int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = value;
	}	
}

}