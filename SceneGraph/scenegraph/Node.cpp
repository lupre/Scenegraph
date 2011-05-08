#include "Node.h"
#include <iostream>

using namespace std;

namespace sg {
	Node::Node()
	{
	}
	
	Node::~Node()
	{
	}
	
	void Node::addChild(Node* node) {
		children.push_back(node);	
	}
	
	bool Node::containsChild(Node* node) {
		vector<Node*>::iterator iter = children.begin();
		while(iter < children.end()) {
			if(*iter == node) {
				return true;	
			}
			iter++;	
		}
		return false;	
	}
	
	void Node::removeChild(Node* node) {
		vector<Node*>::iterator iter = children.begin();
		while(iter < children.end()) {
			if(*iter == node) {
				children.erase(iter);	
			}
			iter++;	
		}	
	}
	
	vector<Node*>* Node::getAllChildren() {
		return &children;	
	}
	
	void Node::setCore(Core* core) {
		this->core = core;	
	}
	
	Core* Node::getCore() {
		return core;	
	}

}
