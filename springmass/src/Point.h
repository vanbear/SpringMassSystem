#pragma once
class Point
{
public:
	Point(float x, float y, float mass);
	~Point();
	void updatePosition();
	void draw();

	float x, y, vx, vy, fx, fy, mass; // po³o¿enie, prêdkoœæ, si³y
	bool isStatic; // czy ma siê poruszaæ
};

