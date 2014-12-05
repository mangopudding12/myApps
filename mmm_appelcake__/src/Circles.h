


// I still don't understand this ???? I try to understand it. But it's weird 
 #ifndef _CIRCLES
 #define _CIRCLES


// this is some library 
#include "ofMain.h"
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
	  Circles (); 

	  // variables
	  float speedx; 
	  float speedy;  
	  float radius; 
	  float color; 
	  float x;
	  float y; 
	  float speed; 

	  // bounce of the arc(hoek) of the screen. 
	  void bounce();
  
  // place for private functions or variables 
  private: 

};

#endif



