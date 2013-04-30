#include "testApp.h"

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
	ofSetVerticalSync(true);
    //set camera size
	cam.initGrabber(640, 480);
	//loading facial expression tracking
	tracker.setup();
	tracker.setRescale(.5);
    
    //helo.jpg
    string description = "sippin";
    int reset = 0;
    
    classifier.load("expressions");
}

void testApp::update() {
    //update frames on
	cam.update();
	if(cam.isFrameNew()) {
		if(tracker.update(toCv(cam))) {
			classifier.classify(tracker);
		}		
	}
    //string count = string(sips);
}

void testApp::draw() {
    
	ofSetColor(255);
    
	cam.draw(0, 0);
    //drawing expression
	tracker.draw();
	
	int w = 100, h = 12;
    
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(5, 10);
    //classifing the type of ekpression, red is current, blk is showing potential of the current expression to be another primory expression
	int n = classifier.size();
	int primary = classifier.getPrimaryExpression();
  for(int i = 0; i < n; i++){
		ofSetColor(i == primary ? ofColor::red : ofColor::black);
		ofRect(0, 0, w * classifier.getProbability(i) + .5, h);
		ofSetColor(255);
		ofDrawBitmapString(classifier.getDescription(i), 5, 9);
		ofTranslate(0, h + 5);
      
         // cout << classifier.getPrimaryExpression() << endl;
      
      //if not first saved normal expression count as sip aka when face is missing
      if(classifier.getPrimaryExpression() == 1 && reset == 0){
          cout << "a sip has been taken" << endl;
          //reset = 1
          reset = 1;
          sips++;
      }
      
      //if neutral expression dont increment anything
      if(classifier.getPrimaryExpression() == 0){
          cout << "neutral" << endl;
          //reset = 0
          reset = 0;
          
      }
      //i beeen thinkinnn bout chuuu
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
    
    //drawing preliminary ui
    ofSetColor(255, 0, 0, 255);
    ofRect(540, 20, 30, sips);
    //draw "sips"
    ofDrawBitmapString(String("sips"), 540, 20);
    //draw a bar for the amount of sips, to be a visual of a mug loosing content
    ofDrawBitmapString(ofToString(sips), 600, 20);
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