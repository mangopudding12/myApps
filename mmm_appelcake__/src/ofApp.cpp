
// This is the place where everything come by each other. Else you don't see anything. 

// on this way you include the header I have made. 
#include "ofApp.h"


void ofApp :: setup() 
{
	ofBackground (0,0,0); 
} 

void ofApp :: update() 
{
	
	// this function update 16 Circles ... Thanks so much for loop ... 
	for(int i=0; i<NCircles; i++)
      {
         bigMother[i].update();
      }


}

void ofApp :: draw()
{

	
	// this function draw 16 Circles 
	for(int i=0; i<NCircles; i++)
       {
          bigMother[i].draw();
       }
	
} 


