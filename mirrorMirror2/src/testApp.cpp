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
    triHeight = 215;    
    
    w = 320;
    h = 240;
    
    movie.initGrabber(ofGetWidth(), ofGetHeight(), true);
    
    //reserve memory for cv images
    rgb.allocate(ofGetWidth(), ofGetHeight());
    hsb.allocate(ofGetWidth(), ofGetHeight());
    hue.allocate(ofGetWidth(), ofGetHeight());
    sat.allocate(ofGetWidth(), ofGetHeight());
    bri.allocate(ofGetWidth(), ofGetHeight());
    filtered.allocate(ofGetWidth(), ofGetHeight());

}

//--------------------------------------------------------------
void testApp::update(){
    movie.update();
    
    if (movie.isFrameNew()) {
        
        //copy webcam pixels to rgb image
        rgb.setFromPixels(movie.getPixels(), ofGetWidth(), ofGetHeight());
        
        //mirror horizontal
        rgb.mirror(false, true);
        
        //duplicate rgb
        hsb = rgb;
        
        //convert to hsb
        hsb.convertRgbToHsv();
        
        //store the three channels as grayscale images
        hsb.convertToGrayscalePlanarImages(hue, sat, bri);
        
        //filter image based on the hue value we're looking for
        for (int i=0; i<w*h; i++) {
            filtered.getPixels()[i] = ofInRange(hue.getPixels()[i],findHue-5,findHue+5) ? 255 : 0;
        }
        filtered.flagImageChanged();
        
        //run the contour finder on the filtered image to find blobs with a certain hue
        contours.findContours(filtered, 50, w*h, 1, false);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    //title screen
    if (begin == false) {
        ofBackground(0);
        mirror.drawString("Mirror//Mirror", 50, 100);
        //mirror2.drawString("//Mirror", 100, 100);
        press.drawString("Press Space to Start", 50, 175);
        triHeight = 215;
    }
    
    //choose your character
    if (begin == true and mirrorStart == false) {
        ofBackground(0);
        //list of personas
        select.drawString("Select a critic:", 50, 175);
        names.drawString("Sassy Sarah", 50, 225);
        names.drawString("Accepting Alice", 50, 275);
        names.drawString("Popular Pat", 50, 325);
        names.drawString("Encouraging Eric", 50, 375);
        names.drawString("Mother-in-Law Mary", 50, 425);
        names.drawString("Smart Alec", 50, 475);
        names.drawString("Dirty Doug", 50, 525);
        //cursor
        ofTriangle(25, triHeight-10, 25, triHeight+10, 40, triHeight);
        //instructions
        directions.drawString("w=up  s=down  a=back d=select", 50, ofGetHeight()-50);
    }
    
    //mirror
    if (mirrorStart == true) {
        ofSetColor(255,255,255);
        
        //draw all cv images
        rgb.draw(0, 0);
//        hsb.draw(0,0);
//        hue.draw(0,0);
//        sat.draw(0,0);
//        bri.draw(0,0);
//        filtered.draw(0,0);
        contours.draw(0,0);
        
        ofSetColor(255, 40, 90);
        ofFill();
        
        rgb.drawBlobIntoMe(blob, 255);
        
        //draw red circles for found blobs
        for (int i=0; i<contours.nBlobs; i++) {
            //ofCircle(contours.blobs[i].centroid.x, contours.blobs[i].centroid.y, 20);
            directions.drawString("hello", contours.blobs[i].centroid.x, contours.blobs[i].centroid.y);
        }
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    //press space to start and b to return
    if (key == 32) {
        begin = true;
    }
    if (key == 'a' and mirrorStart == false) {
        begin = false;
    }
    
    //move the selector up and down
    if (key == 'w') {
        if (triHeight > 215){
            triHeight -= 50;
        }
    }
    if (key == 's') {
        if (triHeight < 515){
            triHeight += 50;
        }
    }
    
    
    //select persona
    if (key == 'd' and begin == true) {
        mirrorStart = true;
    }
    
    //return to persona select //doesn't work yet
    if (key == 'x') {
        mirrorStart == false;
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