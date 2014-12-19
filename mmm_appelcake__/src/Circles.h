


// I still don't understand this ???? I try to understand it. But it's weird
#ifndef _CIRCLES
#define _CIRCLES


// this is some library
#include "ofMain.h"
#include "ofApp.h"
#include <iostream>
using namespace std;





// my circles class
class Circles
{
    
    // public place for functions or variables
public:
    
    // methods
    void update ();
    void draw ();

	
    // constructor
    Circles (float _kleur,float _x, float _y, float _radius);
    
    // variables
    float speedx;
    float speedy;
    float radius;
    float kleur;
    float x;
    float y;
    float speed;
    
	// float playerradius; 


	void mouseReleased(ofMouseEventArgs& args);
    void mouseMoved(ofMouseEventArgs& args);
    void mousePressed(ofMouseEventArgs& args);
    void mouseDragged(ofMouseEventArgs& args);
    


    // place for private functions or variables
private: 
    
};

#endif



