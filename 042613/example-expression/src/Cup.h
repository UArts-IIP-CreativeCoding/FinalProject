//
//  cup.h
//  ofApp
//
//  Created by nmbrguy on 5/8/13.
//
//

#ifndef __ofApp__Cup__
#define __ofApp__Cup__

#include "ofMain.h"


class Cup{
    
    //method declared here
    
public:
    
    //constructor would thet go here *if* using
    
    
    
    //the rest of my methods
    void initialize();

    void draw(int x, int y, ofColor body, ofColor etc);

    
    //declare data types, here
    int x, y,radius, app;
    //ofColor flesh;
    ofPoint pos, click;
    
private:
    
    
    
};   // <---------- need your semicolon at the end of your class

#endif