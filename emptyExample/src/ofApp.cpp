#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	// circle function declaring
	yy = 350; 
	xx = 500; 
	speed = 5; 
	radius1 = 40; 

	// setup the FrameRate 
	ofSetFrameRate (100);

    // class
	nDolfins = 2; 

    Dolfin = new ofHoi*[nDolfins];
 
    for (int i = 0; i < nDolfins; i++)
    {
         float xi = 20+(100*i); 
         float yi = 20+(100*i);
         int radius = 30;
	     float kleur = 100; 
 
         Dolfin[i] = new ofHoi(kleur,xi,yi,radius);  
    }


	// this shows the information of variables ... NICE !!! 
	cout << "type \t\tsize \tmin \t\t\tmax" << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "bool\t\t" << sizeof(bool) << endl;
    cout << "char\t\t" << sizeof(char) << "\t" << CHAR_MIN << "\t\t\t" << CHAR_MAX << endl;
    cout << "unsigned char\t" << sizeof(unsigned char) << "\t\t\t\t" << UCHAR_MAX << endl;
    cout << "short\t\t" << sizeof(short) << "\t" << INT_MIN << "\t\t" << INT_MAX << endl;
    cout << "int\t\t" << sizeof(int) << "\t" << INT_MIN << "\t\t" << INT_MAX << endl;
    cout << "unsigned int\t" << sizeof(unsigned int) << "\t\t\t\t" << UINT_MAX << endl;
    cout << "float\t\t" << sizeof(float) << "\t" << FLT_MIN << "\t\t" << FLT_MAX << endl;
    cout << "long\t\t" << sizeof(long) << "\t" << LONG_MIN << "\t\t" << LONG_MAX << endl;
    cout << "double\t\t" << sizeof(double) << "\t" << DBL_MIN << "\t\t" << DBL_MAX << endl;


  string str;
  str = "hello";
  for (char c : str)
  {
    cout << "lol" << c << "]";
  }
    cout << '\n';
}

//--------------------------------------------------------------
void ofApp::update(){

	// circle can bounce don't leave the screen 
	if (xx < 0 || xx > 1013) 
	{
		speed = speed * -1; 
	}

	// circle will move in X position 
	xx += speed; 

	// class
	for (int i = 0; i < nDolfins; i++)
	{
    Dolfin[i]->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

	// this is the color and the circle it self 
     ofSetColor (90,100,300);
	 ofCircle (xx,yy,radius1); 

    // FrameRate of program and print it in de left side of the screen
	ofDrawBitmapString (ofToString (ofGetFrameRate()) + "fps",10,15);

	// class 
	for (int i = 0; i < nDolfins; i++)
	{
    Dolfin[i]->draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

	// this show the key you press and the number of the key the computer use
	cout << "this is char \t " << (char) key  <<"\t and this is the number \t" << key <<  endl;



}

void ofApp::mouseMoved(int x, int y){
}
 
void ofApp::mouseDragged(int x, int y, int button){
}
 
void ofApp::mousePressed(int x, int y, int button)
{

	// I seriues don't understand what is wrong here ???? 
	// Why don't he recogzise Dolfin ???? Why ????? 
	/*for (int i = 0; i < nDolfins; i++)
	{ 
		if (ofDist( Dolfin[i].xi,  Dolfin[i].yi, x, y) <= Dolfin[i].radius)
	   {
    
	         if (radius < 100) 
	         {
	             radius += 10;
	         } else {
		         radius = 30;
	         }
	   }
	}*/






	// purple circle on his own 
	if (ofDist(xx, yy, x, y) <= radius1)
	{
    
	    if (radius1 < 100) 
	    {
	        radius1 += 10;
	    } else {
		    radius1 = 30;
	    }
	}

    cout << "mousePressed: " << x << ", " << y << " button: " << button << endl;
}
 
void ofApp::mouseReleased(int x, int y, int button){

}
//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}