//
//  Ball.h
//  03_04_class
//
//  Created by Anna on 2014/3/4.
//
//
//declare class

#pragma once // only need to declare one time
#include "ofMain.h"

class Ball{
public://outside the class
    Ball(int x, int y, int _size);// the constructor--name of the class, to make sure this is the extension of the testApp, something like the setup
    
    void update();
    void draw();
    void addForce(float x, float y);
    
    int size;
    float forceX;
    float forceY;
    
    ofPoint pos; //storge container x and y(the two or three number) same as ofvec2f
    ofColor color;
    
    
    
private://inside the class
    
};//the semicolon is important in class