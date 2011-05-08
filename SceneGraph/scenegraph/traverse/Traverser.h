#ifndef TRAVERSER_H_
#define TRAVERSER_H_
#include "../Node.h"

namespace sg
{
		//using namespace sg;
		class Traverser
		{
		public:
			Traverser();
			virtual ~Traverser();
			virtual void visit(Node* n)=0;
		};
		
		//template<class Node>
		class Visitable : public Node {
			public:
				Visitable() : Node () {};
				
				void accept(Traverser& v) {v.visit(this);}	
		};
		
		typedef Visitable VNode;
}

#endif /*TRAVERSER_H_*/
