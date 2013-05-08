#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"

#define _USE_LIVE_VIDEO

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    ofVideoGrabber video;
    
    ofxCvColorImage reflection;
    ofxCvContourFinder contourFinder;
    
    ofxCvGrayscaleImage 	hue, grayImage, grayBg, grayDiff;
    
    int 				threshold;
    bool				bLearnBakground;
    
    
    ofTrueTypeFont mirror;
    ofTrueTypeFont mirror2;
    ofTrueTypeFont press;
    ofTrueTypeFont select;
    ofTrueTypeFont names;
    ofTrueTypeFont directions;
    
    
    bool begin;
    bool mirrorStart;
    bool sarah;
    bool alice;
    bool doug;
    bool mike;
    
    int w,h;
    int findHue;
    int triHeight;
    
    string sassArray[22];
    
    string niceArray[16];
    
    string dougArray[20];
    
    string mikeArray[15];
    
};
