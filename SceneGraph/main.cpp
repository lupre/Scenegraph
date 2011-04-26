//#include <GL/gl.h>
//#include <GL/glut.h>
#import <OpenGL/OpenGL.h>
#include <iostream>

#include "scenegraph/SceneGraph.h"
#include "vecalg/Vector3d.h"
#include "TransformTraverser.h"

#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT 200

using namespace std;
using namespace sg;

Node* root;
long lastTime;
Geometry* nobj;
Geometry* nref;

void genARScene(Node* root){
	// Root als Gruppe
	Core* rootCore = new Group();
	root->setCore(rootCore);

    // iPhone
    Node* iPhoneNode = new Node();
    iPhone* iPhoneGeo = new iPhone("iPhone");
    nref = iPhoneGeo;
    Material* iPhoneMat = new Material();
    float iPhoneColor[] = {0.2f, 0.2f, 0.2f, 0};
    iPhoneMat->getDiffuse(iPhoneColor);
    iPhoneGeo->setMaterial(iPhoneMat);
    iPhoneNode->setCore(iPhoneGeo);
    
    Node* iPhoneTrans2CamCenterNode = new Node();
    Transformation* iPhoneTrans2CamCenter = new Transformation();
	iPhoneTrans2CamCenter->translate(0,0.1,0);
    iPhoneTrans2CamCenter->scale(1,1,1);
    iPhoneTrans2CamCenterNode->setCore(iPhoneTrans2CamCenter);
    iPhoneTrans2CamCenterNode->addChild(iPhoneNode);
    
    // iPhone Animation
    Node* iPhoneAnimRotationNode = new Node();
    AnimNodding* negateNodding = new AnimNodding(2, Vector3d(0,1,0), 11.5, 0);
    iPhoneAnimRotationNode->setCore(negateNodding);
    iPhoneAnimRotationNode->addChild(iPhoneTrans2CamCenterNode);

    Node* iPhoneAnimRotation2Node = new Node();
    AnimNodding* nodding = new AnimNodding(1.8, Vector3d(1,0,0), 15, 0);
    iPhoneAnimRotation2Node->setCore(nodding);
    iPhoneAnimRotation2Node->addChild(iPhoneAnimRotationNode);

    Node* iPhoneTransNode = new Node();
    Transformation* iPhoneTrans = new Transformation();
	iPhoneTrans->translate(0,1.5,0);
    iPhoneTrans->rotate(45, 1, 0, 0);
//    iPhoneTrans->scale(0.0588, 0.1109, 0.009);
    iPhoneTransNode->setCore(iPhoneTrans);
    iPhoneTransNode->addChild(iPhoneAnimRotation2Node);
    
    // CodeMarker
    Node* codeMarkerNode = new Node();
    CodeMarker* codeMarkerGeo = new CodeMarker("CodeMarker");
    nobj = codeMarkerGeo;
    Material* codeMarkerMat = new Material();
    float codeMarkerColor[] = {0.2f, 0.2f, 0.2f, 0};
    codeMarkerMat->getDiffuse(codeMarkerColor);
    codeMarkerGeo->setMaterial(codeMarkerMat);
    codeMarkerNode->setCore(codeMarkerGeo);
    
    Node* codeMarkerTransNode = new Node();
    Transformation* codeMarkerTrans = new Transformation();
	codeMarkerTrans->translate(-0.05,1.4, 0.2);
    codeMarkerTrans->scale(1,1,1);
    codeMarkerTransNode->setCore(codeMarkerTrans);
    codeMarkerTransNode->addChild(codeMarkerNode);

	// Boden
	Node* bodenNode = new Node();
	Cube* bodenGeo = new Cube("Boden");
	Material* bodenMat = new Material();
	float bodenColor [] = {0,0,1,0};
	bodenMat->getDiffuse(bodenColor);
	bodenGeo->setMaterial(bodenMat);
	bodenNode->setCore(bodenGeo);

	Node* bodenTransNode = new Node();
	Transformation* bodenTrans = new Transformation();
	bodenTrans->scale(40, 0.5, 40);
	bodenTransNode->setCore(bodenTrans);
	bodenTransNode->addChild(bodenNode);


    // Lichter 
	// Licht 0
	Node* lightNode = new Node();
	Light* light0 = new PointLight();
	lightNode->setCore(light0);
	
	Node* lightTransNode = new Node();
	Transformation* lightTrans = new Transformation();
	lightTrans->translate(20,10,20);
	lightTransNode->setCore(lightTrans);
	lightTransNode->addChild(lightNode);

    
	// bewegliche Kamera
	Input inp [4];
	inp[0].iKey = GLUT_KEY_DOWN;
	inp[1].iKey = GLUT_KEY_UP;
	inp[2].iKey = GLUT_KEY_LEFT;
	inp[3].iKey = GLUT_KEY_RIGHT;
	inp[0].type = TYPE_INT;
	inp[1].type = TYPE_INT;
	inp[2].type = TYPE_INT;
	inp[3].type = TYPE_INT; 
	MoveInPlane* moveTrans = new MoveInPlane(inp, 0.5, 130.0);
	Node* movingNode = new Node();
	movingNode->setCore(moveTrans);
	
	Camera* cam = new Camera();
	Node* camNode = new Node();
	camNode->setCore(cam);
	
	Node* camTransNode = new Node();
	Transformation* camTrans = new Transformation();
	camTrans->translate(0,1.5,0.6);
	camTransNode->setCore(camTrans);
	camTransNode->addChild(movingNode);
	
	movingNode->addChild(camNode);
    
    
	// Szene zusammensetzen
	root->addChild(lightTransNode);
	root->addChild(camTransNode);
	root->addChild(iPhoneTransNode);
	root->addChild(codeMarkerTransNode);
//	root->addChild(bodenTransNode);
}

