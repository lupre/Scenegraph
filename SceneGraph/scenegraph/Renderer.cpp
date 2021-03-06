#include "Renderer.h"

#include <sstream>
#include "ObserverGeometry.h"

namespace sg
{
using namespace std;

long Renderer::lastTime = 0;
int counter = 0;
long lastFPS = 0;
long inDisplay = 0;

Renderer::Renderer(const string& windowTitle, int width, int height)
 : title(windowTitle){
 	this->width = width;
 	this->height = height;
}

Renderer::~Renderer()
{
}

Node* Renderer::root(0);
    
int Renderer::height = 0;
int Renderer::width = 0;

SGInput Renderer::sgInput;

void Renderer::init(int argc, char** argv) const {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow(title.c_str());
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutKeyboardUpFunc(keyboardUp);	
	glutSpecialFunc(specialKey);
	glutSpecialUpFunc(specialKeyUp);
	
	// OpenGL state machine initialization
	glClearColor(0.5,0.5,0.5,0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
  	glEnable(GL_LIGHTING);
  	glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
}

void Renderer::startRendering(Node* n) {
    //tt = t;
	root = n;
	lastTime = glutGet(GLUT_ELAPSED_TIME);
	lastFPS = lastTime;
	glutMainLoop();
}

void Renderer::display() {
	long enterTime = glutGet(GLUT_ELAPSED_TIME);
	glClear(GL_DEPTH_BUFFER_BIT|GL_COLOR_BUFFER_BIT);
	
	double elapsed = (double)(enterTime - lastTime) / 1000.0;
	lastTime = enterTime;
	
	Animation::updateAllAnimation(elapsed);
	BehaviorCore::updateAllBehaviors(&sgInput, elapsed);
    ObserverGeometry::updateAll();
	long leaveTime = glutGet(GLUT_ELAPSED_TIME);
    
    // get Trans from ref to obj
    //Traverser* tt = new TransformTraverser(ref, obj);
    //tt->visit(root);
    //TransformTraverser* tt2 = dynamic_cast<TransformTraverser*>(tt);
    //Transformation *trans = tt2->getTransFromRefToObj();
    //ref->update(trans);
    
	Traverser* ct = new CameraTraverser;
	ct->visit(root);
	GLdouble camMatrix [16];
	((CameraTraverser*) ct)->getMatrix(camMatrix);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glMultMatrixd(camMatrix);
	glPushMatrix();
	Traverser* lt = new LightTraverser;
	lt->visit(root);
	glPopMatrix();
	
	Traverser* rt = new RenderTraverser;
	rt->visit(root);
		
	glutSwapBuffers();
	
	counter++;
//	long leaveTime = glutGet(GLUT_ELAPSED_TIME);
	inDisplay += (leaveTime - enterTime);
	if((leaveTime - lastFPS) > 10000) {
	//if(counter == 100) {
		cout <<  counter << " frames in: " << (leaveTime - lastFPS) << " ms = " << (counter*1000./(leaveTime - lastFPS)) << " FPS" <<  endl;
		cout << "Davon für Aktualisierung: " << inDisplay << " ms"<< endl;
		lastFPS = leaveTime;
		counter = 0;
		inDisplay = 0;
	}
    delete ct;
    delete lt;
    delete rt;
    //delete tt;
}

void Renderer::idle() {
	glutPostRedisplay();
}

void Renderer::keyboard(unsigned char key, int x, int y) {
	if(key == '\33') {
		exit(0);	
	}
	sgInput.addKey(key);
}

void Renderer::keyboardUp(unsigned char key, int x, int y) {
	sgInput.removeKey(key);
}

void Renderer::specialKey(int key, int x, int y) {
	sgInput.addSpecialKey(key);
}

void Renderer::specialKeyUp(int key, int x, int y) {
	sgInput.removeKey(key);
}

void Renderer::reshape(int w, int h) {
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if(h == 0)
		h = 1;

	float ratio = 1.0* (double)w / (double)h;

	// Reset the coordinate system before modifying
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);
	// Set the correct perspective.
	gluPerspective(45,ratio,0.01,1000);
	glMatrixMode(GL_MODELVIEW);
}

Node* Renderer::getRoot()
{
    return root;
}

}
