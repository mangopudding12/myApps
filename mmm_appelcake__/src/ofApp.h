

#ifndef _OF_APP
#define _OF_APP 

#include "ofMain.h"
#include "Circles.h"
#define NCircles 16

class ofApp : public ofBaseApp
{
  public: 
	  void setup(); 
	  void update(); 
	  void draw();

	  // here I give the class a name. So that you can use him !!! 
	 /* Circles bigMother; 
	  Circles bigMother1;
	  Circles bigMother2; */


	  Circles bigMother[NCircles];


  private:

};

#endif
