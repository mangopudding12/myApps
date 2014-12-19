
#ifndef _OF_HOI
#define _OF_HOI


// this is some library
#include "ofMain.h"
#include <iostream>
using namespace std;





// my circles class
class ofHoi
{
    
    // public place for functions or variables
public:
    
    // methods
    void update ();
    void draw ();

	
    // constructor
    ofHoi (float _kleur,float _xi, float _yi, float _radius);
    
    // variables
    float speedx;
    float radius;
    float kleur;
    float xi;
    float yi;
    
    
	
private: 
    
};

#endif



