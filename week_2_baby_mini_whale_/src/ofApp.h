#pragma once

#include "ofMain.h"

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

		// (enemy up down)
		float d2;
		float yenemy;
		float speed;
		float xenemy;
		float color3; 

		// (enemy 2 right left) 
		float Speednew;
		float xenemy2;
		float yenemy2;
		float d3;
		float color2; 

		// radius player
		float d1;
		float color; 

		// game rules 
		bool LostGame; 
		float Level;
		bool LostGame2;
		bool hasTouch; 
		bool smaller;

		// picutere 
		ofImage land2;
		
};
