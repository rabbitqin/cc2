#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    shader.load("shader.vert","shader.frag");
    
    fftFile.setMirrorData(false);
    fftFile.setup();
    
    ofLoadImage(meshTexture, "texture.jpg");
    music.load("hip.mp3");
    music.setLoop(true);
    music.play();
    
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
    ofBackground(100);
    
    sphere.setRadius( 100 );
    currentState=VERT;
    meshes.push_back(sphere.getMesh());
    //--------------------------------------------------------------
    fftFile.setup();
    
    //--------------------------------------------------------------
    string guiPath = "audio.xml";
    meshIndex = 0;
    // gui.setup("audio", guiPath, 20, 20);
    bUseAudioInput = true;
    audioPeakDecay = 0.915;
    audioMaxDecay = 0.995;
    audioMirror = true;
    gui.add(color.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
    gui.loadFromFile(guiPath);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    fftFile.setPeakDecay(audioPeakDecay);
    fftFile.setMaxDecay(audioMaxDecay);
    fftFile.setMirrorData(audioMirror);
    fftFile.update();
    
    
    //---------------------------------------------------------- dispacing mesh using audio.
    ofMesh & meshOriginal = meshes[meshIndex];
    meshWarped = meshOriginal;
    
    if(bUseAudioInput == false) {
        return;
    }
    
    vector<ofVec3f> & vertsOriginal = meshOriginal.getVertices();
    vector<ofVec3f> & vertsWarped = meshWarped.getVertices();
    int numOfVerts = meshOriginal.getNumVertices();
    
    audioData = new float[numOfVerts];
    fftFile.getFftPeakData(audioData, numOfVerts);
    
    float meshDisplacement = 20;
    
    for(int i=0; i<numOfVerts; i++) {
        audioValue = audioData[i];
        ofVec3f & vertOriginal = vertsOriginal[i];
        ofVec3f & vertWarped = vertsWarped[i];
        
        ofVec3f direction = vertOriginal.getNormalized();
        vertWarped = vertOriginal + direction * meshDisplacement * audioValue;
    }
    
    // delete[] audioData;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //----------------------------------------------------------
    gui.draw();
    
    //----------------------------------------------------------
    ofEnableDepthTest();
    
    float dist = 400;
    camera.setDistance(dist);
    camera.begin();
    
    shader.begin();
    
    shader.setUniform1f("peak", audioValue);
    shader.setUniform1f("change", ofGetElapsedTimef());
    shader.setUniform1f("time", ofGetElapsedTimef());
    ofSetColor(color);
    //  ofSetColor(ofColor::white);
    //sphere.draw();
    //ofSetColor(ofColor::white);
    if(currentState==VERT){
         ofSetColor(ofColor::white);
        sphere.drawVertices();}
    if(currentState==wFRAME)
    sphere.drawWireframe();
    if(currentState==SURFACE)
    sphere.draw();
    
    shader.end();
    camera.end();
    
    ofDisableDepthTest();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(key){
        case '1':
            currentState = VERT;
            break;
        case '2':
            currentState = wFRAME;
            break;
        case '3':
            currentState=SURFACE;
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

