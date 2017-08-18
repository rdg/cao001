#pragma once

#include "ofMain.h"

class Line {
public:
	ofPoint a;
	ofPoint b;
};

class ofApp : public ofBaseApp {

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
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	ofPolyline line;

	vector <ofPoint> drawnPoints;
	vector < Line > lines;

	// for 3d lines ...
	ofNode baseNode;
	ofNode childNode;
	ofNode grandChildNode;

	// for camera
	ofEasyCam cam;
	int maxDistance;
	int camEnabled;
	int followEnabled;
};
