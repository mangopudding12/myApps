#pragma once
#include "ofMain.h"
#include <iostream>

// on this way you make a constant that you can change if you want !!!!!
 #define NUM_CIRCLE 2
// #define MAX_SPEED 16
using namespace std;

struct Circle {
    int x;
    int y;
    int width;
	int speedy; 
	int speedx;
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

		// this size of the player
		float d_player; 

		// bool switch 
		bool saus; 
		float k; 
		

};
