#include "Camera.h"

namespace sg {
	
Camera::Camera()
{
}

Camera::~Camera()
{
}

void Camera::accept(Traverser& t) {
	t.visit(this);	
}

}
