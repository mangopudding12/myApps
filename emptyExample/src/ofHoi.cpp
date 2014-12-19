

// on this way you include the header I have made.
#include "ofHoi.h"

//------This the constructor function form my Circles class------
ofHoi::ofHoi (float _kleur,float _xi, float _yi, float _radius)
{
    // variables
    speedx = ofRandom (1,3);
    xi = _xi;
    yi = _yi;
    radius = _radius;
    kleur = _kleur;                
}


//---This is member function from the Circles class-----------
void ofHoi :: update ()
{
    
    // The Circles can move
    xi += speedx;
   
    // bounce
    if (xi > 1000 || xi < 20)
    {
        speedx *= -1;
    }
}


//----This is a member function from the Circles class ---------
void ofHoi :: draw ()
{	
    // draw the circles, so you can't see them !!!!!
    ofSetColor (150,kleur,kleur);
    ofCircle (xi,yi,radius);
} 




