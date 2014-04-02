//
//  dust.cpp
//  0304_particles
//
//  Created by Anna on 2014/3/12.
//
//

#include "dust.h"


Dust::Dust(float fX, float fY, float fZ) {
    pos.set(fX, fY, fZ);
    angle = 0;
    angle_inc = ofRandom(0,0.08);
    radius = ofRandom(60,90.0f);
    start_x = move_pos.x = fX;
    start_y = move_pos.y = fY;
    start_z = fZ;
    move_pos.z = fZ;
    vel = ofRandom(0.05,0.08);
}
float Dust::getStartZ() {
    return start_z;
}
void Dust::update() {
    vel += accel;
    vel.limit(30);
    move_pos += vel;
    //pos.z += vel.z;
    pos.z = move_pos.z;
    angle += angle_inc;
    pos.x = move_pos.x + cos(angle) * radius;
    pos.y = move_pos.y + sin(angle) * radius;
}
void Dust::draw() {
    glPushMatrix();
    ofSetColor(0xFF00CC);
    glTranslatef(pos.x, pos.y, pos.z);
    ofCircle(0,0,4);
    glPopMatrix();
}
void Dust::setPosition(ofxVec3f oPos) {
    move_pos = oPos;
}
void Dust::arrive(Dust* pParent) {
    /*
     ofxVec3f target = pParent->getPosition();
     ofxVec3f desired_vel = target - pos;
     float dist = desired_vel.length();
     desired_vel.normalize();
     float max_vel = 80;
     float arrive_dist = 40;
     if (dist <= arrive_dist) {
     desired_vel *= ((max_vel * dist / arrive_dist));
     }
     else {
     desired_vel *= max_vel;
     }
     if (dist > 10) {
     desired_vel -= vel;
     addForce(desired_vel);
     }
     */
}
ofxVec3f Dust::getPosition() {
    return move_pos;
}
void Dust::addForce(ofxVec3f oForce) {
    accel += oForce;
}

};


