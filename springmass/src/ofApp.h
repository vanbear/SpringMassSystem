#pragma once

#include "ofMain.h"
#include "Point.h"
#include "Spring.h"
#include <ofVec2f.h>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		// rysowanie 
		void drawAllSprings(); // springi
		void drawVelocities(); // prêdkoœci
		void drawPoints();	   // punkty

		//wektory
		vector<Point*> myPoints;
		vector<Spring*> mySprings;
		Point *clickPoint;
		Point *selectedPoint;
		ofVec2f dragForce;

		//sta³e
		float G;		// grawitacja
		float KS, KD;	// jakieœ tam wspó³czynniki
		int counter;	// licznik kroków
		float pointSize; // rozmiar punktów

};
