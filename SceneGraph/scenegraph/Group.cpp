#include "Group.h"

namespace sg {

Group::Group()
{
}

Group::~Group()
{
}

void Group::accept(Traverser& t) {
	t.visit(this);	
}

}
