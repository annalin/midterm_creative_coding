#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "MyCircle.h"
#include "Mycircle2.h"
#include "MyCircle3.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    
    //    Ball myBall;
    vector<Ball> myBalls;//vector is a special array(?)
    
    vector <MyCircle> circles;
    
    vector <MyCircle2> circles2;
    
    vector <MyCircle3> circles3;
    
    ofArduino	ard;
	bool		bSetupArduino;			// flag variable for setting up arduino once
    
    //background
    ofVideoPlayer myPlayer;
    
private:
    
    void setupArduino(const int & version);
    void digitalPinChanged(const int & pinNum);
    void analogPinChanged(const int & pinNum);
	void updateArduino();
    
    string buttonState;
    string potValue;


    
};

//declare all the function