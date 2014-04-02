#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    ofSetCircleResolution(32);
    ofSetFrameRate(60);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    ofSetVerticalSync(true);
    
    potValue = "analog pin";
    ard.connect("/dev/tty.usbmodem411", 57600);
    
    ofAddListener(ard.EInitialized, this, &testApp::setupArduino);
    bSetupArduino = false;
    
    //---------background-------
    myPlayer.loadMovie("dandelion.mov");
    
}
//--------------------------------------------------------------
void testApp::update(){
//    for(int i = 0; i<myBalls.size(); i++){
//        myBalls[i].update(); // updte all balls
//    }
    //------background-----
    myPlayer.update();
    
    //--------arduino-------
    updateArduino();

    //size is the length of the array
    
    //--------circles------------------
    
     for (int i = 0; i < circles.size(); i++) {
     circles[i].update();
     }
    

    //----------circles2----------
    for (int i = 0; i < circles2.size(); i++) {
        circles2[i].update();
    }
    
    //---------circles3-------------
    for (int i = 0; i < circles3.size(); i++) {
        circles3[i].update();
    }
    
}
//-------------------------------------------------------
void testApp:: setupArduino(const int & version){
    ofRemoveListener(ard.EInitialized, this, &testApp::setupArduino);
    bSetupArduino = true;
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() <<"."<<ard.getMinorFirmwareVersion();
    
    //set pin A0 to analog input
    ard.sendAnalogPinReporting(0, ARD_ANALOG);
    ofAddListener(ard.EAnalogPinChanged, this, &testApp::analogPinChanged);

    
}
//--------------------------------------------------------------
void testApp::updateArduino(){
    ard.update();
 
}
//--------------------------------------------------------------
void testApp::analogPinChanged(const int &pinNum){
    ofLogNotice() << "value change:" << ard.getAnalog(0);
    if(ard.getAnalog(0)>339){for(int i = 0; i < 4; i++) {
        circles3.push_back(*new MyCircle3(ofPoint(ofGetWindowWidth()/2, ofGetWindowHeight()/2-20), ofRandom(1, 8)));
    }
};
//    if(ard.getAnalog(0)<750 && ard.getAnalog(0)>= 350){for(int i = 0; i < 4; i++) {
//        circles.push_back(*new MyCircle(ofPoint(ofGetWindowWidth()/2, ofGetWindowHeight()/2-20), ofRandom(1, 8)));
//    }
//};
    if(ard.getAnalog(0)< 338){for(int i = 0; i < 4; i++) {
        circles2.push_back(*new MyCircle2(ofPoint(ofGetWindowWidth()/2, ofGetWindowHeight()/2-20), ofRandom(1, 8)));
    }
    };

    
}
//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);
    


    myPlayer.draw(0,0);
    myPlayer.play();
//    for(int i = 0; i<myBalls.size(); i++){
//        myBalls[i].draw();//update all balls
//    }
    
    //------------circles----------
    
     for (int i = 0; i < circles.size(); i++) {
     circles[i].draw();
     }

    
    //info
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("fps = " + ofToString(ofGetFrameRate(), 4), 10, 15);
    ofDrawBitmapString("circle num = " + ofToString(circles.size(), 0), 10, 30);
    
    //----circles2-------
    for (int i = 0; i < circles2.size(); i++) {
        circles2[i].draw();
    }
    //info
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("circle2 num = " + ofToString(circles2.size(), 0), 10, 45);
    
    //------circles3-------
    for (int i = 0; i < circles3.size(); i++) {
        circles3[i].draw();
    }
    //info
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("circle3 num = " + ofToString(circles3.size(), 0), 10, 60);
    
    
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    if (key == 'f') {
        ofToggleFullscreen();
    }
    
    //------circles-------------------
    if (key == 's') {
        for(int i = 0; i < 4; i++) {
            circles.push_back(*new MyCircle(ofPoint(ofGetWindowWidth()/2, ofGetWindowHeight()/2-20), ofRandom(1, 8)));
        }
    }
            
        

    //----------circles2---------------
    if (key == 'a') {
        for(int i = 0; i < 4; i++) {
            circles2.push_back(*new MyCircle2(ofPoint(ofGetWindowWidth()/2, ofGetWindowHeight()/2-20), ofRandom(1, 8)));
            }
    }
    
    //---------circles3--------------
    if (key == 'd') {
        for(int i = 0; i < 4; i++) {
            circles3.push_back(*new MyCircle3(ofPoint(ofGetWindowWidth()/2, ofGetWindowHeight()/2-20), ofRandom(1, 8)));
        }
    }


    
    
}


//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
//    for(int i=0; i<50; i++){
//        //  Ball tempBall = * new Ball(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 5);
//        //*---pointer is to reference the code is not permenant
//        Ball tempBall = * new Ball(x, y, 2);
//        myBalls.push_back(tempBall);
//    }
    

    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}