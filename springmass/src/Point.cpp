#include "Point.h"
#include <ofGraphics.h>


Point::Point(float x, float y, float mass)
{
	this->v_position = { x,y };
	this->v_positionOld = { x,y };
	this->v_velocity = { 0,0 };
	this->v_forces = { 0,0 };
	this->mass = mass;
	this->isStatic = false;
}

Point::~Point()
{
}


void Point::draw()
{
	ofDrawCircle(this->v_position, 5);
}

void Point::updateVerlet()
{
	if (!this->isStatic)
	{
		this->v_positionNew = 2 * this->v_position - this->v_positionOld + (0.01*0.01*this->v_forces / this->mass);
		this->v_positionOld = this->v_position;
		this->v_position = this->v_positionNew;
	}
}
