#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(255, 255, 255);
	
	ofEnableAlphaBlending();
	ofEnableAntiAliasing();
	ofEnableDepthTest();

	camEnabled = 1;
	followEnabled = 1;
}

//--------------------------------------------------------------
void ofApp::update() {
	strand.update(20000);
	strand.extendLine();
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (camEnabled == 1) {
		cam.enableMouseInput();
	}
	else {
		cam.disableMouseInput();
	}

	cam.begin();
	strand.render();
	if (followEnabled == 1) {
		// collect points from strand
		ofPoint target = strand.getPoint(1);
		ofPoint eye = strand.getPoint(90);
		// collect camera
		ofNode currTarget = cam.getTarget();
		// ease towards
		ofPoint offset = target - currTarget.getPosition();
		cam.setTarget(currTarget.getPosition() + offset * 0.01);
		offset = (eye - cam.getPosition()) * 0.01;
		cam.setPosition(cam.getPosition() + offset);
	}
	cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == '+') {
		strand.setInfluence(strand.getInfluence() + 10);
	}
	else if (key == '-') {
		strand.setInfluence(strand.getInfluence() - 10);
	}
	else if (key == 'c') {
		camEnabled *= -1;
	}
	else if (key == 'f') {
		followEnabled *= -1;
	}
	else if (key == 'r') {
		strand.reset();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
