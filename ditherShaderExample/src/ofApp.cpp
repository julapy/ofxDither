#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.loadImage("sutu_512x512.jpg");
    
    shader.load("shaders/dither_ordered_bayer_4x4");

    fbo.allocate(image.width, image.height, GL_RGBA);
    fbo.getTextureReference().setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    fbo.begin();
    shader.begin();
    shader.setUniform1i("bUseColor", ofGetMousePressed());
    image.draw(0, 0, fbo.getWidth(), fbo.getHeight());
    shader.end();
    fbo.end();
    
    image.draw(0, 0);
    fbo.draw(image.getWidth(), 0, image.getWidth(), image.getHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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