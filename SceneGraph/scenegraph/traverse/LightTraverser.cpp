#include "LightTraverser.h"

namespace sg
{

	LightTraverser::LightTraverser(){}

	LightTraverser::~LightTraverser(){}

	void LightTraverser::visit(Light* l) {
		l->enable();
		l->drawLightGeom();
	}
	
	void LightTraverser::visit(Group* g) {
		traverseChildrenNodes(tmpNode);	
	}
	
	void LightTraverser::visit(Transformation* t) {
		glPushMatrix();
		t->applyTransformation();
		traverseChildrenNodes(tmpNode);
		glPopMatrix();
	}
}
