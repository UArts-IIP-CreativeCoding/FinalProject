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
    
    
    sassy.loadFont("MavenProLight-200.otf", 24);
    sass = "Sass";
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    video.update();
    
    //get the image from the video and put it on the screen across the width and height
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
    contourFinder.findContours(grayDiff, 10, (340*240)/3, 10, true);	// find holes

}

//--------------------------------------------------------------
void testApp::draw(){
    
    //Start Screen
if (begin == false) {
    ofBackground(0);
    mirror.drawString("Mirror//Mirror", 50, 100);
    press.drawString("Press Space to Start", 50, 175);

}
    
    
    
    
if (begin == true) {
    //webcam feed
//    reflection.draw(0, 0);
    grayImage.draw(0, 0);
    

    //darw the blobs
//    for (int i = 0; i < contourFinder.nBlobs; i++){
//        contourFinder.blobs[i].draw(0, 0);
//    }
    
    //draw text for found blobs
    for (int i=0; i<contourFinder.nBlobs; i++) {
        //ofCircle(contours.blobs[i].centroid.x, contours.blobs[i].centroid.y, 20);
        directions.drawString(sass, contourFinder.blobs[i].centroid.x, contourFinder.blobs[i].centroid.y);
    }
    
    

}
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    //Press Start
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