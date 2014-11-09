#pragma once

#include "ofMain.h"
#include <iostream>
using namespace std;


// this a struct is like a class what can hold all diffirent things like int / float / string enzo. 
	struct Circle
		{
			  int x;
			  int y;
			  int w;
		      int h;
		      string name;
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
		
	
		// mmmmm vector is still dificult to understand. I think it is something that remmenbers things for            you. Like ooooo I have 3 circles inside me and I have 3 names inside me. something like that I   
	   // think. 
			vector <string> names;
			vector <Circle> circles;

};
