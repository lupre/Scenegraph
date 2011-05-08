#include "Transformation.h"
#include <iostream>

using namespace std; 

namespace sg {
void Transformation::setIdentity() {
	setMatrixElemToNull();
	matrix[0] = 1; matrix[5] = 1; matrix[10] = 1; matrix[15] = 1;
	invMatrix[0] = 1; invMatrix[5] = 1; invMatrix[10] = 1; invMatrix[15] = 1;
}

void Transformation::setMatrixElemToNull() {
	for(int i = 0; i < MAT_SIZE; i++) {
		matrix[i] = 0;
		invMatrix[i] = 0;	
	}	
}

void Transformation::translate(GLdouble x, GLdouble y, GLdouble z) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadMatrixd(matrix);
	glTranslatef(x,y,z);
	glGetDoublev(GL_MODELVIEW_MATRIX, matrix);
	glLoadIdentity();
	glTranslatef(-x, -y, -z);
	glMultMatrixd(invMatrix);
	glGetDoublev(GL_MODELVIEW_MATRIX, invMatrix);
	glPopMatrix();
}

void Transformation::rotate(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadMatrixd(matrix);
	glRotatef(angle, x, y, z);
	glGetDoublev(GL_MODELVIEW_MATRIX, matrix);
	glLoadIdentity();
	glRotatef(-angle, x, y, z);
	glMultMatrixd(invMatrix);
	glGetDoublev(GL_MODELVIEW_MATRIX, invMatrix);
	glPopMatrix();	
}

void Transformation::scale(GLdouble x, GLdouble y, GLdouble z) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadMatrixd(matrix);
	glScalef(x, y, z);
	glGetDoublev(GL_MODELVIEW_MATRIX, matrix);
	glLoadIdentity();
	glScalef(1/x, 1/y, 1/z);
	glMultMatrixd(invMatrix);
	glGetDoublev(GL_MODELVIEW_MATRIX, invMatrix);
	glPopMatrix();
}

void Transformation::setMatrix(const GLdouble* newMatrix) {
	memcpy(matrix, newMatrix, 16 * sizeof(GLdouble));	
}

void Transformation::setInvMatrix(const GLdouble* newMatrix) {
	memcpy(invMatrix, newMatrix, 16 * sizeof(GLdouble));	
}

void Transformation::multInv(const GLdouble * newMatrix) {
	performMultiplikation(invMatrix, newMatrix);
}

void Transformation::mult(const GLdouble* newMatrix) {
	performMultiplikation(matrix, newMatrix);
}

void Transformation::performMultiplikation(GLdouble* currMatrix, const GLdouble* newMatrix) {
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadMatrixd(currMatrix);
	glMultMatrixd(newMatrix);
	glGetDoublev(GL_MODELVIEW_MATRIX, currMatrix);
	glPopMatrix();	
}

void Transformation::applyTransformation() {
	glMultMatrixd(matrix);	
}

Transformation::Transformation()
{
	setIdentity();
}

GLdouble* Transformation::getInvMatrix() {
	return invMatrix;	
}

GLdouble* Transformation::getMatrix() {
	return matrix;	
}

Transformation::~Transformation()
{
}

void Transformation::accept(Traverser &t) {
	t.visit(this);	
}

}
