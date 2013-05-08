#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    string title = "Mirror";
    string titleTwo = "//Mirror";
    string start = "Press Space to start";
    
    bool begin = false;
    bool mirrorStart = false;
    bool sarah = false;
    bool alice = false;
    
    mirror.loadFont("MavenProLight-200.otf", 72);
    mirror2.loadFont("MaveProLight-200.otf", 72);
    press.loadFont("MavenProLight-200.otf", 48);
    select.loadFont("MavenProLight-200.otf", 36);
    names.loadFont("MavenProLight-200.otf", 24);
    directions.loadFont("MavenProLight-200.otf", 18);
    
    triHeight = 215;
    
    video.initGrabber(ofGetWidth(),ofGetHeight(), true);
    
    reflection.allocate(ofGetWidth(),ofGetHeight());
    hue.allocate(ofGetWidth(), ofGetHeight());
    grayImage.allocate(ofGetWidth(),ofGetHeight());
    
    bLearnBakground = true;
    threshold = 80;
    
    //list of terms that will go into the arrays
    sassArray[0] = "Has this always been there?";
    sassArray[1] = "I hope that grows back";
    sassArray[2] = "You know what soap is, right?";
    sassArray[3] = "Why don't you smile more?";
    sassArray[4] = "Is this your rebel phase?";
    sassArray[5] = "That grows back, right?";
    sassArray[5] = "Oh, come on";
    sassArray[5] = "Cover this up first";
    sassArray[6] = "Did you try makeup?";
    sassArray[7] = "Don't tell your mom";
    sassArray[8] = "You better not be taking a selfie right now";
    sassArray[9] = "Can you use a razor?";
    sassArray[10] = "I guess so";
    sassArray[11] = "Why are you even here?";
    sassArray[12] = "Don't have kids";
    sassArray[13] = "You remind me of a young Conan";
    sassArray[14] = "A new wardrobe can do wonders";
    sassArray[15] = "A solid 6";
    sassArray[16] = "I've been thinking about you";
    sassArray[17] = "No beards, please";
    sassArray[18] = "You can do better";
    sassArray[19] = "Too much?";
    sassArray[20] = "Niche attraction";
    sassArray[21] = "What year is it?";
    
    niceArray[0] = "Lookin' Good!";
    niceArray[1] = "Fresh!";
    niceArray[2] = "You've got a nice smile";
    niceArray[3] = "Can I have your eyes?";
    niceArray[4] = "Nice style, bud!";
    niceArray[5] = "9/10";
    niceArray[6] = "Don't change a thing!";
    niceArray[7] = "I'm liking it!";
    niceArray[8] = "Pow Pow Pow!";
    niceArray[9] = "Fresh to death!";
    niceArray[10] = "You're the best!";
    niceArray[11] = "Keep it up!";
    niceArray[12] = "Nice!";
    niceArray[13] = "You've got this!";
    niceArray[14] = "Marry me!";
    niceArray[15] = "Hot damn, gurl!";
    
    dougArray[0] = "Show me your naked edges.";
    dougArray[1] = "And that's how I got fired.";
    dougArray[2] = "Show me your naked edges.";
    dougArray[3] = "Show me your naked edges.";
    dougArray[4] = "Show me your naked edges.";
    dougArray[5] = "Show me your naked edges.";
    dougArray[6] = "Show me your naked edges.";
    dougArray[7] = "Show me your naked edges.";
    dougArray[8] = "Show me your naked edges.";
    dougArray[9] = "Show me your naked edges.";
    dougArray[10] = "Show me your naked edges.";
    dougArray[11] = "Show me your naked edges.";
    dougArray[12] = "Show me your naked edges.";
    dougArray[13] = "Show me your naked edges.";
    dougArray[14] = "Show me your naked edges.";
    dougArray[15] = "Show me your naked edges.";
    dougArray[16] = "Show me your naked edges.";
    dougArray[17] = "Show me your naked edges.";
    dougArray[18] = "Show me your naked edges.";
    dougArray[19] = "Show me your naked edges.";
    
    mikeArray[0] = "Ha- HA!";
    mikeArray[1] = "Maybe you're a bit over-qualified";
    mikeArray[2] = "If you know what I mean";
    mikeArray[3] = "More is never enough for women";
    mikeArray[4] = "Hide the 'twins'";
    mikeArray[5] = "Are you looking for some 'extra credit?'";
    mikeArray[6] = "Are you suggesting something?";
    mikeArray[7] = "Oh, women...";
    mikeArray[8] = "Ken or Girl Ken?";
    mikeArray[9] = "Oh, I get it...";
    mikeArray[10] = "That's what SHE SAID";
    mikeArray[11] = "Is there something I'm missing?";
    mikeArray[12] = "What're you so smiley about?";
    mikeArray[13] = "WHAT? It's not my fault";
    mikeArray[14] = "Ha- HA!";
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
    
    // find contours which are between the size of 7 pixels and 1/7 the w*h pixels.
    // also, find holes is set to true so we will get interior contours as well....
    contourFinder.findContours(grayDiff, 7, (340*240)/7, 10, true);	// find holes
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //Start Screen
    if (begin == false) {
        ofBackground(0);
        mirror.drawString("Mirror//Mirror", 50, 100);
        press.drawString("Press Space to Start", 50, 175);
        
    }
    
    if (begin == true and mirrorStart == false) {
        ofBackground(0);
        //list of personas
        select.drawString("Select a critic:", 50, 175);
        names.drawString("Sassy Sarah", 50, 225);
        names.drawString("Accepting Alice", 50, 275);
        names.drawString("Dirty Doug", 50, 325);
        names.drawString("Uncle Mike", 50, 375);
        
        //cursor
        ofTriangle(25, triHeight-10, 25, triHeight+10, 40, triHeight);
        
        //instructions
        directions.drawString("w=up  s=down  a=back d=select", 50, ofGetHeight()-50);
    }
    
    
    if (mirrorStart == true) {
        //your face
        reflection.draw(0, 0);
        
        //how to get back
        directions.drawString("a=back", 50, ofGetHeight()-50);
        
        if(sarah == true){
            //draw text for found blobs
            for (int i=0; i<contourFinder.nBlobs; i++) {
                directions.drawString(sassArray[i], contourFinder.blobs[i].centroid.x, contourFinder.blobs[i].centroid.y);
            }
        }
        
        if(alice == true){
            //draw text for found blobs
            for (int i=0; i<contourFinder.nBlobs; i++) {
                directions.drawString(niceArray[i], contourFinder.blobs[i].centroid.x, contourFinder.blobs[i].centroid.y);
            }
        }
        
        if(doug == true){
            //draw text for found blobs
            for (int i=0; i<contourFinder.nBlobs; i++) {
                directions.drawString(dougArray[i], contourFinder.blobs[i].centroid.x, contourFinder.blobs[i].centroid.y);
            }
        }
        
        if(mike == true){
            //draw text for found blobs
            for (int i=0; i<contourFinder.nBlobs; i++) {
                directions.drawString(mikeArray[i], contourFinder.blobs[i].centroid.x, contourFinder.blobs[i].centroid.y);
            }
        }
        
    }
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    //Press Start
    if (key == ' ') {
        begin = true;
    }
    if (key == 'a' and mirrorStart == false) {
        begin = false;
    }
    if (key == 'a' and mirrorStart == true) {
        mirrorStart = false;
        alice = false;
        sarah = false;
        doug = false;
        mike = false;
    }
    //move the selector up and down
    if (key == 'w') {
        if (triHeight > 215){
            triHeight -= 50;
        }
    }
    if (key == 's') {
        if (triHeight < 365){
            triHeight += 50;
        }
    }
    
    
    //select persona
    if (key == 'd' and begin == true) {
        mirrorStart = true;
        if (triHeight == 215) {
            sarah = true;
        }
        if (triHeight == 265) {
            alice = true;
        }
        if (triHeight == 315) {
            doug = true;
        }
        if (triHeight == 365) {
            mike = true;
        }
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
    int mx = x % ofGetWidth();
    int my = y % ofGetHeight()
    ;
    
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