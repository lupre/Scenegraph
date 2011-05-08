#ifndef TRANSFORMATION_H_
#define TRANSFORMATION_H_

#include "VCore.h"
//#include "traverse/Traverser.h"
#include <cstring>

/** \define size of the matrix (4x4)*/
#define MAT_SIZE 16

namespace sg {

/**
 * This class implements a static transformation core. It consits of two matrizes which
 * in their part contain the normal and inverse transformation.
 */	
class Transformation : public VCore
{
	
public:
	/**
	 * Calls setIdentity().
	 */
	Transformation();
	
	/** Simpledestructor */
	virtual ~Transformation();
	
	/**
	 * Sets the normal and inverse transfromation matrix to the Identity matrix.
	 */
	void setIdentity();
	
	/**
	 * Applies a right side multiplication of a rotation transformation matrix to 
	 * the existing transformation matrix. Afterwards a left side multiplication of
	 * the inverse rotation matrix to the existing inverse transfromation matrix is 
	 * done. 
	 */
	void rotate(GLdouble angle, GLdouble x, GLdouble y, GLdouble z);
	
	/**
	 * Applies a right side multiplication of a translation transformation matrix to 
	 * the existing transformation matrix. Afterwards a left side multiplication of
	 * the inverse translation matrix to the existing inverse transfromation matrix is 
	 * done.
	 */
	void translate(GLdouble x, GLdouble y, GLdouble z);
	
	/**
	 * Applies a right side multiplication of a scale transformation matrix to 
	 * the existing transformation matrix. Afterwards a left side multiplication of
	 * the inverse scale matrix to the existing inverse transfromation matrix is 
	 * done.
	 */
	void scale(GLdouble x, GLdouble y, GLdouble z);
	
	/**
	 * Sets the member matrix to the values of the given matrix. Requires also a call 
	 * of setInvMatrix() because it does not invert the given matrix automatically.
	 */
	void setMatrix(const GLdouble* newMatrix);
	
	/**
	 * Sets the member invMatrix to the values of the given matrix. Requires also a call 
	 * of setMatrix().
	 */
	void setInvMatrix(const GLdouble* newMatrix);
	
	/**
	 * Performs a right side multiplication of two 4x4 matrizes. The left matrix is the
	 * member matrix. The right matrix is newMatrix.
	 */
	void mult(const GLdouble* newMatrix);
	
	/**
	 * Performs a left side multiplication of two 4x4 matrizes. The left matrix is 
	 * newMatrix. The right matrix is the member invMatrix.
	 */
	void multInv(const GLdouble* newMatrix);
	
	/**
	 * Applies the member matrix to the OpenGL matrix stack.
	 */
	void applyTransformation();
	
	/**
	 * Returns a pointer to the inverse transformation matrix.
	 */
	GLdouble* getInvMatrix();
	
	/**
	 * Returns a pointer to the transfromation matrix.
	 */
	GLdouble* getMatrix();
	
	/**
	 * Calls the method `visit` of the given Traverser object.
	 */
	virtual void accept(Traverser& t);

protected:
	GLdouble matrix[16]; ///< holds the normal transformation
	GLdouble invMatrix[16]; ///< holds the inverse transformation
	
private:
	/**
	 * Helper methode which sets all elements of the members matrix and invMatrix
	 * to the value 0.
	 */
	void setMatrixElemToNull();
	
	/**
	 * Performs a multiplication of the two given matrizes in the order they are given.
	 */
	void performMultiplikation(GLdouble* currMatrix, const GLdouble* newMatrix);
};
}
#endif /*TRANSFORMATION_H_*/
