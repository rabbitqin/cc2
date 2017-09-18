#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camera.setup(640,480);
    shader.load("shader.vert","shader.frag");
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    shader.begin();
    shader.setUniform1f("rand",-sin(ofGetElapsedTimef())*sin(ofGetElapsedTimef()));
    
    shader.setUniform2f("u_mouse", mouseX, ofGetHeight()-mouseY);
    shader.setUniform2f("u_resolution",ofGetWidth(), ofGetHeight());
    
    
    camera.draw(0,0);
    shader.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    shader.load("shader.vert","shader.frag");
    
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
