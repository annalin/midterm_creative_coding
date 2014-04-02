//
//  Ball.cpp
//  03_04_class
//
//  Created by Anna on 2014/3/4.
//
//

#include "Ball.h"

Ball::Ball(int x, int y, int _size){
    pos.x = x; //dot--notation accessing a vaeiable inside an class
    pos.y = y;
    forceX = 2+ofRandom(-4,4);
    forceY = 2+ofRandom(-4,4);
    size = _size;
    
    color = ofColor(255,255,255);
    
}
//-----------------------
void Ball::update(){
    color.r = ofMap(pos.x, 0,ofGetWidth(),0,255);
    color.g = ofMap(pos.y, 0,ofGetHeight(),0,255);
    color.b = ofMap(pos.x, 0,ofGetWidth(), 0, 255);
    color.a = ofMap(forceX, 0, 5, 0, 255);
    
    forceX -= 0.01;
    forceY -= 0.01;
    if(forceX < 0.2)forceX = 0;
    if(forceY < 0.2)forceY = 0;
    pos.x += forceX;
    pos.y += forceY;
    //    if(pos.x > ofGetWidth()-size/2)pos.x = 0;
}
//-----------------------
void Ball::draw(){
    ofSetColor(color);
    ofCircle(pos, size);
    
    
}
//-----------------------
void Ball::addForce(float x, float y){
    forceX += x;
    forceY += y;
}