void genPerformanceTestScene(Node* root){
	// Root als Gruppe
	Core* rootCore = new Group();
	root->setCore(rootCore);
	
	// Boden
	Node* bodenNode = new Node();
	Cube* bodenGeo = new Cube("Boden");
	Material* bodenMat = new Material();
	float bodenColor [] = {0,0,1,0};
	bodenMat->getDiffuse(bodenColor);
	bodenGeo->setMaterial(bodenMat);
	bodenNode->setCore(bodenGeo);
	
	Node* bodenTransNode = new Node();
	Transformation* bodenTrans = new Transformation();
	bodenTrans->scale(40, 0.5, 40);
	bodenTransNode->setCore(bodenTrans);
	bodenTransNode->addChild(bodenNode);
	
	// Teapot Geo
//	Teapot* teapotGeo = new Teapot();
//	Material* teapotMat = new Material();
//	float teapotColor [] = {0.3,0.5,0.5,1};
//	teapotMat->setDiffuse(teapotColor);
//	teapotGeo->setMaterial(teapotMat);
	
	// Ball Geo
	Sphere* ballGeo = new Sphere("Kugel");
	Material* ballMat = new Material();
	float ballColor [] = {0.8, 0.5, 0.1, 1.0};
	ballMat->setDiffuse(ballColor);
	ballGeo->setMaterial(ballMat);
	// Ausmaße des Balls
	Transformation* ballScale = new Transformation();
	ballScale->translate(0,1,0);
	ballScale->scale(0.25,0.25,0.25);
	
	
	for(int z=-19; z < 20; z+=5) {
		for(int x=-19; x < 20; x+=5) {
			//Haeuser
			Node* hausNode = new Node();
			float hausColor [] = {(float)(x+19)/40, (float)(z+19)/40, (float)(x+z+19)/60, 1};
			Cube* hausGeo = new Cube("Haus");
			Material* hausMat = new Material();
			hausGeo->setMaterial(hausMat);
			hausMat->setDiffuse(hausColor);
			//hausMat->setSpecular(hausColor);
			
			hausNode->setCore(hausGeo);
			
			Node* hausTransNode = new Node();
			Transformation* hausTrans = new Transformation();
			hausTrans->translate(x, 0, z);
			hausTrans->scale(0.5,4,0.5);
			hausTrans->translate(0, 0.5, 0);
			hausTransNode->setCore(hausTrans);
			hausTransNode->addChild(hausNode);	
			
			root->addChild(hausTransNode);
			// rotierender Teapot
//			VNode* teapotNode = new VNode();
//			teapotNode->setCore(teapotGeo);
//			
//			VNode* teapotRotAnimNode = new VNode();
//			// Teapot Animation (Rotation)
//			AnimRotation* teapotAnimRot = new AnimRotation(50,Vector3d(0,1,0));
//			teapotRotAnimNode->setCore(teapotAnimRot);
//			teapotRotAnimNode->addChildren(teapotNode);
//			
//			VNode* teapotTransNode = new VNode();
//			Transformation* teapotTrans = new Transformation();
//			teapotTrans->translate(x+1.5, 2, z+1.5);
//			teapotTransNode->setCore(teapotTrans);
//			teapotTransNode->addChildren(teapotRotAnimNode);
//			
//			root->addChildren(teapotTransNode);
			
			for(int i = 0; i < 3; i++) {
			// springender Ball
			Node* ballNode = new Node();
			ballNode->setCore(ballGeo);
			
			Node* ballScaleNode = new Node();
			ballScaleNode->setCore(ballScale);
			ballScaleNode->addChild(ballNode);
			
			Node* ballAnimJumpNode = new Node();
			// Ball Animation
			AnimJumping* ballAnimJump = new AnimJumping(Vector3d(0,1,0), 4);
			ballAnimJumpNode->setCore(ballAnimJump);
			ballAnimJumpNode->addChild(ballScaleNode);
			
			Node* ballTransNode = new Node();
			Transformation* ballTrans = new Transformation();
			ballTrans->translate(x+3.5,0,z+3.5);
			ballTransNode->setCore(ballTrans);
			ballTransNode->addChild(ballAnimJumpNode);
	 
			root->addChild(ballTransNode);
			}
		}
	}
	
	
	
	// Lichter 
	// Licht 0
	Node* lightNode = new Node();
	Light* light0 = new PointLight();
	lightNode->setCore(light0);
	
	Node* lightTransNode = new Node();
	Transformation* lightTrans = new Transformation();
	lightTrans->translate(20,10,20);
	lightTransNode->setCore(lightTrans);
	lightTransNode->addChild(lightNode);
	
	// Licht 1
	Node* lightNode1 = new Node();
	Light* light1 = new PointLight();
	lightNode1->setCore(light1);
	
	Node* lightTransNode1 = new Node();
	Transformation* lightTrans1 = new Transformation();
	lightTrans1->translate(-20,10,-20);
	lightTransNode1->setCore(lightTrans1);
	lightTransNode1->addChild(lightNode1);
	
	// bewegliche Kamera
	Input inp [4];
	inp[0].iKey = GLUT_KEY_UP;
	inp[1].iKey = GLUT_KEY_DOWN;
	inp[2].iKey = GLUT_KEY_LEFT;
	inp[3].iKey = GLUT_KEY_RIGHT;
	inp[0].type = TYPE_INT;
	inp[1].type = TYPE_INT;
	inp[2].type = TYPE_INT;
	inp[3].type = TYPE_INT; 
	MoveInPlane* moveTrans = new MoveInPlane(inp, 10, 50);
	Node* movingNode = new Node();
	movingNode->setCore(moveTrans);
	
	Camera* cam = new Camera();
	Node* camNode = new Node();
	camNode->setCore(cam);
	
	Node* camTransNode = new Node();
	Transformation* camTrans = new Transformation();
	camTrans->translate(0,1.5,0);
	camTransNode->setCore(camTrans);
	camTransNode->addChild(movingNode);
	
	movingNode->addChild(camNode);
	
	// Szene zusammensetzen
	root->addChild(lightTransNode);
	root->addChild(lightTransNode1);
	root->addChild(camTransNode);
	root->addChild(bodenTransNode);
}

