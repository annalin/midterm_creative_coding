#ifndef _MY_CIRCLE2
#define _MY_CIRCLE2

#include "ofMain.h"

class MyCircle2 {
    
public:
    //constructor__the construct of class
    // ofPoint is like a container of posx and posy
    MyCircle2(ofPoint pos, float radius);
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