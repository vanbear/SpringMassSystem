#include "ofApp.h"
#include "Point.h"
#include "Spring.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 0);

	G = 0.01;

	myPoints.push_back(new Point(100, 100, 1));
	myPoints.push_back(new Point(200, 200, 1));

	mySprings.push_back(new Spring(0, 1, 100));
}

//--------------------------------------------------------------
void ofApp::update(){
	
	for (auto &s : mySprings)
	{
		// liczenie odleg³oœci miêdzy po³¹czonymi punktami
		float x1 = myPoints[s->i]->x;
		float x2 = myPoints[s->j]->y;
		float y1 = myPoints[s->i]->x;
		float y2 = myPoints[s->j]->y;

		float dl = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));

		// si³a sprê¿ystoœci
		if (s->length != 0)
		{
			float vx1 = myPoints[s->i]->vx;
			float vx2 = myPoints[s->j]->vx;
			float vx = vx1 - vx2;

			float vy1 = myPoints[s->i]->vy;
			float vy2 = myPoints[s->j]->vy;
			float vy = vy1 - vy2;

			//TODO
			float f = (dl - s->length)* KS + (vx*(x1 - x2) + vy*(y1 - y2))*KD / dl;
		}
	}


	for (auto &p : myPoints)
		p->fy = p->mass*G;
	myPoints[0]->vy = 0;

	for (auto &p : myPoints)
		p->updatePosition();

	std::cout << myPoints[0]->x << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){

	for (auto &p : myPoints)
	{
		p->draw();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
