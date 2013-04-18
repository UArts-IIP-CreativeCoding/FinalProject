#pragma once

#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxOpenCv.h"

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
    
    //void mousePressed(int x, int y, int button);
    
    ofVideoGrabber movie;
    
    ofxCvColorImage rgb,hsb;
    ofxCvGrayscaleImage hue,sat,bri,filtered;
    ofxCvContourFinder contours;
    
    int w,h;
    int findHue;
    
    
    ofxCvBlob blob;
    
    
    ofTrueTypeFont mirror;
    ofTrueTypeFont mirror2;
    ofTrueTypeFont press;
    ofTrueTypeFont select;
    ofTrueTypeFont names;
    ofTrueTypeFont directions;
    string title;
    string titleTwo;
    string start;
    bool begin;
    bool mirrorStart;
    int triHeight;
    
    
    //Sarah's Strings
    string ssHair1;
    string ssHair2;
    string ssHair3;
    string ssHair4;
    
    string ssEyes1;
    string ssEyes2;
    string ssEyes3;
    string ssEyes4;
    
    string ssEars1;
    string ssEars2;
    string ssEars3;
    string ssEars4;
    
    string ssNose1;
    string ssNose2;
    string ssNose3;
    string ssNose4;
    
    
    //Alice's Strings
    string aaHair1;
    string aaHair2;
    string aaHair3;
    string aaHair4;
    
    string aaEyes1;
    string aaEyes2;
    string aaEyes3;
    string aaEyes4;
    
    string aaEars1;
    string aaEars2;
    string aaEars3;
    string aaEars4;
    
    string aaNose1;
    string aaNose2;
    string aaNose3;
    string aaNose4;
    
    
    //Pat's Strings
    string ppHair1;
    string ppHair2;
    string ppHair3;
    string ppHair4;
    
    string ppEyes1;
    string ppEyes2;
    string ppEyes3;
    string ppEyes4;
    
    string ppEars1;
    string ppEars2;
    string ppEars3;
    string ppEars4;
    
    string ppNose1;
    string ppNose2;
    string ppNose3;
    string ppNose4;
    
    
    //Eric's Strings
    string eeHair1;
    string eeHair2;
    string eeHair3;
    string eeHair4;
    
    string eeEyes1;
    string eeEyes2;
    string eeEyes3;
    string eeEyes4;
    
    string eeEars1;
    string eeEars2;
    string eeEars3;
    string eeEars4;
    
    string eeNose1;
    string eeNose2;
    string eeNose3;
    string eeNose4;
    
    
    //Mary's Strings
    string mmHair1;
    string mmHair2;
    string mmHair3;
    string mmHair4;
    
    string mmEyes1;
    string mmEyes2;
    string mmEyes3;
    string mmEyes4;
    
    string mmEars1;
    string mmEars2;
    string mmEars3;
    string mmEars4;
    
    string mmNose1;
    string mmNose2;
    string mmNose3;
    string mmNose4;
    
    
    
    //Alec's Strings
    string saHair1;
    string saHair2;
    string saHair3;
    string saHair4;
    
    string saEyes1;
    string saEyes2;
    string saEyes3;
    string saEyes4;
    
    string saEars1;
    string saEars2;
    string saEars3;
    string saEars4;
    
    string saNose1;
    string saNose2;
    string saNose3;
    string saNose4;
    
    
    //Doug's Strings
    string ddHair1;
    string ddHair2;
    string ddHair3;
    string ddHair4;
    
    string ddEyes1;
    string ddEyes2;
    string ddEyes3;
    string ddEyes4;
    
    string ddEars1;
    string ddEars2;
    string ddEars3;
    string ddEars4;
    
    string ddNose1;
    string ddNose2;
    string ddNose3;
    string ddNose4;
    
};
#endif