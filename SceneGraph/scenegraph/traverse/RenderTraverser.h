#ifndef RENDERTRAVERSER_H_
#define RENDERTRAVERSER_H_
#include "../VCore.h"
#include "../Transformation.h"
#include "../Geometry.h"

namespace sg {

		/**
 		 * This class is used to render all Geometries within the scenegraph with their
 		 * Material information. It extends the Traverser class.
 		 */
		class RenderTraverser : public Traverser
		{
		public:
			/** Simple constructor */
			RenderTraverser();
			/** Simple destructor */
			virtual ~RenderTraverser();

			/**
	 		 * This method overrides the method `visit(Transformation*)` from the class 
	 		 * Traverser. It stores the inverse transformation within a matrix. 
	 		 */
			void visit(Transformation*);
			/**
			 * This method overrides the method `visit(Geometry*)` from the class Traverser.
			 * It initiates the drawing of the given Geometry object.
			 */
			void visit(Geometry*);
			/**
	 		 * This method overrides the method `visit(Group*)` from the class Traverser.
	 		 * It calls the method `traverseChildrenNodes(Node*)` to continue the traversion.
	 		 */
			void visit(Group*);
		};

}
#endif /*RENDERTRAVERSER_H_*/
