#include "Cone.h"

namespace sg {

Cone::Cone(char* labelStr):Geometry(labelStr)
{
}

Cone::~Cone()
{
}

void Cone::draw() {
	glutSolidCone(BASE,HEIGHT,SLICES,STACKS);	
}

}