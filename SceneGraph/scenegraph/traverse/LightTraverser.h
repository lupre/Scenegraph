#ifndef LIGHTTRAVERSER_H_
#define LIGHTTRAVERSER_H_

#include "../VCore.h"
#include "../Light.h"
#include "../Transformation.h"

namespace sg
{

/**
 * This class inherits from the class Traverser and implements the searching for
 * Light-Cores. If a Light-Core is found, it will be enabled and the color attributes
 * are set.
 * The LightTraverser has to be applied before RenderTraverser.
 */
class LightTraverser : public sg::Traverser
{
public:
	/** Simple constructor */
	LightTraverser();
	/** Simple destructor */
	virtual ~LightTraverser();

	/**
	 * This method overrides the method `visit(Transformation*)` from the class 
	 * Traverser. It stores the inverse transformation within a matrix. 
	 */
	void visit(Transformation* t);
	/**
	 * This method overrides a method from Traverser. It enables the light and sets
	 * the color and other attributes. 
	 */
	void visit(Light* l);
	/**
	 * This method overrides the method `visit(Group*)` from the class Traverser.
	 * It calls the method `traverseChildrenNodes(Node*)` to continue the traversion.
	 */
	void visit(Group* g);

};

}

#endif /*LIGHTTRAVERSER_H_*/
