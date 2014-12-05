

// on this way you include the header I have made. 
#include "Circles.h"

//------This the constructor function form my Circles class------
Circles :: Circles () 
{
    // variables
	  speedx = 1; 
	  speedy = 1;   
	  radius = 60;  
	  color = ofRandom (0,200);  
	  x = ofRandom (200,400); 
	  y = ofRandom (500,550); 
} 


//---This is member function from the Circles class-----------
void Circles :: update () 
{ 
	x += speedx;
	y += speedy;

	// bounce van y as
	   if (y > 758 || y < 10) 
	    {
		  speedy *= -1; 
        }

	// bounce van x as 
       if (x > 1010 || x < 10) 
		{
		  speedx *= -1;	
		}
} 


//----This is a member function from the Circles class ---------
void Circles :: draw () 
{ 
	// draw the circles, so you can't see them !!!!!
	ofSetColor (100,color,color); 
	ofCircle (x,y,radius);
} 


