
#include "Cube.h"
#include <iostream>

using namespace std;

namespace sg {
	
    Cube::Cube(char* labelStr):Geometry(labelStr)
    {
    }
    
    Cube::~Cube()
    {
    }
    
    void Cube::draw() {
        glutSolidCube(SIZE);
    }
    
}
