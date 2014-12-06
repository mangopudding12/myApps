

// on this way you include the header I have made. 
#include "Circles.h"


//------This the constructor function form my Circles class------
Circles :: Circles () 
{
    // variables
	  speedx = ofRandom (1,3); 
	  speedy = ofRandom (1,3);   
	  radius = ofRandom (30,50);  
	  color = ofRandom (0,200);  
	  x = ofRandom (100,1000); 
	  y = ofRandom (100,550); 
} 


//---This is member function from the Circles class-----------
void Circles :: update () 
{ 

    // The Circles can move 
	x += speedx;
	y += speedy;



	 // The bounce funtions for y and the x as. 
	 if (y > 750 || y < 20) 
	    {
		  speedy *= -1; 
        }

     if (x > 1000 || x < 20) 
		{
		  speedx *= -1;	
		}
} 


//----This is a member function from the Circles class ---------
void Circles :: draw () 
{ 
	// draw the circles, so you can't see them !!!!!
	ofSetColor (150,color,color); 
	ofCircle (x,y,radius);
} 


