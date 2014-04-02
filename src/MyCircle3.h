//
//  MyCircle3.h
//  0304_particles
//
//  Created by Anna on 2014/3/14.
//
//

#ifndef _MY_CIRCLE3
#define _MY_CIRCLE3

#include "ofMain.h"

class MyCircle3 {
    
public:
    //constructor__the construct of class
    // ofPoint is like a container of posx and posy
    MyCircle3(ofPoint pos, float radius);
    //destructor__something like closing file or deleting expression
    
    void update();
    void draw();
    
    //circle behavior
    float phase;
    //circle behavior speed
    float phaseSpeed;
    
    //where to go
    void addForce(float x, float y);
    float forceX;
    float forceY;
    
    ofPoint pos;
    float radius;
    

    
private:
};

#endif