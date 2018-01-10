#include "Point.h"
#include <ofGraphics.h>


Point::Point(float x, float y, float mass)
{
	this->x = x;
	this->y = y;
	this->vx = 0;
	this->vy = 0;
	this->fx = 0;
	this->fy = 0;
	this->mass = mass;
}


Point::~Point()
{
}

void Point::updatePosition()
{
	this->vx += this->fx;
	this->vy += this->fy;

	this->x += this->vx;
	this->y += this->vy;
}

void Point::draw()
{
	ofDrawCircle(this->x, this->y, 5);
}
