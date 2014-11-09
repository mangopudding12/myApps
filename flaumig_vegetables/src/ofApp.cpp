#include "ofApp.h"
using namespace std;
#include <iostream>





//--------------------------------------------------------------
void ofApp::setup(){


	// this is like you can only make 3 circles 
	const int numCircles = 3;

	// this are the 3 names 
    names.push_back("player");
    names.push_back("enemy");
    names.push_back("peanut");



	// this I don't get because I know c dies in this function. But what is happening here ?????
	// maybee we make here space for 3 circles something like that 
    for (int i=0; i<numCircles; i++) {
        Circle c;

		// this is push back to vector 
        circles.push_back(c);
    }


	// I know here we give every circles his name. But how does it work ??? 
	// because how can the pc know that circle 0 must called player and not enemy ??? 
    for (int i=0; i<numCircles; i++) {
        circles.at(i).name = names[i];
		cout<< i << endl; 
        cout<< circles.at(i).name <<endl;
    }


	//  aaaaaaaaa I don't understand how to give the circles a x value wiht a for loop ???????????
	// because I think it is very handy because else you must writte so much lines if you have more than 3         circles
	for (int i = 0; i < numCircles; i++) {
	    int t = 300; 
		circles.at (i).x = t;
		t = ofRandom (50,400);
		cout << t << endl; 
		cout << i << endl; 
	}

	// this is not handy at all because if I have 100 circle I must writte this 100 times that is crazy ???
	circles.at (1).h = 30; 
	circles.at (1).w = 90; 
	circles.at (1).x = 700; 
	circles.at (1).y = 400; 

	circles.at (2).h = 120; 
	circles.at (2).w = 120; 
	circles.at (1).x = 200; 
	circles.at (2).y = 200; 

	circles.at (0).h = 50; 
	circles.at (0).w = 120; 
	circles.at (1).x = 500; 
	circles.at (0).y = 600; 

	cout << "I think it is for me difficult to understand vectors and struct because I never just class /   array in processing, But I go to read the information now. I hope I will understand vectors and         struct better than. :) I don't give up. and woooo hoooo it is a comment... I like it on this way hihi"       << endl; 
}

//--------------------------------------------------------------
void ofApp::update(){

	


}

//--------------------------------------------------------------
void ofApp::draw(){

	// this is also crazy if you must writte this 100 times ????????
	ofEllipse (circles [0].x, circles [0].y, circles [0].w,circles [0].h);
	ofEllipse (circles [1].x, circles [1].y, circles [1].w,circles [1].h);
	ofEllipse (circles [2].x, circles [2].y, circles [2].w,circles [2].h);

	




}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
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
