#include "PointLight.h"

#include <iostream>

namespace sg {

using namespace std;
	
PointLight::PointLight() : Light()
{
	position[POS_SIZE-1] = 1.0;
}

PointLight::~PointLight()
{
}

void PointLight::enable() {
	glLightfv(num, GL_POSITION, position);
	glLightfv(num, GL_DIFFUSE, diffuse);
	glLightfv(num, GL_AMBIENT, ambient);
	glLightfv(num, GL_SPECULAR, specular);
	glEnable(num);	
}

}
