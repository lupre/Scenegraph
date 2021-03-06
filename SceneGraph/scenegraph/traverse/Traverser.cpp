#include "../VCore.h"

#include "iostream"

using namespace std;

namespace sg
{
		Traverser::Traverser()
		{
		}
	
		Traverser::~Traverser()
		{
		}
		
		void Traverser::traverseChildrenNodes(Node* node) {
//			cout << "Kinder werden verarbeitet!" << endl;
			for(unsigned int i = 0; i < node->getAllChildren()->size(); i++) {
				Node* child = (*(node->getAllChildren()))[i];
				visit(child);
			}
		}
		
		void Traverser::visit(Core* c) {}
		
		void Traverser::visit(Group* g) {}	
		
		void Traverser::visit(Node* node) {
//			cout << "Node wird verarbeitet!" << endl;
			tmpNode = node;
			VCore* c = dynamic_cast<VCore*> (node->getCore());
			c->accept(*this);
		}
		
		void Traverser::visit(Camera* c) {}
		
		void Traverser::visit(Transformation* t) {
//			cout << "Traverser besucht Transformation" << endl;
		}
		
		void Traverser::visit(Geometry* g) {}
		
		void Traverser::visit(Light* l) {}
    
    
}
