

// on this way you include the header I have made. 
#include "ofApp.h"


void ofApp :: setup() 
{
	ofBackground (0,0,0); 
} 

void ofApp :: update() 
{
	
	/*for (int i = 0; i < 16; i++){
		bigMother[i].update(); 
	}*/
	
	bigMother.update(); 
	bigMother1.update(); 
	bigMother2.update(); 
}

void ofApp :: draw()
{
	bigMother.draw(); 
	bigMother1.draw(); 
	bigMother2.draw(); 

} 


