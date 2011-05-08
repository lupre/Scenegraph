#ifndef CAMERATRAVERSER_H_
#define CAMERATRAVERSER_H_

#include "../VCore.h"
#include "../Camera.h"
#include "../Transformation.h"

#define MAT_SIZE 16

namespace sg
{

/**
 * This class searches for the Camera within the scenegraph by traversing it. The 
 * result is the inverse camera transformation. 
 * It extends the Traverser class. 
 */
class CameraTraverser : public Traverser
{
public:
	CameraTraverser();
	virtual ~CameraTraverser();
	/**
	 * Returns the inverse transformation of the camera. The computed transformation 
	 * matrix is copied to the given pointer address.
	 * @param tmp a pointer to a GLdouble array with 16 fields. 
	 */
	void getMatrix(GLdouble* tmp);
	
	/**
	 * This method overrides the method `visit(Node*)` from the class Traverser.
	 * @see Traverser
	 */
	void visit(Node* node);

	/**
	 * This method overrides the method `visit(Camera*)` from the class Traverser.
	 * After this method is called the traversion is stopped. 
	 */
	void visit(Camera* c);
	
	/**
	 * This method overrides the method `visit(Transformation*)` from the class 
	 * Traverser. It stores the inverse transformation within a matrix. 
	 */
	void visit(Transformation* t);
	
	/**
	 * This method overrides the method `visit(Group*)` from the class Traverser.
	 * It calls the method `traverseChildrenNodes(Node*)` to continue the traversion.
	 */
	void visit(Group* g);
	
	/**
	 * This method overrides a method from Traverser. It continues the traversion.
	 */
	void traverseChildrenNodes(Node* node);
	

private:
	Transformation* camTransform; ///< holds transformation to the camera node
	bool foundCam; ///< signalizes if camera was found
	
	/**
	 * This method multiplies the given matrix from left side to the existing 
	 * camera transformation matrix.
	 * @param currentTransform is a pointer to the current trasformation matrix.
	 */
	void multInv(GLdouble* currentTransform);
	
};

}

#endif /*CAMERATRAVERSER_H_*/
