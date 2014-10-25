#include "ofApp.h"

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
	hasTouch = false; 

	// picutere 
	MM.loadImage("MM.png");
}

//--------------------------------------------------------------
void ofApp::update(){
	
		// background 
	//	ofBackground (200,color2,200);



	// The mmmm you lose or aaaa you go to next level code line (enemy up to down)
	  if (ofDist (xenemy,yenemy,mouseX,mouseY) <= d1 + d2) 
     {
		  // This is the you have lose part 
            color = 100; 
		    LostGame2 = true; 	
		    hasTouch = true; 
	      }

		  // This part say you lose game so froze everything 
		  else if (hasTouch == true) {
		     LostGame2 = true;
		  }

          // aaaa you go to next level part :) 
	      else {
             color = 200;   
		     LostGame2 = false; 

		  // If you get level 5 you get a new enemy from right to left 
		  if ( Level > 5) { 
			  Speednew = 14; 

          // Speed from enemy become faster when you get level 9 
		  } else if (Level > 9){
			  Speednew = 20;

          // When are lower than level 5 you don't you 2 enemy's 
          } else {
			  Speednew = 0; 
		  }
      }



       // The mmmm you lose or aaaa you go to next level code line (enemy right to left)
	   if (ofDist (xenemy2,yenemy2,mouseX,mouseY) <= d1 + d3)
        {
			 // This is the you have lose part 
			   LostGame = true;  
			   hasTouch = true; 
			 } 
	   
			 // This part say you lose game so froze everything 
			  else if (hasTouch == true) {
			    LostGame = true; 
			  }

              // aaaa you go to next level part :) 
			  else { 
			    color = 200;  
			    LostGame = false;
		 }



		  // enemy moving 
		    yenemy+= speed; 
			xenemy2+= Speednew;


		  // enemy fall out the screen (enemy up to down)
		  if (yenemy > 600)
		  {
			  yenemy = ofRandom (10,100);
			  Level++;
			  xenemy = ofRandom (20,570);
		  }


		  // (enemy right to left) fall out the screen  
		  if (xenemy2 > 600)
		  {
			  xenemy2 = 0;
			  yenemy2 = ofRandom (10,570);
		  }

		

			
	   
	

}

//--------------------------------------------------------------
void ofApp::draw(){
	
		// player 
		ofSetColor (90,color,color);
		ofCircle (mouseX,mouseY,d1);


		// (enemy up down) 
		ofSetColor (color2,0,color3); 
		ofCircle (xenemy,yenemy,d2);

		// (enemy right left)
		ofSetColor (80,color3,color2);
		ofCircle (xenemy2,yenemy2,d3); 

	
		// game rules level 
		ofSetColor(0); 
		ofDrawBitmapString("Level: " + ofToString(Level), 20, 20); 


	if (LostGame)
	{
		Speednew = 0; 
		speed = 0; 
		color = 100;
		ofSetColor(0); 
		ofDrawBitmapString("Your are a peanut \nYour final Level: " + ofToString(Level) +
			               "\nPress mouse to restart!", 50, 200);
	    } else {
			speed = 15;
	}


	if (LostGame2)
	{
		Speednew = 0; 
		color = 100;
		speed = 0; 
		ofSetColor(0); 
		ofDrawBitmapString("Your are a peanut \nYour final Level: " + ofToString(Level) +						   "\nPress mouse to restart!", 50, 200);
	} 
	      // I have a picture problem oooo noooo help me it is a monster really 
	 //if (Level > 13) {
		   MM.draw(300,300,400,400);
		//   }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	// both enemy size and color change 
	d2 = ofRandom (10,50);
	d3 = ofRandom (10,50); 
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
	     

		 if (LostGame)
		 {
			 // reset the enemy's location and size 
			 // (enemy up down)  
			 xenemy = ofRandom (100,500);
			 yenemy = ofRandom (-20,-70);
			 d2 = 30; 

			 // (enemy right left) 
			  xenemy2 = ofRandom (-30,-70);
			  yenemy2 = ofRandom (200,500);
			  d3 = 30;
		  
			 // reset level to 0 again 
			  Level = 0; 

			  // reset the color of the player
			  color2 = 100;

			 // reset game frozen to game alive 
			  hasTouch = false; 
		 } 

		 

		 if (LostGame2)
		 {
			  // reset the enemy's location and size 
			  // (enemy up down)  
			  xenemy = ofRandom (100,500);
			  yenemy = ofRandom (-20,-70);
			  d2 = 30; 

			  // (enemy right left) 
			 xenemy2 = ofRandom (-30,-70);
			 yenemy2 = ofRandom (200,500);
			  d3 = 30;
		  
			  // reset level to 0 again 
			 Level = 0; 

			 // reset the color of the player
			  color2 = 100;

			 // reset game frozen to game alive 
			 hasTouch = false; 
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
