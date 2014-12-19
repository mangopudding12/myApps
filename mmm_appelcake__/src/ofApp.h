

#ifndef _OF_APP
#define _OF_APP

#include "ofMain.h"
#include "Circles.h"
#include "Circles.cpp"

class ofApp : public ofBaseApp
{
public:
    void setup();
    void update();
    void draw();
    Circles *c;

	// mouse pressed functions 
    /*void mouseReleased(ofMouseEventArgs& args);
    void mouseMoved(ofMouseEventArgs& args);
    void mousePressed(ofMouseEventArgs& args);
    void mouseDragged(ofMouseEventArgs& args);
*/

	// player
	float radiusplayer; 

	// Circles class functions 
	/*float kleur;
    float x;
    float y;
    int radius;
*/




private:
    Circles **bigMother;
    int nCircless;
    
};
#endif
