#pragma once

#include "ofMain.h"
#include "Point.h"
#include "Spring.h"
#include "Player.h"
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
		void drawVelocities(); // pr�dko�ci
		void drawPoints();	   // punkty
		// tworzenie linki
		void createLine(float x, float y);

		//wektory
		vector<Point*> myPoints;
		vector<Spring*> mySprings;
		Point *clickPoint;
		Point *selectedPoint;
		ofVec2f dragForce;
		Player *player;

		// sta�e
		float G;		// grawitacja
		float KS, KD;	// jakie� tam wsp�czynniki

		// konfiguracja sceny
		float pointSize; // rozmiar punkt�w
		float groundHeight; // wysoko�� pod�o�a
		ofColor springColor; // kolor liny
		ofTrueTypeFont tarzanFont; // czcionka 

		// obs�uga programu
		int counter;	// licznik krok�w
		bool debug; // false - off, true - on
		bool keyIsDown[255]; // obs�uga klawiatury

};
