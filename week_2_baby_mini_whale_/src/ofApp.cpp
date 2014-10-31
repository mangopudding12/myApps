#include "ofApp.h"







//--------------------------------------------------------------
void ofApp::setup(){

	// mmm I don't really get what is means 
    myArduino.connect("/dev/tty.usbmodem1421", 57600);
    
    //a test to see if the arduion has been set up yet?
    bSetupArduino= false;

    // player 
	color = 190;
    d1 = 70;

	// enemy
	d2 = 50;
	yenemy = 0; 
	speed = 15; 
	xenemy = 300; 
	xenemy2 = -70; 
	d3 = 15; 
	

	// SLOW 
	ofSetFrameRate (40);

	// Game rules
	Level = 0; 
	color2 = 100; 
	hasTouch = false; 
	smaller = false; 

	// picutere 
	land2.loadImage("land2.png");
	pinda.loadImage("pinda.png");

	// music
	sound.loadSound ("woho.mp3");
	sound1.loadSound ("boe.wav");
	sound.play(); 
	
}

     

void ofApp::updateArduino(){
	// update the arduion data ins and out
    myArduino.update();
}



//this will set up all of my arduio pins
void ofApp::setupArduino(){
    myArduino.sendDigitalPinMode(9, ARD_OUTPUT);
}



