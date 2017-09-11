#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // setup gui
    gui.setup();
    gui.add(radius.setup("Size", .5, 0, 5));
    gui.add(height.setup("Height", 1, 0, 10));
    gui.add(speed.setup("Speed", 1, 0, 5));
    
    texture.load("sniffer.png");
    texture.getTexture().setTextureWrap( GL_REPEAT, GL_REPEAT );
    
    angle = speed / 100;
    float w     = ofGetWidth() * .12;
    h    = ofGetHeight() * .12;
    cone.setMode( OF_PRIMITIVE_TRIANGLE_STRIP );
    
    cone.set( w*.75, h*2.2 );
}

//--------------------------------------------------------------
void ofApp::update(){
    angle += 0.05;
//    if(angle >= TWO_PI*2){
//        angle = 0;
//    }
    if(angle*speed*10>ofGetWindowWidth())
        angle=0;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    float spinX = sin(ofGetElapsedTimef()*.35f);
    float spinY = cos(ofGetElapsedTimef()*.075f);
    

   // ofDrawCircle(angle*20, sin(angle)*20+300, radius*10);
    
    //cone.setPosition(ofGetWidth()*.5, ofGetHeight()*.75, 0);
    cone.set( radius*20, height*20 );
//    cone.setPosition(angle*20, sin(angle*2)*50+300, 0);
    h = 0.9*h + 0.1*(mouseY-ofGetWindowHeight()/2);
  cone.setPosition(angle*speed*10, sin(angle)*h/2+300, 0);
    cone.rotate(spinX, 1.0, 0.0, 0.0);
    cone.rotate(spinY, 0, 1.0, 0.0);
    
    
    texture.getTexture().bind();
    //vector<ofMeshFace> triangles = cone.getMesh().getUniqueFaces();
    //ofFill();
    //cone.setPosition(cone.getPosition().x, cone.getPosition().y, cone.getPosition().z-2);
    cone.draw();
    
    
    ofNoFill();
    ofSetColor(0, 0, 0);
    //cone.setPosition(cone.getPosition().x+20, cone.getPosition().y+20, cone.getPosition().z+20);
    cone.setScale(1.01f);
    cone.drawWireframe();
    ofSetColor(255);
    //ofNoFill();
    //texture.getTexture().bind();

     gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
