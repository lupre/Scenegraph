#ifndef CORE_H_
#define CORE_H_
//#include <GL/gl.h>
#import <OpenGL/OpenGL.h>


namespace sg {
/**
 * This class defines a core of a scenegraph node. Possible core my be geometry cores, 
 * transformation cores, light cores and so on.
 */
class Core
{
public:
	/** Simple constructor */
	Core();
	/** Simple destructor */
	virtual ~Core();	
};

} // namespace sg
#endif /*CORE_H_*/
