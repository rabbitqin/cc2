#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxFFTFile.h"
#include "ofxFFTBase.h"

enum gameState{
    VERT,
    wFRAME,
    SURFACE,
    
};



class ofApp : public ofBaseApp{
    
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
    
    ofxPanel gui;
    int meshIndex;
    float audioPeakDecay;
    bool bUseAudioInput;
    float audioMaxDecay;
    bool audioMirror;
    
    // ofxFFTLive fftLive;
    ofxFFTFile fftFile;
    
    ofSoundPlayer music;
    
    ofEasyCam camera;
    
    ofTexture meshTexture;
    vector<ofMesh> meshes;
    ofMesh meshWarped;
    
    ofShader shader;
    
    float * audioData;
    
    float audioValue;
    
    ofSpherePrimitive sphere;
    ofxColorSlider color;
    
    gameState currentState;
    
    // ofImage img;
};

