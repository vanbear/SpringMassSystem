#pragma once
class Spring
{
public:
	Spring(int i, int j, float length);
	~Spring();
	void draw();

	int i, j; // indeksy punkt�w
	float length, nx, ny; //d�ugo�� i normalne
};

