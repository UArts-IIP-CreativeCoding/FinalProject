#include "testApp.h"
#include "Cup.h"

using namespace ofxCv;
using namespace cv;

void testApp::setup() {
    ofBackground(117, 117, 117);
	ofSetVerticalSync(true);
    
    //loads camera for draw
	cam.initGrabber(640, 480);
	
    //loads Kyle McDonald's facetracking addon
	tracker.setup();
	tracker.setRescale(.5);
    
    //house keeping
    string description = "sippin";
    int reset = 0;
    
    //load presaved expressions
    //should be replaced by icon tracking eventually for more reliable and sensible tracking of objects in relation to the users INNER_MOUTH.
    //Will work for now (and not well in conditional lighting) due to time and studio load.
    
    classifier.load("expressions");
    
    //On load set # of coffee consumed to 0
    int coffee = 0;
    
    //a little help from the simple timer eg here
    bTimerReached = false; //time not reached
    startTime = ofGetElapsedTimeMillis();  // get the start time
    endTime = (int)ofRandom(1000, 5000); // in milliseconds
    
    

	stop.loadSound("sounds/enuf.mp3"); // think yo've had enuf
	sip.loadSound("sounds/sip.mp3"); // take another
    cofe.loadSound("sounds/rush.mp3"); // ahhh caffiene
	sip.setVolume(0.75f); //set vols
    cofe.setVolume(0.75f);
	stop.setVolume(0.75f);
	font.loadFont("PropCourierSans-Bold-1.4.ttf", 20); //load mah fav open source font for the bottom titles


    
    
}

void testApp::update() {
    //get new frames to facetrack from camera
	cam.update();
    //if new, get er done
	if(cam.isFrameNew()) {
		if(tracker.update(toCv(cam))) {
			classifier.classify(tracker);
		}
	}
    
    float timer = ofGetElapsedTimeMillis() - startTime;
    
    //string count = string(sips);
    
    //set # of sips to equal a coffee consumed
    liquid-sips;
    if(sips == 10){
        sips = 0;
        coffee++;
        if(coffee <= 2){
        cofe.play();
        }
        
    }
    
    //If preloaded expression of a blocked mouth/face, count
    if(classifier.getPrimaryExpression() == 1 && reset == 0){
        cout << "a sip has been taken" << endl;
        //reset = 1
        reset = 1;
        sips++;
        liquid--;
        startTime = ofGetElapsedTimeMillis();
        endTime = (int)ofRandom(10000, 15000); // milliseconds=
        bTimerReached = false;
        
    }
    //flat face, we do nothingg
    if(classifier.getPrimaryExpression() == 0){
        //cout << "neutral" << endl;
        //reset = 0
        reset = 0;
        if(timer >= endTime && !bTimerReached) {
            bTimerReached = true;
            sip.play();
        }
        
    }
    if(coffee == int(3)){
        stop.play();
    }
    
    
}

void testApp::draw() {
    
	ofSetColor(255);
    
    
	//cam.draw(0, 0);
	//tracker.draw();
    
	//preloading current action bars
	int w = 100, h = 12;
    
	ofPushStyle();
	ofPushMatrix();
	ofTranslate(65, 25);
    
    //current expression and its probability is being drawn
	int n = classifier.size();
	int primary = classifier.getPrimaryExpression();
    for(int i = 0; i < n; i++){
		ofSetColor(i == primary ? ofColor::red : ofColor::black);
		ofRect(0, 0, w, h);
		ofSetColor(255);
		ofDrawBitmapString(classifier.getDescription(i), 22, 9);
		ofTranslate(0, h + 5);
        
        // cout << classifier.getPrimaryExpression() << endl;
        

        
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
    //ofRect(540, 20, 30, sips);
    
    ofFill();
    sipz.draw(415,20,ofColor(0, 0, 0),ofColor(160,82,45));
    
//    ofSetColor(0, 0, 0);
//    ofRect(495, 20, 40, 30);
//    ofSetColor(100, 100, 100, 10);
//    ofRect(500, 20, 30, 20);
//    ofSetColor(0, 0, 0);

    ofFill();
    ofSetColor(255,255,255);
    ofRect(420, 20, 30, sips);
    
    //yall want some crack?
    //ofDrawBitmapString(String("coffeeeee"), 500, 20);
    
    ofSetLineWidth(2);
    ofNoFill();
    ofSetColor(255, 255, 255);
    
    
    
    ofScale(.5,.5);

    
    //scale background
    ofRect(445, 40, 265, 70);
    font.drawString(String("Cup-o-meter"), 495, 140);
    
    //sip text
    font.drawString(String("Sip-o-meter"), 800, 140);
    font.drawString(ofToString(sips), 940, 80);
    
    //coffee scaleee
    
    
    if(coffee == 1){
        
        coffees.draw(495,55,ofColor(0, 0, 0),ofColor(255,255,255));
        
        //cup(495, 55);

        
    };
    if(coffee == 2){
        
        coffees.draw(495,55,ofColor(0, 0, 0),ofColor(255,255,255));
       // cup(495, 55);
        coffees.draw(560,55,ofColor(0, 0, 0),ofColor(255,255,255));
        //cup(560, 55);

        
    };
    if(coffee == 3){
        
        
        sipz.draw(495,55,ofColor(0, 0, 0),ofColor(255,255,255));
        //cup(495, 55);
        sipz.draw(560,55,ofColor(255, 223, 0),ofColor(255,255,255));
        //cup(560, 55);
        sipz.draw(620,55,ofColor(255, 0, 0),ofColor(255,255,255));
        //cup(620, 55);
    
    }
    if(coffee >= 4){
        
        
    font.drawString(ofToString(coffee), 585, 80);

        
    }
    
    
}
//
//void testApp::cup(int x, int y){
//    
//        ofFill();
//        ofSetColor(0, 0, 0);
//        ofRect(x, y, 40, 30);
//        ofSetColor(100, 100, 100, 10);
//        ofSetColor(255, 255, 255);
//        ofRect(x+5, y, 30, 20);
//        
//        ofSetLineWidth(2);
//        ofNoFill();
//        ofSetColor(0, 0, 0);
//        ofCircle(x-5, y+10, 6);
//
//
//}

void testApp::keyPressed(int key) {
    if(key == 'p'){
        
        stop.play();
    }
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