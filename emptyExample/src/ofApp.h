#pragma once

#include "ofMain.h"
#include "ofHoi.h"



class ofApp : public ofBaseApp{
	public:
		
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);


		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);


		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

      // one Circle
	   float xx;
	   float yy;
       float radius1; 
	   int speed; 

private: 
		ofHoi **Dolfin;
		int nDolfins; 

};





