#include "testApp.h"

//learning blob stuffs from joshua noble


//--------------------------------------------------------------
void testApp::setup(){

    learnBackground = false;
    
    vidGrabber.setVerbose(true);
    vidGrabber.initGrabber(320, 240);
    //allocating memory for image pixel data
    
    colorImg.allocate(320, 240);
    grayImage.allocate(320, 240);
    grayBg.allocate(320, 240);
    grayDiff.allocate(320, 240);
}

//--------------------------------------------------------------
void testApp::update(){
    vidGrabber.grabFrame();
    //do we have a new frome?
    if (vidGrabber.isFrameNew()){
        colorImg.setFromPixels(vidGrabber.getPixelsRef());
        if (learnBackground == true){
            grayBg = grayImage; //update bg image
            learnBackground = false;
        }
        
        grayDiff.absDiff(grayBg, grayImage);
        grayDiff.threshold(30);
        contourFinder.findContours(grayDiff, 10, (320*240)/4, 2, false, true);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    ofSetHexColor(0xffffff);
    colorImg.draw(0,0,320,240);
    grayDiff.draw(0,240,320,240);
    ofRect(320, 0, 320, 240);
    contourFinder.draw(320,0,320,240);
    ofColor c(255,255,255);
    
    for(int i = 0; i < contourFinder.nBlobs; i++){
        ofRectangle r = contourFinder.blobs.at(i).boundingRect;
        r.x += 320; r.y += 240;
        c.setHsb (i * 64, 255, 255);
        ofSetColor(c);
        ofRect(r);
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    learnBackground = true;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}