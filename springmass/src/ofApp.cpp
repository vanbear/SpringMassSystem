#include "ofApp.h"
#include "Point.h"
#include "Spring.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 0);
	ofSetFrameRate(60);

	G = 9.8;
	KS = 1755.0;
	KD = 35.0;

	myPoints.push_back(new Point(ofGetWidth()/2, 100, 1)); 
	myPoints.push_back(new Point(200, 200, 1));
	myPoints.push_back(new Point(300, 200, 1));
	myPoints.push_back(new Point(400, 400, 1));

	mySprings.push_back(new Spring(0, 1, 20));
	mySprings.push_back(new Spring(0, 2, 50));
	mySprings.push_back(new Spring(2, 3, 100));

	myPoints[0]->isStatic = true;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	// grawitacja
	for (auto &p : myPoints)
		p->v_forces.y = p->mass*G;

	// si³a sprê¿ystoœci
	for (auto &s : mySprings)
	{
		// liczenie odleg³oœci miêdzy po³¹czonymi punktami
		Point *p1 = myPoints[s->i];		Point *p2 = myPoints[s->j];
		ofVec2f pos1 = p1->v_position;	ofVec2f pos2 = p2->v_position;
		float dist = pos1.distance(pos2);

		if (dist != 0)
		{
			//float vn = p1->v_velocity.distance(p2->v_velocity);
			ofVec2f vn = p1->v_velocity - p2->v_velocity;	// ró¿nica prêdkoœci
			ofVec2f dpos = pos1 - pos2;						// ró¿nica po³o¿eñ
			
			// si³y
			//ofVec2f f = (dist - s->length) * (dpos / dist) * KS + vn.dot(dpos / dist) * KD;
			ofVec2f f = (dist - s->length) * KS + (vn * dpos) * KD / dist;
			ofVec2f F = f * (dpos / dist);
			p1->v_forces -= F;
			p2->v_forces += F;
		}
	}

	// aktualizacja po³o¿eñ
	for (auto &p : myPoints)
	{
		p->updateVerlet();
	}
}

//--------------------------------------------------------------
void ofApp::draw(){

	for (auto &p : myPoints)
	{
		p->draw();
	}
	drawAllSprings();

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


void ofApp::drawAllSprings()
{
	for (auto s : mySprings)
	{
		ofVec2f pos1 = myPoints[s->i]->v_position;
		ofVec2f pos2 = myPoints[s->j]->v_position;
		ofDrawLine(pos1.x, pos1.y, pos2.x, pos2.y);
	}
}