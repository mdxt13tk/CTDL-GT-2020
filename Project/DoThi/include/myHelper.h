#include <iostream>
#include <math.h>
using namespace std;

int calFactorial(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result = result * i;
	}
	return result;
}

int calCombonation(int k, int n)
{
	return calFactorial(n) / (calFactorial(n - k) * calFactorial(k));
}

void drawBezier(int px[], int py[], int color, int n){
	float t, x, y;
	int i;
	n=n-1;
	for (t = 0; t <= 1; t = t + 0.0001f)
	{
		x = 0;
		y = 0;
		for (i = 0; i <= n; i++)
		{
			x = x + (calCombonation(i, n) * pow(1 - t, n - i) * pow(t, i) * px[i]);
			y = y + (calCombonation(i, n) * pow(1 - t, n - i) * pow(t, i) * py[i]);
		}
		putpixel(x,y,color);
	}
}