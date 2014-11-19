#include "ofApp.h"
using namespace std;
#include <iostream>





//--------------------------------------------------------------
void ofApp::setup()
  {
		
		 //set up the circles
		 for(int i = 0; i <= 16; i ++ )
		 {
			Circle c;
			c.x = ((10* i )+ ofRandom (0,900));
			c.y = (i*10) + ofRandom (0,500);
			c.width = 40;
			c.height = 60;

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
			   
  }

//--------------------------------------------------------------
void ofApp::update(){
	 
	// I want if you press key s than something must happen but pc don't understand what I want ???????
    // Little bit help will be fine :) 
	//if (key 115 == true) { 


}

//--------------------------------------------------------------
void ofApp::draw()
   {

	  
		 


		  //draw the circles
		  for(int i =1; i <= 16 ; i ++ )
          {
                // is draw the circles and give the color  
			    ofSetColor(i*50, i*20,60);
                ofEllipse((myCircles[i].x), myCircles[i].y,myCircles[i].width, myCircles                                    [i].height);
		 
		        // give all the circles a other speed 
				myCircles[i].y += myCircles[i].speedy; 
		        myCircles[i].x += myCircles[i].speedx;
                 
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
	     cout << key << endl;       


	      // this change the width of the circle so you know who you are hihi !!!!
	      myCircles[1].width = ofRandom (20,70); 

	      // if speedx is - than the speed will become slower 
	      // if speedx is + than the speed will become faster 
		  if (myCircles[1].speedx <= 6){ 
	      myCircles[1].speedx += 1; 
		  } else {
			  myCircles[1].speedx = 0; 
		  }
	
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