//--------------------------------------------------------------
void ofApp::update(){
	
		 //if my arduio is ready
		 if ( myArduino.isArduinoReady())
		 {

			   // 1st: setup the arduino if haven't already:
			   if (bSetupArduino == false)
			   {
            
			      //this fundtion assigns the pins
			      setupArduino();
			      // we've starting running arduino so no need to call setup again! :)
			      bSetupArduino = true;	// only do this once
			   }
        
             // 2nd do the update of the arduino
             updateArduino();
        }


	// The mmmm you lose or aaaa you go to next level code line (enemy up to down)
	  if (ofDist (xenemy,yenemy,mouseX,mouseY) <= d1 + d2) 
     {
		  // This is the you have lose part 
		    LostGame2 = true; 	
		    hasTouch = true; 

			// How can you say: I want to hear this sound only one time ???????????  
			sound1.play(); 
			 
	      }

		  // This part say you lose game so froze everything 
		  else if (hasTouch == true) {
		     LostGame2 = true;
			 sound.stop(); 
			
		  }

          // aaaa you go to next level part :) 
	      else {
             color = 200;   
		     LostGame2 = false; 
      }



       // The mmmm you lose or aaaa you go to next level code line (enemy right to left)
	   if (ofDist (xenemy2,yenemy2,mouseX,mouseY) <= d1 + d3)
        {
			 // This is the you have lose part 
			   LostGame = true;  
			   hasTouch = true; 

			 // How can you say: I want to hear this sound only one time ???????????  
			 sound1.play(); 
			 // I must make a bool swits !!!! 

			 } 
	   
			 // This part say you lose game so froze everything 
			  else if (hasTouch == true) {
			    LostGame = true; 
				sound.stop();
				
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
		  if ((yenemy > 700) && (Level < 14) )
		  { 
			       yenemy = ofRandom (-50,150);
				   Level++;
				   xenemy = ofRandom (100,900);
			 }
			   else if ((yenemy > 530) && (Level >= 14))
			 {
				    yenemy = 170;
				    Level++;				    
					xenemy = ofRandom (150,850);
					d2 = ofRandom (20,45);
			        color2 = 110;
			        color3 = 215; 
			 }



		  // (enemy right to left) fall out the screen  
		  if ((xenemy2 > 1000) && (Level < 14))
		  {
			  xenemy2 = 0;
			  yenemy2 = ofRandom (100,600);
		  } 
		  else if ((xenemy2 > 850) && (Level >= 14))
		  {
			  xenemy2 = 250; 
			  yenemy2 = ofRandom (200,476);
		  }



		  // If you get level 5 you get a new enemy from right to left 
		  if ( (Level > 4) && (Level < 9) ) { 
			  Speednew = 14; 
			  d2 = ofRandom (60,75); 
			  color2 = 90;
			  color3 = 150; 

			  // The light of the Arduino goes on Like you are I level 5 jhee 
			  myArduino.sendDigital(9, ARD_HIGH);

			  
          // Speed from enemy become faster when you get level 9 
		  } else if ((Level > 9) && (Level < 14 )){
			  Speednew = 25; 
			  d2 = ofRandom (80,120);
			  color2 = 200;
			  color3 = 250;
			  myArduino.sendDigital(9, ARD_LOW);


		  } else if ( (Level >= 14) && (Level <= 19)){
			  Speednew = 0;
			  xenemy2 = -60; 
			  myArduino.sendDigital(9, ARD_HIGH);

		  } else if ((Level > 19) && (Level < 23)){
			  Speednew = ofRandom (18,25);
			  d3 = 33;
			  myArduino.sendDigital(9, ARD_LOW);

		  } else if (Level >= 23){
			  d3 = 47; 
			  Speednew = ofRandom (20,28); 
			  myArduino.sendDigital(9, ARD_HIGH);

          // When are lower than level 5 you don't have 2 enemy's 
          } else {
			  Speednew = 0; 
		  }
	


		  // playing field is smaller now (X)
		  if ((mouseX > 845) && (Level >= 14)) {
			  mouseX = 845; 
		  }else if ((mouseX < 144) && (Level >= 14)){
			  mouseX = 144;
		  } 



		  // playing field is smaller now (Y) 
		  if ((mouseY > 496) && (Level >= 14)) {
			  mouseY = 496; 
		  }else if ((mouseY < 204) && (Level >= 14)){
			  mouseY = 204;
		  } 


		  // The picture apper at level 14 
		  if (Level > 13){
			   smaller = true;  

			   // player become smaller 
			   d1 = 50; 
		  } 

		  		  
}

//--------------------------------------------------------------
void ofApp::draw(){
	    
	   

	    // draw the picture when you are at level 14
	    if (smaller) {
        ofSetColor(255,255,255);
	    land2.draw(0,0);
		} 


		// player 
		ofSetColor (90,color,color);
		ofCircle (mouseX,mouseY,d1);


		// (enemy up down) 
		ofSetColor (color2,0,color3); 
		ofCircle (xenemy,yenemy,d2);

		// (enemy right left) why is this working ???? because there is no d3 ?? so how is it possible it               that is know when he touch the player ??? How can this enemy know that ??? it is weird 
		ofSetColor(255,255,255);
		pinda.draw(xenemy2-85,yenemy2-60,150,150);

		// (enemy right left)
		//ofSetColor (80,color3,color2);
		//ofCircle (xenemy2,yenemy2,d3); 

	
		// game rules level 
		ofSetColor(0); 
		ofDrawBitmapString("Level: " + ofToString(Level), 20, 20); 


    // if (enemy up donw) is touch than you lost GAME 
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


	// if (enemy right left) is touch than you lost GAME
	if (LostGame2)
	{
		Speednew = 0; 
		color = 100;
		speed = 0; 
		ofSetColor(0); 
		ofDrawBitmapString("Your are a peanut \nYour final Level: " + ofToString(Level) +						                                     "\nPress mouse to restart!", 50, 200);
	} 
	     

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //  x from (enemy up down) change &&  y from (enemy right left). 
	xenemy += ofRandom (100,400); 
	yenemy2 += ofRandom (150,370); 

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	// x from (enemy up down) change &&  y from (enemy right left). 
	xenemy -= ofRandom (100,400); 
	yenemy2 -= ofRandom (150,370); 


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
			 xenemy = ofRandom (100,1000);
			 yenemy = ofRandom (-20,-70);
			 d2 = 50; 

			 // (enemy right left) 
			  xenemy2 = ofRandom (-40,-70);
			  yenemy2 = ofRandom (200,600);
			  d3 = 40;
			  
			 // reset level to 0 again 
			  Level = 0; 
			  sound.play(); 

			  // reset the color of the player
			  color2 = 100;

			 // reset game frozen to game alive 
			  hasTouch = false; 

             // reset picture 
			 smaller = false; 
		 } 

		 

		 if (LostGame2)
		 {
			  // reset the enemy's location and size 
			  // (enemy up down)  
			  yenemy = ofRandom (-20,-70);
			  xenemy = ofRandom (100,900);
			  d2 = 50; 

			 // (enemy right left) 
			 xenemy2 = ofRandom (-40,-70);
			 
		     yenemy2 = ofRandom (200,600);
			 d3 = 40;

			 // reset level to 0 again 
			 Level = 0; 
			 sound.play(); 

			 // reset the color of the player
			 color2 = 100;

			 // reset game frozen to game alive 
			 hasTouch = false; 

			 // reset picture 
			 smaller = false; 

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
