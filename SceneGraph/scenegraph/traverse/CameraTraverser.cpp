#include "CameraTraverser.h"

namespace sg
{

	CameraTraverser::CameraTraverser() : Traverser()
	{
		camTransform = new Transformation();
		foundCam = false;
	}
	
	CameraTraverser::~CameraTraverser()
    {
        if(camTransform)
        {
            delete camTransform;
        }
    }
	
	void CameraTraverser::multInv(GLdouble* currentTransform) {
		glPushMatrix();
		glLoadMatrixd(currentTransform);
		glMultMatrixd(camTransform->getInvMatrix());
		glGetDoublev(GL_MODELVIEW_MATRIX, camTransform->getInvMatrix());
		glPopMatrix();
	}
	

	void CameraTraverser::visit(Camera* c) {
		foundCam = true;
	}
	
	void CameraTraverser::visit(Transformation* t) {
		multInv( t->getInvMatrix() );
			traverseChildrenNodes(tmpNode);
			if(!foundCam) {
				multInv( t->getMatrix() );	
			}
	}
	
	void CameraTraverser::visit(Group* g) {
		traverseChildrenNodes(tmpNode);	
	}
	
	void CameraTraverser::traverseChildrenNodes(Node* node) {
		for(unsigned int i = 0; i < node->getAllChildren()->size(); i++) {
			Node* child = (*(node->getAllChildren()))[i];
			visit(child);
			if(foundCam) {
				break;	
			}
		}
	}
	
	void CameraTraverser::visit(Node* node) {
		tmpNode = node;
		VCore* c = dynamic_cast<VCore*> (node->getCore());
		c->accept(*this);
	}
	
	void CameraTraverser::getMatrix(GLdouble* tmp) {
		memcpy(tmp, camTransform->getInvMatrix(), 16 * sizeof(GLdouble));
	}

}
