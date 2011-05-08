#include "Teapot.h"

namespace sg
{

Teapot::Teapot(char* labelStr):Geometry(labelStr)
{
}

Teapot::~Teapot()
{
}

void Teapot::draw() {
	glutSolidTeapot(1);	
}

}
