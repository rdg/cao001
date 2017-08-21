#include "Strand.h"

Strand::Strand()
{
	addLine();

}

void Strand::update(int maxLines)
{
	// remove old segements
	while (lines.size() > maxLines) {
		lines.erase(lines.begin());
	}
	while (points.size() > maxLines) {
		points.erase(points.begin());
	}

}

void Strand::render()
{
	ofSetLineWidth(0.1f);
	ofSetColor(0, 0, 0 , 15);
	// draw all the segments
	for (auto line : lines) {
		ofDrawLine(line.start, line.end);
	}
}

void Strand::addLine()
{
	// add a new random line segment
	Line line;
	ofPoint start(0, 0, 0);
	ofPoint end(ofRandom(-stepSize, stepSize),
				ofRandom(-stepSize, stepSize),
				ofRandom(-stepSize, stepSize));
	line.start = start;
	line.end = end;

	lines.push_back(line);
	points.push_back(end);
}

void Strand::extendLine()
{
	float time = ofGetElapsedTimef();

	// connect a new random line segment
	Line line;
	ofPoint start;
	ofPoint end;
	start.set(lines[lines.size() - 1].end);
	end.set(start.x + ofSignedNoise(-30, 30, time * 20.1) * stepSize,
			start.y + ofSignedNoise(-30, time * 30.1, 30) * stepSize,
			start.z + ofSignedNoise(time* 0.2, -30, 30) * stepSize);
	line.start = start;
	line.end = end;

	lines.push_back(line);
	points.push_back(end);

	// connect them all
	for (auto point : points) {
		float dist = (point - end).length();
		if (dist < influence) {
			Line lineTemp;
			lineTemp.start.set(end);
			lineTemp.end.set(point);
			lines.push_back(lineTemp);
		}
	}
}

void Strand::reset()
{
	lines.clear();
	points.clear();
	addLine();
}

void Strand::setInfluence(float value)
{
	if (value >= 0) {
		influence = value;
	}
	else {
		influence = 0;
	}
}

const float & Strand::getInfluence()
{
	return influence;
}

const ofPoint & Strand::getPoint(int offset)
{

	if (points.size() > offset) {
		return points[points.size() - offset];
	}
	return points[0];
}

