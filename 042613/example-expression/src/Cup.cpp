//
//  cup.cpp
//  ofApp
//
//  Created by nmbrguy on 5/8/13.
//
//

#include "Cup.h"


void Cup:: initialize(){
    
    cout << "i did it!" << endl;
    
}



void Cup:: draw(int x, int y, ofColor body, ofColor etc){
    
    ofFill();
    //mug
    ofSetColor(ofColor(body));
    ofRect(x, y, 40, 30);
    //wut
    ofSetColor(100, 100, 100, 10);
    //liquid
    ofSetColor(ofColor(etc));
    ofRect(x+5, y, 30, 20);
    
    ofSetLineWidth(2);
    ofNoFill();
    ofSetColor(0, 0, 0);
    ofCircle(x-5, y+10, 6);
    
}