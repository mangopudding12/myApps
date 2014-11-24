#include "ofApp.h"
using namespace std;
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup()
  {
		cout << "nice that you are here " << endl; 

		// this code say you don't see the mouse 
		ofHideCursor();

		 //set up the circles
		 for(int i = 0; i <= NUM_CIRCLE ; i ++ )
		 {
			Circle c;
			c.x = ((10* i )+ ofRandom (0,900));
			c.y = (i*10) + ofRandom (0,500);
			c.width = 20;

			// now the speed of the circles will be not to fast nice !!!!!
			if ( i >= 6 )
			{
				c.speedy = ofRandom (1,4);
				c.speedx = ofRandom (1,4);
			} else {
				c.speedy = i;
				c.speedx = i;
			}  
               
			   // this push all the circles we made to the vector 
		       myCircles.push_back(c);
         }
        
               cout << myCircles.size() << " number of elements in the vector"<<endl;


			   // this is the width and height from player
		       d_player = 80;
			   // bool switch when the player touch the enemy 
			  /* saus = true; 
			   cout << saus << "saus is true "<< endl; 
			     */
  }

//--------------------------------------------------------------
void ofApp::update(){
	 
	// mmmmmmm moeten even kijken wat ik hier mee kan 
	for (int i = 0; i <= NUM_CIRCLE ; i ++)
	{
		
		if (ofDist (myCircles[i].x,myCircles[i].y,mouseX,mouseY) <= (myCircles[i].width-50) + d_player) 
        {
		    // here must stand the when the player touch the enemy than ....... 

			// 1).  I want that the enemy stand still for 10 sec 
			// 2).  If you have touch all the enemy's and they all stand still than you winn !!!
			// saus = false; 
			cout <<"circles"<< i  << "touch the player "<< endl; 
			saus = false;
		
		} else if (saus == false) { 
			
	    } else {
			saus = true; 
		} 

		
 	}  


	

}

//--------------------------------------------------------------
void ofApp::draw()
   {

	     // player 
	     ofSetColor(50, 190,60,100);
		 ofRect(mouseX-40,mouseY-40,d_player,d_player); 


		  //draw the crcles
		  for(int i =1; i <= NUM_CIRCLE; i ++ )
          {
                // is draw the circles and give the color  
			    ofSetColor(i*50, i*20,60);
                ofCircle((myCircles[i].x), myCircles[i].y,myCircles[i].width,myCircles[i].width);
		 
		        // give all the circles a other speed 
				// when it is false than the circles stand still 
				if (saus == true) 
				{ 
				   myCircles[i].y += myCircles[i].speedy; 
		           myCircles[i].x += myCircles[i].speedx;
				} 

				if (saus == false) { 
				 /*  myCircles[1].speedy = 0; 
				   myCircles[1].speedx = 0;*/
				   /*myCircles[i].y += myCircles[i].speedy; 
		           myCircles[i].x += myCircles[i].speedx;*/
				}
				



				// bounce van y as
	            if (myCircles[i].y > 768 || myCircles[i].y < 0) 
		        {
			        myCircles[i].speedy *= -1; 
                }

				// bounce van x as 
         	    if (myCircles[i].x > 1024 || myCircles[i].x < 0) 
		        {
			        myCircles[i].speedx *= -1;		
					
                }
	       }






   }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	     
	      // this is key s    
	      if (key == 115) 
		    {
				// this change the width of the circle so you know who you are hihi !!!!
	            myCircles[1].width = ofRandom (20,70); 

	            // if speedx is - than the speed will become slower 
	            // if speedx is + than the speed will become faster 
		        if (myCircles[1].speedx <= 6)
		        { 
	                myCircles[1].speedx += 1; 
		        } else {
		        	myCircles[1].speedx = 0; 
		        }
        	 }

		  // this is the key - k !! 
		  if (key == 107) 
		    {
				// this change the width of the circle so you know who you are hihi !!!!
	            myCircles[6].width = ofRandom (20,70); 

	            // if speedx is - than the speed will become slower 
	            // if speedx is + than the speed will become faster 
		        if (myCircles[6].speedx <= 6)
		        { 
	                myCircles[6].speedx += 1; 
		        } else {
		        	myCircles[6].speedx = 0; 
		        }
        	 }

	      // this is for that you know what is the cijfer of the key 
	     // cout << key << endl;       
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	saus = true; 
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