void genPerformanceTestSceneStatic(Node* root){
	// Root als Gruppe
	Core* rootCore = new Group();
	root->setCore(rootCore);
	
	// Boden
	Node* bodenNode = new Node();
	Cube* bodenGeo = new Cube("Boden");
	Material* bodenMat = new Material();
	float bodenColor [] = {0,0,1,0};
	bodenMat->getDiffuse(bodenColor);
	bodenGeo->setMaterial(bodenMat);
	bodenNode->setCore(bodenGeo);
	
	Node* bodenTransNode = new Node();
	Transformation* bodenTrans = new Transformation();
	bodenTrans->scale(40, 0.5, 40);
	bodenTransNode->setCore(bodenTrans);
	bodenTransNode->addChild(bodenNode);
	
	Teapot* teapotGeo = new Teapot("Teepott");
	Material* teapotMat = new Material();
	float teapotColor [] = {0.3,0.5,0.5,1.0};
	teapotMat->setDiffuse(teapotColor);
	teapotGeo->setMaterial(teapotMat);

	Sphere* ballGeo = new Sphere("Kugel");
	Material* ballMat = new Material();
	float ballColor [] = {0.8, 0.5, 0.1, 1.0};
	ballMat->setDiffuse(ballColor);
	ballGeo->setMaterial(ballMat);
	
	Transformation* ballScale = new Transformation();
	ballScale->translate(0,1,0);
	ballScale->scale(0.25,0.25,0.25);

//	AnimRotation* teapotAnimRot = new AnimRotation(50,Vector3d(0,1,0));
//	AnimJumping* ballAnimJump = new AnimJumping(Vector3d(0,1,0), 2, 4);
	
	// Häuser
	for(int z=-19; z < 20; z+=5) {
		for(int x=-19; x < 20; x+=5) {
			Node* hausNode = new Node();
			float hausColor [] = {(float)(x+19)/40, (float)(z+19)/40, (float)(x+z+19)/60, 1};
			Cube* hausGeo = new Cube("Haus");
			Material* hausMat = new Material();
			hausGeo->setMaterial(hausMat);
			hausMat->setDiffuse(hausColor);
			//hausMat->setSpecular(hausColor);
			
			hausNode->setCore(hausGeo);
			
			Node* hausTransNode = new Node();
			Transformation* hausTrans = new Transformation();
			hausTrans->translate(x, 0, z);
			hausTrans->scale(0.5,4,0.5);
			hausTrans->translate(0, 0.5, 0);
			
			hausTransNode->setCore(hausTrans);
			hausTransNode->addChild(hausNode);	
			
			root->addChild(hausTransNode);

	
			// rotierender Teapot
			Node* teapotNode = new Node();
			
			teapotNode->setCore(teapotGeo);
			
			Node* teapotRotAnimNode = new Node();
			Group* teapotAnimRot = new Group();
			//AnimRotation* teapotAnimRot = new AnimRotation(50,Vector3d(0,1,0));
			teapotRotAnimNode->setCore(teapotAnimRot);
			teapotRotAnimNode->addChild(teapotNode);
			
			Node* teapotTransNode = new Node();
			Transformation* teapotTrans = new Transformation();
			teapotTrans->translate(x+1.5, 2, z+1.5);
			teapotTransNode->setCore(teapotTrans);
			teapotTransNode->addChild(teapotRotAnimNode);
			
			root->addChild(teapotTransNode);
			
			// springender Ball
			Node* ballNode = new Node();
			
			ballNode->setCore(ballGeo);
			
			Node* ballScaleNode = new Node();
			ballScaleNode->setCore(ballScale);
			ballScaleNode->addChild(ballNode);
			
			Node* ballAnimJumpNode = new Node();
			Group* ballAnimJump = new Group();
			//AnimJumping* ballAnimJump = new AnimJumping(Vector3d(0,1,0), 2, 4);
			ballAnimJumpNode->setCore(ballAnimJump);
			ballAnimJumpNode->addChild(ballScaleNode);
			
			Node* ballTransNode = new Node();
			Transformation* ballTrans = new Transformation();
			ballTrans->translate(x+3.5,0,z+3.5);
			ballTransNode->setCore(ballTrans);
			ballTransNode->addChild(ballAnimJumpNode);
	 
			root->addChild(ballTransNode);
		}
	}
	
	// Lichter 
	// Licht 0
	Node* lightNode = new Node();
	Light* light0 = new PointLight();
	lightNode->setCore(light0);
	
	Node* lightTransNode = new Node();
	Transformation* lightTrans = new Transformation();
	lightTrans->translate(20,10,20);
	lightTransNode->setCore(lightTrans);
	lightTransNode->addChild(lightNode);
	
	// Licht 1
	Node* lightNode1 = new Node();
	Light* light1 = new PointLight();
	lightNode1->setCore(light1);
	
	Node* lightTransNode1 = new Node();
	Transformation* lightTrans1 = new Transformation();
	lightTrans1->translate(-20,10,-20);
	lightTransNode1->setCore(lightTrans1);
	lightTransNode1->addChild(lightNode1);
	
	// bewegliche Kamera
	Input inp [4];
	inp[0].iKey = GLUT_KEY_UP;
	inp[1].iKey = GLUT_KEY_DOWN;
	inp[2].iKey = GLUT_KEY_LEFT;
	inp[3].iKey = GLUT_KEY_RIGHT;
	inp[0].type = TYPE_INT;
	inp[1].type = TYPE_INT;
	inp[2].type = TYPE_INT;
	inp[3].type = TYPE_INT; 
	MoveInPlane* moveTrans = new MoveInPlane(inp, 10, 50);
	Node* movingNode = new Node();
	movingNode->setCore(moveTrans);
	
	Camera* cam = new Camera();
	Node* camNode = new Node();
	camNode->setCore(cam);
	
	Node* camTransNode = new Node();
	Transformation* camTrans = new Transformation();
	camTrans->translate(0,1.5,0);
	camTransNode->setCore(camTrans);
	camTransNode->addChild(movingNode);
	
	movingNode->addChild(camNode);
	
	// Szene zusammensetzen
	root->addChild(lightTransNode);
	root->addChild(lightTransNode1);
	root->addChild(camTransNode);
	root->addChild(bodenTransNode);
	
}


int main(int argc, char** argv) {
	root = new Node();
	Renderer r("Szenengraph-Test", WINDOW_WIDTH, WINDOW_HEIGHT);
	r.init(argc, argv);
    genARScene(root);
	//genPerformanceTestScene(root);
	//genPerformanceTestSceneStatic(root);
	r.startRendering(root, nref, nobj);
}
