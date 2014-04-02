#include "MyCircle2.h"

MyCircle2::MyCircle2(ofPoint _pos, float _radius)
{
    //define pos and radius
    pos = _pos;
    pos.x = _pos.x;
    pos.y = _pos.y;
    radius = _radius;
    phaseSpeed = 0.06;
    
    
    //initail circle behavior
    phase = ofRandom(0, PI);

    
    //define force
    //    forceX = 1+ofRandom(1.5, -1);
    //    forceY = -1+ofRandom(0, 1.5);
      forceX = -1 + ofRandom(-1.5, 1);
      forceY = -1+ ofRandom(0.3, 1.5);
//    forceX = ofRandom(-0.4, 0.4);
//    forceY = ofRandom(-0.4, 0.4);
}

//-------------------------------------------

void MyCircle2::update()
{
    phase += phaseSpeed;
    
    
    //position update adding force
    pos.x += forceX;
    pos.y += forceY;
    
    
}

void MyCircle2::draw()
{
    //how radius change through time
    float r = sin(phase)*radius;
    
    
    //set the color of circles__three layers
    
    ofSetColor(255, 255, 153, 15);
    ofCircle(pos.x, pos.y, radius*2.0);
    
    ofSetColor(255, 255, 204, 127);
    ofCircle(pos.x, pos.y, r);
    
    ofSetColor(255, 255, 255);
    ofCircle(pos.x, pos.y, r*0.25);
}


//----------------
void MyCircle2::addForce(float x, float y){
    forceX += x;
    forceY += y;
}

