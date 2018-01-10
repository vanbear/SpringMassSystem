#pragma once
class Spring
{
public:
	Spring(int i, int j, float length);
	~Spring();
	void draw();

	int i, j; // indeksy punktów
	float length, nx, ny; //d³ugoœæ i normalne
};

