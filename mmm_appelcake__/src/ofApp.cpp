
// This is the place where everything come by each other. Else you don't see anything.

// on this way you include the header I have made.
#include "ofApp.h"



void ofApp :: setup()
{
    ofBackground (0,0,0);
    
    nCircless = 16;
    
    bigMother = new Circles*[nCircless];
 
    for (int i = 0; i < nCircless; i++)
    {
        float kleur =(10*i)+10;
        float x = ofRandom (0,900) + i;
        float y = ofRandom (0,700);
        int radius = ofRandom (25,30) + i ;
        
        bigMother[i] = new Circles(kleur,x,y,radius);
        ofRegisterMouseEvents(bigMother[i]); 
    }

	// player 
	radiusplayer = 30; 

}

void ofApp :: update()
{
    for (int i = 0; i < nCircless; i++)
    {
        bigMother[i]->update();
    }
}

void ofApp :: draw()
{
    for (int i = 0; i < nCircless; i++)
    {
        bigMother[i]->draw();
    }
    
	// this is the player 
	ofSetColor (100,30,210); 
	ofCircle (mouseX,mouseY,radiusplayer); 
} 


// The very big problem is that I have make a player. But When I will just de player in de Circles. cpp he don't recognize mouseX and If I just THE cIRCLES function i ofApp.cpp dan he don't recognize the Circles functions. I don't now what I must do ?????? Help 


// ------ This a event & lisenaar -------------------------------
//void ofApp::mouseReleased(ofMouseEventArgs& args)
//{
//    
//    for (int d = 0; d < nCircless; d ++ ) 
//		{ 
//			//freeze things
//    cout << "clicked" << c[d].x <<endl;
//
//	//the values of the x (args [0]) and y (args [1]) position of the mouse when clicked
//    cout << args[0] << args[1]; 
//
//	      //
//	      if(ofDist(args[0], args[1], mouseX, mouseY) <= c[d].radius + radiusplayer)
//		  {
//           c[d].speedy = 0; 
//		   c[d].speedx = 0; 
//		  }
//        }
//}

//void ofApp::mouseDragged(ofMouseEventArgs& args){}
//void ofApp::mousePressed(ofMouseEventArgs& args){}
//void ofApp::mouseMoved(ofMouseEventArgs& args){}
//
//









