#pragma once
class Point
{
public:
	Point(float x, float y, float mass);
	~Point();
	void updatePosition();
	void draw();

	float x, y, vx, vy, fx, fy, mass; // po�o�enie, pr�dko��, si�y
	bool isStatic; // czy ma si� porusza�
};

