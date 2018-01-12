#include "ofApp.h"
#include "Point.h"
#include "Spring.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(0, 0, 0);

	G = 0.01;
	KS = .00001;
	KD = .01;

	myPoints.push_back(new Point(100, 100, 1)); 
	myPoints.push_back(new Point(200, 200, .1));
	myPoints.push_back(new Point(300, 300, .1));
	myPoints.push_back(new Point(400, 400, .01));

	mySprings.push_back(new Spring(0, 1, 20));
	mySprings.push_back(new Spring(0, 2, 50));
	mySprings.push_back(new Spring(2, 3, 10));

	myPoints[0]->isStatic = true;
}

//--------------------------------------------------------------
void ofApp::update(){
	
	// grawitacja
	for (auto &p : myPoints)
		if (!p->isStatic)
			p->fy = p->mass*G;
		else
			p->fy = 0;

	for (auto &s : mySprings)
	{
		// liczenie odleg³oœci miêdzy po³¹czonymi punktami
		float x1 = myPoints[s->i]->x;
		float x2 = myPoints[s->j]->x;
		float y1 = myPoints[s->i]->y;
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
			float fx = ((x1 - x2) / dl)*f;
			float fy = ((y1 - y2) / dl)*f;

			if (!myPoints[s->i]->isStatic)
			{
				myPoints[s->i]->fx -= fx;
				myPoints[s->i]->fy -= fy;
			}
				
			if (!myPoints[s->j]->isStatic)
			{
				myPoints[s->j]->fx += fx;
				myPoints[s->j]->fy += fy;
			}

			std::cout << "x " << myPoints[s->i]->x << endl;
			std::cout << "fx " << myPoints[s->i]->fx << endl;
			
		}
		
	}


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
		float x1 = myPoints[s->i]->x;
		float x2 = myPoints[s->j]->x;
		float y1 = myPoints[s->i]->y;
		float y2 = myPoints[s->j]->y;
		ofDrawLine(x1,y1,x2,y2);
	}
}