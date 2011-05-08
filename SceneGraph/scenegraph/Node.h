#ifndef NODE_H_
#define NODE_H_
#include <vector>
#include "Core.h"

//#include "Geometry.h"
//#include "Transformation.h"
//#include "Group.h"
//#include "Light.h"

using namespace std;

namespace sg {
	
	/**
 	 * Implements a scenegraph node. Contains children nodes and cores which specify the
 	 * kind of the node.
 	 */
	class Node
	{	
		vector<Node*> children; ///<
		Core* core; ///<
	 
	public:
		/** Simple constructor  */
		Node();
		/** Simple destructor */
		virtual ~Node();
		
		/**
		 * Adds a node to the children list.
		 */
		void addChild(Node*);

		/**
		 * Removes the given node from the childrens list.
		 */
		void removeChild(Node*);
		
		/**
		 * Checks if the given node is contained in the children lsit.
		 */
		bool containsChild(Node*);
		
		/**
		 * Returns the vector with all children nodes.
		 */
		vector<Node*>* getAllChildren();
		
		/**
		 * Sets the member core to the given Core pointer.
		 */
		void setCore(Core*);
		
		/**
		 * Returns the member core.
		 */
		Core* getCore();
		
	};

}
#endif /*NODE_H_*/
