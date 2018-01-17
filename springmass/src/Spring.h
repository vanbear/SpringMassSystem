#pragma once

#include <vector>
#include "Point.h"

class Spring
{
public:
	Spring(int i, int j, std::vector<Point*> &points);
	~Spring();
	void draw();

	int i, j; // indeksy punkt�w
	float length, nx, ny; //d�ugo�� i normalne
};

