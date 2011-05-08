#include "Geometry.h"

namespace sg {

Geometry::Geometry(char* labelStr)
{
    this->coordSys = new CoordSys(labelStr);
//    transToRemote = NULL;
    material = NULL;
}

Geometry::~Geometry()
{
}

void Geometry::setMaterial(Material* material) {
	this->material = material;	
}

Material* Geometry::getMaterial() {
	return material;	
}

void Geometry::drawWithMaterial() {
	if(material != NULL) {
		material->apply();
	}
    this->coordSys->draw();
	draw();
}

void Geometry::accept(Traverser& t) {
	t.visit(this);	
}
    
//void Geometry::update(Transformation *trans)
//{
//    transToRemote = trans;
//}

}
