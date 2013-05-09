#pragma once

#include "ofMain.h"
#include "Cup.h"
#include "ofxFaceTracker.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
    void cup(int x, int y);
	
	ofVideoGrabber cam;
	ofxFaceTracker tracker;
	ExpressionClassifier classifier;
    
    ofImage mug;
    
    Cup sipz;
    
    Cup coffees;
    
    string description, count;
    int reset, sips, liquid, coffee, another;
    
};