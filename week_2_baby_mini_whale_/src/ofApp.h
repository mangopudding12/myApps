#pragma once

#include "ofMain.h"
#include <iostream>
using namespace std;


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

		///fucntions for arduino
        void setupArduino();
        void updateArduino();
    
        //allows for serial output 
        ofSerial serial;

        //an arduino object
        ofArduino myArduino;

        //this variable will only be false when the code first runs arduino
        bool bSetupArduino;


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
		float d4; 

		// radius player
		float d1;
		float color; 

		// game rules 
		bool LostGame; 
		float Level;
		bool LostGame2;
		bool hasTouch; 
		bool smaller; 
		bool onlyOnes; 
		 

		// picutere 
		ofImage land2;
		ofImage pinda;

		// sound 
		ofSoundPlayer sound;
		ofSoundPlayer sound1; 
		bool muziek; 
		bool muziek1; 

		// time keper 
		int begintime1; 
		int begintime2;

		int endtime1; 
		int endtime2;

		float g1;
		float g2;
	
		// I want that the 3 light all begin on a ather time with blinking 
		bool light1; 
		bool light2; 


};
