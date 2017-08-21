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
	void reset();
	void setInfluence(float value);
	const float & getInfluence();
	const ofPoint & getPoint(int offset);
	vector <Line> lines;
	vector <ofPoint> points;

private:
	int stepSize = 15;
	float influence = 40.0f;
};
