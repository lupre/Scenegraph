#include "Sphere.h"

namespace sg {
	
Sphere::Sphere(char* labelStr):Geometry(labelStr)
{
}

Sphere::~Sphere()
{
}

void Sphere::draw() {
	glutSolidSphere(RADIUS, S_SLICES, S_STACKS);	
}

}