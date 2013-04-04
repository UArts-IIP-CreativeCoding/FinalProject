#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    string title = "Mirror//Mirror";
    string start = "Press Space to start";
    bool begin = false;
    mirror.loadFont("MavenProLight-200.otf", 72);
    press.loadFont("MavenProLight-200.otf", 48);
    select.loadFont("MavenProLight-200.otf", 36);
    names.loadFont("MavenProLight-200.otf", 24);
    directions.loadFont("MavenProLight-200.otf", 14);
    triHeight = 215;
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    //title screen
    if (begin == false) {
        ofBackground(0);
        mirror.drawString("Mirror//Mirror", 50, 100);
        press.drawString("Press Space to Start", 50, 175);
        triHeight = 215;
    }
    
    //choose your character
    if (begin == true) {
        ofBackground(0);
        select.drawString("Select a critic:", 50, 175);
        names.drawString("Sassy Sarah", 50, 225);
        names.drawString("Accepting Alice", 50, 275);
        names.drawString("Popular Pat", 50, 325);
        names.drawString("Encouraging Eric", 50, 375);
        names.drawString("Mother-in-Law Mary", 50, 425);
        names.drawString("Smart Alec", 50, 475);
        names.drawString("Dirty Doug", 50, 525);
        ofTriangle(25, triHeight-10, 25, triHeight+10, 40, triHeight);
        directions.drawString("w=up  s=down  b=back", 50, ofGetHeight()-50);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    //press space to start and b to return
    if (key == 32) {
        begin = true;
    }
    if (key == 'b') {
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