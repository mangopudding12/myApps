#pragma once
#include "ofMain.h"
#include <iostream>
// #define //NUM_CIRCLE 2
// #define MAX_SPEED 16
using namespace std;



//// this a struct is like a class what can hold all diffirent things like int / float / string enzo. 
//	struct Circle
//		{
//			  int x;
//			  int y;
//			  int w;
//		      int h;
//		      string name;
//		};

struct Circle {
    int x;
    int y;
    int width;
    int height;
	int speedy; 
	int speedx;

	// Random de speed so that it not the seem al the time 
    };





class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
	
		

		float speed; 
        vector<Circle> myCircles;
      

};
