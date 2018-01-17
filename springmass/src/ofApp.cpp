#include "ofApp.h"
#include "Point.h"
#include "Spring.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 0);
	ofSetFrameRate(60);

	G = 90;
	KS = 1755.0;
	KD = 35.0;
	counter = 0;
	pointSize = 5;

	// nowy punkt (x, y, masa, isStatic)
	myPoints.push_back(new Point(ofGetWidth() / 2, 100, 1, true));
	myPoints.push_back(new Point(ofGetWidth() / 2 - 10, 120, 1, false));
	myPoints.push_back(new Point(ofGetWidth() / 2 - 20, 140, 1, false));
	myPoints.push_back(new Point(ofGetWidth() / 2 - 30, 160, 1, false));
	myPoints.push_back(new Point(ofGetWidth() / 2 - 40, 180, 1, false));

	mySprings.push_back(new Spring(0, 1, myPoints));
	mySprings.push_back(new Spring(1, 2, myPoints));
	mySprings.push_back(new Spring(2, 3, myPoints));
	mySprings.push_back(new Spring(3, 4, myPoints));

}

//--------------------------------------------------------------
void ofApp::update(){
	
	// grawitacja
	for (auto &p : myPoints)
	{
		p->v_forces.y = p->m_mass*G;
		p->v_forces.x = 0;
	}
		

	// si³a sprê¿ystoœci
	for (auto &s : mySprings)
	{
		// liczenie odleg³oœci miêdzy po³¹czonymi punktami
		Point *p1 = myPoints[s->i];		Point *p2 = myPoints[s->j];
		ofVec2f pos1 = p1->v_position;	ofVec2f pos2 = p2->v_position;
		float dist = pos1.distance(pos2);

		if (dist != 0)
		{
			// prêdkoœci z po³o¿eñ 
			p1->v_velocity = p1->v_position - p1->v_positionOld;
			p2->v_velocity = p2->v_position - p2->v_positionOld;
			ofVec2f vn = p1->v_velocity - p2->v_velocity;	// ró¿nica prêdkoœci
			ofVec2f dpos = pos1 - pos2;						// ró¿nica po³o¿eñ
			
			// si³y
			ofVec2f f = (dist - s->length) * KS + (vn * dpos) * KD / dist;
			ofVec2f F = f * (dpos / dist);
			p1->v_forces -= F;
			p2->v_forces += F;
		}
	}

	// aktualizacja po³o¿eñ
	if (counter < 2)
		for (auto &p : myPoints)
		{
			p->updateEuler();
			counter++;
		}
	else
		for (auto &p : myPoints)
		{
			p->updateVerlet();
		}
}

//--------------------------------------------------------------
void ofApp::draw(){

	drawPoints();
	drawAllSprings();
	drawVelocities();

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
	ofVec2f mousePos = ofVec2f(x, y); // po³o¿enie kursora
	for (auto &p : myPoints)
	{
		ofVec2f tempPos = mousePos - p->v_position;
		float dist = tempPos.length();

		if (dist < pointSize)
		{
			p->v_position = { (float)x,(float)y };
			p->v_forces = { 0,0 };
			p->v_velocity = { 0,0 };
		}
	}
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
	for (auto const& s : mySprings)
	{
		ofVec2f pos1 = myPoints[s->i]->v_position;
		ofVec2f pos2 = myPoints[s->j]->v_position;
		ofSetLineWidth(5);
		ofDrawLine(pos1,pos2);
		ofSetLineWidth(1);
	}
}

void ofApp::drawVelocities()
{
	for (auto const &p : myPoints)
	{
		ofSetColor(255, 0, 0);
		ofVec2f pos = p->v_position;
		ofDrawLine(pos, pos + p->v_velocity*10);
		ofSetColor(255, 255, 255);
	}
}

void ofApp::drawPoints()
{
	for (auto const &p : myPoints)
		ofDrawCircle(p->v_position, pointSize);
}