#ifndef RENDERER_H_
#define RENDERER_H_
#include <string>
#include "traverse/RenderTraverser.h"
#include "traverse/CameraTraverser.h"
#include "traverse/LightTraverser.h"
#include "TransformTraverser.h"
#include "VCore.h"
#include "behavior/SGInput.h"
#include "behavior/BehaviorCore.h"
#include "Animation.h"
#include "Node.h"

namespace sg
{
	
using namespace std;

/**
 * This class is used to initialize the desired OpenGL state, create a window, handle 
 * the keyboard and mouse input and render a given scene.
 */
class Renderer
{
public:
	/**
	 * Initializes the widowTitle and the with and height of the window.
	 */
	Renderer(const string& windowTitle, int width, int height);
	/** Simple destructor */
	virtual ~Renderer();
	
	/**
	 * Initializes the desired OpenGL state
	 */
	void init(int argc, char** argv) const;
	
	/**
	 * Is called from glutMainLoop() to render the scene. Within this method, the 
	 * Animations and Behaviors are updated, the camera and lights are set and then
	 * the objects are drawn.
	 */
	static void display();
	
	/**
	 * Is called from glutMainLoop() when the window is resized. Within this method the
	 * viewport is reset and the projection matrix is updated.
	 */
	static void reshape(int w, int h);
	
	/**
	 * Calls glutPostRedisplay() to initiate a call to display().
	 */
	static void idle();
	
	/**
	 * Terminates the process if \ESC is pressed. Other keys are added to the member
	 * sgInput.
	 */
	static void keyboard(unsigned char key, int x, int y);
	
	/**
	 * Removes the released key from the member sgInput.
	 */
	static void keyboardUp(unsigned char key, int x, int y);
	
	/**
	 * Adds the pressed special key to the member sgInput.
	 */
	static void specialKey(int key, int x, int y);
	
	/**
	 * Removes the released special key from the member sgInput.
	 */
	static void specialKeyUp(int key, int x, int y);
    
    static Node* getRoot();
	
	/**
	 * Starts the rendering of the given scene. 
	 * \param n		root node of the scene
	 */
	void startRendering(Node* n);	
	
	/**
	 * Sets the width of the window.
	 */
	void setWidth(int width);
	
	/**
	 * Returns the width of the window.
	 */
	int getWidth();
	
	/**
	 * Sets the height of the window.
	 */
	void setHeight(int height);
	
	/**
	 * Returns the heigth of the window.
	 */
	int getHeight();
	
	/**
	 * Sets the title of the window.
	 */
	void setTitle(string tilte);
	
	/**
	 * Returns the title of the window.
	 */
	string getTitle();

private:
	static int width; ///< width of window
	static int height; ///< height of window
	string title; ///< title
	static Node* root; ///< root node of scene
	static long lastTime; ///< lastTime when display() was called
	static SGInput sgInput; ///< container for pressed keys
};

}
#endif /*RENDERER_H_*/
