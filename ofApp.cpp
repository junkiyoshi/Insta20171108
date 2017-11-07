#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(255);
	ofSetWindowTitle("Insta");

	ofSetColor(0);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	float x, y, z;
	float noise_value;
	ofVec3f prev_point;

	for (int radius = 50; radius < 1024; radius += 10) {
		for (int deg = 0; deg <= 360; deg += 1) {
			x = radius * cos(deg * DEG_TO_RAD);
			y = radius * sin(deg * DEG_TO_RAD);
			z = 100 * ofNoise(x * 0.0025, y * 0.0025, ofGetFrameNum() * 0.015 - radius * 0.005);

			if (deg > 0) {
				ofDrawLine(prev_point, ofVec3f(x, y, z));
			}

			prev_point = ofVec3f(x, y, z);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}