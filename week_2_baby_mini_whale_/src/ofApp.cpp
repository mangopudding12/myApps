#include "ofApp.h"


	// enemy 1 
	float d2;
	float yenemy;
	float speed;
	float xenemy;
	float color3; 

	// enemy 2 
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
	float Special; 
	bool HorrorSpecial; 
	bool LostGame2;
	bool hasBeenTouched; 

//--------------------------------------------------------------
void ofApp::setup(){
    // player 
	color = 200;
    d1 = 70;

	// enemy
	d2 = 30;
	yenemy = 0; 
	speed = 15; 
	xenemy = 300; 
	xenemy2 = -50; 
	d3 = 30; 

	// SLOW 
	ofSetFrameRate (40);

	// Game rules
	Level = 0; 
	color2 = 100; 

}

//--------------------------------------------------------------
void ofApp::update(){
	
	// background 
	ofBackground (200,color2,200);

	// The color change from player
	  if (ofDist (xenemy,yenemy,mouseX,mouseY) <= d1 + d2 && hasBeenTouched) 
     {
          color = 100; 
		  LostGame2 = true; 	
		  HorrorSpecial = false; 
		  } else {
          color = 200;   
		  LostGame2 = false; 
     }

	   if (ofDist (xenemy2,yenemy2,mouseX,mouseY) <= d1 + d3 && hasBeenTouched)
       {
		  LostGame = true;  
          } else {
          color = 200;  
		  LostGame = false; 
		}

	  // enemy moving 
	  yenemy+= speed; 
	  xenemy2+= Speednew;


	  // enemy fall out the screem 
	  if (yenemy > 600)
	  {
		  yenemy = ofRandom (10,100);
		  Level++;
		  xenemy = ofRandom (20,570);
	  }

	  if (xenemy2 > 600)
	  {
		  xenemy2 = 0;
		  yenemy2 = ofRandom (10,570);
	  }

	  // lostgame rules

	  if (Level > 5)
	  {
		  HorrorSpecial = true; 
	  } else {
		  HorrorSpecial = false; 
	  }

	  if (HorrorSpecial){
		  Speednew = 12;
	  } else {
		  Speednew = 0; 
	  }
	   
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	// player 
	ofSetColor (90,color,color);
	ofCircle (mouseX,mouseY,d1);

	// enemy 
	ofSetColor (color2,0,color3); 
	ofCircle (xenemy,yenemy,d2); 
	ofSetColor (80,color3,color2);
	ofCircle (xenemy2,yenemy2,d3); 

	// froze the game 

	if (hasBeenTouched){
		
	} else { 
	}





	// game rules level 
	ofSetColor(0); 
    ofDrawBitmapString("Level: " + ofToString(Level), 20, 20); 

	if (LostGame){
		Speednew = 0; 
		speed = 0; 
		color = 100;
		ofSetColor(0); 
		ofDrawBitmapString("Your are a peanut \nYour final Level: " + ofToString(Level) +		 
			                 "\nPress mouse to restart!", 50, 200);
	    } else {
			speed = 15;
	    }

	if (LostGame2){
		Speednew = 0; 
		color = 100;
		speed = 0; 
		ofSetColor(0); 
		ofDrawBitmapString("Your are a peanut \nYour final Level: " + ofToString(Level) +		 
			                 "\nPress mouse to restart!", 50, 200);
	    } 
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	// radius - size enemy 
	d2 = ofRandom (10,70);
	xenemy-= ofRandom (0,50); 
	color2 = ofRandom (30,210); 
	color3 = ofRandom (100,250); 
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
// De game starts again if you press the mouse 
	     // enemy2 
		 if (LostGame){
	      Level = 0; 
		  xenemy2 = ofRandom (-40,-70);
		  yenemy2 = ofRandom (200,500);
		  xenemy = ofRandom (100,500);
		  yenemy = ofRandom (-20,-70);
		  color2 = 100; 
		 } 

		 // enemy 
		 if (LostGame2){
	      Level = 0; 
		  xenemy = ofRandom (100,500);
		  yenemy = ofRandom (-20,-70);
		  xenemy2 = ofRandom (-20,-70);
		  yenemy2 = ofRandom (200,500);
		  color2 = 100;
		 } 

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
