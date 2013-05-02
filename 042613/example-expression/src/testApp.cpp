#include "testApp.h"

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
	ofSetVerticalSync(true);
	cam.initGrabber(640, 480);
	
	tracker.setup();
	tracker.setRescale(.5);
    
    string description = "sippin";
    int reset = 0;
    
    classifier.load("expressions");
    
    int liquid = 20;
}

void testApp::update() {
	cam.update();
	if(cam.isFrameNew()) {
		if(tracker.update(toCv(cam))) {
			classifier.classify(tracker);
		}
	}
    //string count = string(sips);
    liquid-sips;
    if(sips == 20){
        sips = 0;
        coffee++;
        
    }
}

void testApp::draw() {
	ofSetColor(255);
	cam.draw(0, 0);
	tracker.draw();
	
	int w = 100, h = 12;
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(5, 10);
	int n = classifier.size();
	int primary = classifier.getPrimaryExpression();
    for(int i = 0; i < n; i++){
		ofSetColor(i == primary ? ofColor::red : ofColor::black);
		ofRect(0, 0, w * classifier.getProbability(i) + .5, h);
		ofSetColor(255);
		ofDrawBitmapString(classifier.getDescription(i), 5, 9);
		ofTranslate(0, h + 5);
        
        // cout << classifier.getPrimaryExpression() << endl;
        
        if(classifier.getPrimaryExpression() == 1 && reset == 0){
            cout << "a sip has been taken" << endl;
            //reset = 1
            reset = 1;
            sips++;
            liquid--;
        }
        if(classifier.getPrimaryExpression() == 0){
            cout << "neutral" << endl;
            //reset = 0
            reset = 0;
            
        }
        
    }
	ofPopMatrix();
	ofPopStyle();
	
    //	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), ofGetWidth() - 20, ofGetHeight() - 10);
    //	drawHighlightString(
    //		string() +
    //		"r - reset\n" +
    //		"e - add expression\n" +
    //		"a - add sample\n" +
    //		"s - save expressions\n"
    //		"l - load expressions",
    //		14, ofGetHeight() - 7 * 12);
    
    ofSetColor(255, 0, 0, 255);
    ofRect(540, 20, 30, sips);
    ofDrawBitmapString(String("sips"), 540, 20);
    ofDrawBitmapString(ofToString(sips), 600, 20);
    
    
    ofSetColor(255, 0, 0, 255);
    ofRect(495, 20, 40, 30);
    ofSetColor(100, 100, 100, 10);
    ofRect(500, 20, 30, 20);
    ofSetColor(255, 0, 0, 255);
    ofRect(500, 20, 30, sips);
    ofDrawBitmapString(String("coffeeeee"), 500, 20);
}

void testApp::keyPressed(int key) {
    //	if(key == 'r') {
    //		tracker.reset();
    //		classifier.reset();
    //	}
    //	if(key == 'e') {
    //		classifier.addExpression();
    //	}
    //	if(key == 'a') {
    //		classifier.addSample(tracker);
    //	}
    //	if(key == 's') {
    //		classifier.save("expressions");
    //	}
    //	if(key == 'l') {
    //		classifier.load("expressions");
    //	}
}