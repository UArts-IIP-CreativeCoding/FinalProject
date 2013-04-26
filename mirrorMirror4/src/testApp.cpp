#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    string title = "Mirror";
    string titleTwo = "//Mirror";
    string start = "Press Space to start";
    
    bool begin = false;
    bool mirrorStart = false;
    
    mirror.loadFont("MavenProLight-200.otf", 72);
    mirror2.loadFont("MaveProLight-200.otf", 72);
    press.loadFont("MavenProLight-200.otf", 48);
    select.loadFont("MavenProLight-200.otf", 36);
    names.loadFont("MavenProLight-200.otf", 24);
    directions.loadFont("MavenProLight-200.otf", 14);
    
    
    video.initGrabber(ofGetWidth(),ofGetHeight(), true);

    reflection.allocate(ofGetWidth(),ofGetHeight());
    hue.allocate(ofGetWidth(), ofGetHeight());
    grayImage.allocate(ofGetWidth(),ofGetHeight());
    
    bLearnBakground = true;
    threshold = 80;
    
    begin = false;
}

//--------------------------------------------------------------
void testApp::update(){
    
    ofBackground(100,100,100);

    video.update();
    
    reflection.setFromPixels(video.getPixels(), ofGetWidth(),ofGetHeight());
    grayImage = reflection;
    
    if (bLearnBakground == true){
        grayBg = grayImage;
        bLearnBakground = false;

    }
    
    // take the abs value of the difference between background and incoming and then threshold:
    grayDiff.absDiff(grayBg, grayImage);
    grayDiff.threshold(threshold);
    
    // find contours which are between the size of 20 pixels and 1/3 the w*h pixels.
    // also, find holes is set to true so we will get interior contours as well....
    contourFinder.findContours(grayDiff, 20, (340*240)/3, 10, true);	// find holes

}

//--------------------------------------------------------------
void testApp::draw(){
    
if (begin == false) {
    ofBackground(0);
    mirror.drawString("Mirror//Mirror", 50, 100);
    press.drawString("Press Space to Start", 50, 175);

}
    
    
    
    
if (begin == true) {
    //webcam feed
//    reflection.draw(0, 0);
    grayImage.draw(0, 0);
    

    
    for (int i = 0; i < contourFinder.nBlobs; i++){
        contourFinder.blobs[i].draw(0, 0);
    }
    
    

}
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if (key == ' ') {
        begin = true;
    }
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
    //calculate local mouse x,y in image
    int mx = x % w;
    int my = y % h;
    
    //get hue value on mouse position
    findHue = hue.getPixels()[my*w+mx];
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