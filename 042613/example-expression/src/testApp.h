#pragma once

#include "ofMain.h"
#include "ofxFaceTracker.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	
    //cam
	ofVideoGrabber cam;
    //load kyle mcd's focial tracking demo
	ofxFaceTracker tracker;
    //load classifier with presaved expressions
	ExpressionClassifier classifier;
    
    
    string description, count;
    int reset, sips;
    
};
