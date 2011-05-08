#ifndef VCORE_H_
#define VCORE_H_

#include "Core.h"
#include "Node.h"

namespace sg {
// forward declarations
class Transformation;
class Group;
class Camera;
class Light;
class Geometry; 	
 	
 	/**
	 * The class Traverser implements the traversing of the scenegraph using 
	 * the Visitor pattern. Therefore this file also defines the class Visitable
	 * which inherits from the Node class. The class Traverser is abstract!
	 * The mechanism is used by RenderTraverser, CameraTraverser or LightTraverser.
	 */
	class Traverser
	{
	public:
		/**
		 * A simple constructor which does nothing.
		 */
		Traverser();
		virtual ~Traverser();
		
		/**
		 * Visits the Core object of the given Node object. 
		 */
		virtual void visit(Node* n);
		
		/**
		 * Performs no action. Concrete actions should be implemented by inheritors. 
		 */
		virtual void visit(Core* n);
		
		/**
		 * Performs no action. Concrete actions should be implemented by inheritors. 
		 */
		virtual void visit(Transformation* t);
		
		/**
		 * Performs no action. Concrete actions should be implemented by inheritors. 
		 */
		virtual void visit(Light* l);
		
		/**
		 * Performs no action. Concrete actions should be implemented by inheritors. 
		 */
		virtual void visit(Geometry* g);
		
		/**
		 * Performs no action. Concrete actions should be implemented by inheritors. 
		 */
		virtual void visit(Camera* c);
		
		/**
		 * Performs no action. Concrete actions should be implemented by inheritors. 
		 */
		virtual void visit(Group* g);
			
	protected:
		/**
		 * Continues the traversion on child nodes.
		 */
		void traverseChildrenNodes(Node* n);
		
		/**
		 * Required temporary node while traversion.
		 */
		Node* tmpNode;
	};
	
	/**
	 * This class implements a visitable Core which can be used in conjunction with
	 * the Traverser class. All inheriting classes can be used to be visited by an 
	 * instance of Traverser or its inheritors.
	 */
	class VCore : public Core {
 		public:
 		/** Simple constructor */
 		VCore() : Core () {}
 		
 		/**
 		 * Method `accept` which is part of the visitor pattern. Accepts a reference 
 		 * of a Traverser object and calls its `visit` method. 
 		 */
 		virtual void accept(Traverser& t) {t.visit(this);}	
 	};
};

#endif /*VCORE_H_*/
