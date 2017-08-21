#pragma once

#include "ofMain.h"

// Line
class Line {
public:
	ofPoint start;
	ofPoint end;
};

// Group of Lines
class Strand {
public:
	Strand();
	void update(int maxLines);
	void render();
	void addLine();
	void extendLine();
	const ofPoint & getPoint(int offset);
	vector <Line> lines;
	vector <ofPoint> points;

	int stepSize = 15;
	float maxDistance = 40.0;
};
