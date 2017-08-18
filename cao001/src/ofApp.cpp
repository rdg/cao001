#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(255, 255, 255);
	ofSetLineWidth(0.5f);
	ofEnableAlphaBlending();
	ofEnableAntiAliasing();
	ofSetColor(51, 102, 51, 15);
	ofEnableDepthTest();

	maxDistance = 20;
	camEnabled = 1;
	followEnabled = 1;
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	float time = ofGetElapsedTimef();

	Line tempLine;
	ofPoint start;
	if (lines.size() == 0) {
		start.set(ofRandom(0, 500), ofRandom(0, 500), ofRandom(0, 500));
	}
	else {
		start = lines[lines.size() - 1].b;
	}

	ofPoint end;
	end.set(start.x + ofSignedNoise(-30, 30, time * 20.1) * 15, start.y + ofSignedNoise(-30, time * 30.1, 30) * 15, start.z + ofSignedNoise(time* 0.2, -30, 30) * 15);

	tempLine.a = start;
	tempLine.b = end;
	lines.push_back(tempLine);
	while (lines.size() > 20000) {
		lines.erase(lines.begin());
	}

	float curDist = 20.0; // 10.0 + abs(ofSignedNoise(time)) * 30.0;
	for (auto point : drawnPoints) {
		float dist = (end - point).length();
		if (dist < maxDistance) {
			Line lineTemp;
			lineTemp.a = end;
			lineTemp.b = point;
			lines.push_back(lineTemp);
		}
	}
	drawnPoints.push_back(end);
	while (drawnPoints.size() > 3000) {
		drawnPoints.erase(drawnPoints.begin());
	}
	if (camEnabled == 1) {
		cam.enableMouseInput();
	}
	else {
		cam.disableMouseInput();
	}

	cam.begin();
	for (auto line : lines) {
		ofDrawLine(line.a, line.b);
	}

	if (followEnabled == 1) {
		ofPoint target = drawnPoints[drawnPoints.size() - 1];
		ofPoint eye;
		if (drawnPoints.size() > 100) {
			eye = drawnPoints[drawnPoints.size() - 90];
		}
		else {
			eye = cam.getPosition();
		}
		ofNode currTarget = cam.getTarget();
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
		maxDistance += 10;
	}
	if (key == '-') {
		maxDistance -= 10;
	}
	if (key == 'c') {
		camEnabled *= -1;
	}
	if (key == 'f') {
		followEnabled *= -1;
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
	// line.clear();
	ofPoint pt;
	pt.set(x, y);
	line.addVertex(pt);
	float time = ofGetElapsedTimef();
	float curDist = 10.0 + abs(ofSignedNoise(time)) * 30.0;
	for (auto point : drawnPoints) {
		ofPoint mouse;
		mouse.set(x, y);
		float dist = (mouse - point).length();
		if (dist < curDist) {
			Line lineTemp;
			lineTemp.a = mouse;
			lineTemp.b = point;
			lines.push_back(lineTemp);
		}
	}
	drawnPoints.push_back(ofPoint(x, y));
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
