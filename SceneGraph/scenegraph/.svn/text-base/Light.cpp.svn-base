#include "Light.h"

#include <iostream>

namespace sg {
	
using namespace std;

unsigned int Light::lightIDs [] = {GL_LIGHT0, GL_LIGHT1, GL_LIGHT2, GL_LIGHT3, GL_LIGHT4, 
	GL_LIGHT5, GL_LIGHT6, GL_LIGHT7};

unsigned int Light::counter = 0;


Light::Light()
{
	if (counter < NUM_LIGHT_IDS) {	
		num = lightIDs[counter];
		counter++;
	}
	else {
		cout << "Zuviele Lichter definiert! \nEs werden lediglich 8 Lichter unterstützt." << endl;	
	}
	
	initialize(diffuse, COLOR_SIZE, 1.0);
	initialize(ambient, COLOR_SIZE, 0.0);
	ambient[COLOR_SIZE-1] = 1.0;
	initialize(specular, COLOR_SIZE, 1.0);
	initialize(position, POS_SIZE, 0.0);
}

Light::~Light()
{
}

void Light::setColorAmbient(float* color) {
	for(int i = 0; i < COLOR_SIZE; i++) {
		ambient[i] = color[i];	
	}
}

void Light::getColorAmbient(float* color) {
	for(int i = 0; i < COLOR_SIZE; i++) {
		color[i] = ambient[i];	
	}
}

void Light::setColorDiffuse(float* color) {
	for(int i = 0; i < COLOR_SIZE; i++) {
		diffuse[i] = color[i];	
	}
}

void Light::getColorDiffuse(float* color) {
	for(int i = 0; i < COLOR_SIZE; i++) {
		color[i] = diffuse[i];	
	}
}

void Light::setColorSpecular(float* color) {
	for(int i = 0; i < COLOR_SIZE; i++) {
		specular[i] = color[i];	
	}
}

void Light::getColorSpecular(float* color) {
	for(int i = 0; i < COLOR_SIZE; i++) {
		color[i] = specular[i];	
	}
}

void Light::setPosition(float* position) {
	for(int i = 0; i < POS_SIZE; i++) {
		this->position[i] = position[i];	
	}
}

void Light::getPosition(float* position) {
	for(int i = 0; i < POS_SIZE; i++) {
		position[i] = this->position[i];	
	}
}

void Light::setAttenuation(float value) {
	this->attenuation = value;	
}

float Light::getAttenuation() {
	return this->attenuation;	
}

void Light::initialize(float* arr, int size, float value) {
	for (int i = 0; i < size; ++i) {
		arr[i] = value;
	}	
}

void Light::drawLightGeom() {
	glDisable(GL_LIGHTING);
	glColor3f(1,1,1);
	glutSolidSphere(1, 12, 6);
	glEnable(GL_LIGHTING);
}

void Light::accept(Traverser& t) {
	t.visit(this);	
}

}
