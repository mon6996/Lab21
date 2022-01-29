#include<iostream>
#include<cmath>

using namespace std;

struct Rect
{
	double x,y,w,h;
};

double overlap(Rect *r1, Rect *r2)
{
	double w = 0, h = 0;
	if(r1->w + r1->x > r2->x)
	{
		if(r1->x + r1->w < r2->x + r2->w)
			w = r1->w - abs(r2->x - r1->x);
		else
			w = r2->w;
		if(r1->y + r1->h < r2->y + r2->h)
			h = r2->h - abs(r2->y - r1->y);
		else
			h = r2->h;
	}
	return w*h;
}

int main()
{
	Rect R1 = {1, 1, 5, 5};
	Rect R2 = {7, 2, 3, 3};
	cout << overlap(&R1, &R2);

	return 0;
}