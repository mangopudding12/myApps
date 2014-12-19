

// on this way you include the header I have made.
#include "Circles.h"

//------This the constructor function form my Circles class------
Circles :: Circles (float _kleur,float _x, float _y, float _radius)
{
    // variables
    speedx = ofRandom (1,3);
    speedy = ofRandom (1,3);
    
    x = _x;
    y = _y;
    radius = _radius;
    kleur = _kleur;                
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
    ofSetColor (150,kleur,kleur);
    ofCircle (x,y,radius);


	// why ?????? don't exists mouseX ?????? that is seriues weird ????
	// ofCirle (mouseX,mouseY, playerradius); 
} 

void Circles::mouseReleased(ofMouseEventArgs& args){
    //freeze things
    cout << "clicked" << x <<endl;
    cout << args[0] << args[1]; //these are the values of the x and y position of the mouse when it was clicked
    float x = ofDist(args[0], args[1], x, y);
    cout<< x << " I am the radius of the thingamabob" <<endl;

    if(ofDist(args[0], args[1], x, y) < radius){
    }
}

void Circles::mouseDragged(ofMouseEventArgs& args){}
void Circles::mousePressed(ofMouseEventArgs& args){}
void Circles::mouseMoved(ofMouseEventArgs& args){}




