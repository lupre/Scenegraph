#include "RenderTraverser.h"

namespace sg {

		RenderTraverser::RenderTraverser()
		{
		}
		
		RenderTraverser::~RenderTraverser()
		{
		}
		
		void RenderTraverser::visit(Transformation* t) {
			glPushMatrix();
			t->applyTransformation();
			traverseChildrenNodes(tmpNode);
			glPopMatrix();
		}
		
		void RenderTraverser::visit(Geometry* g) {
			g->drawWithMaterial();
		}
		
		void RenderTraverser::visit(Group* g) {
			traverseChildrenNodes(tmpNode);
		}
}
