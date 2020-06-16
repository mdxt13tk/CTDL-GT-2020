#pragma once

#include <iostream>
#include <math.h>
#include <graphics.h>
using namespace std;

#include "myGlobalVariable.h"

//declare
int calFactorial(int);
float calCombonation(int, int);
int distanceTwoPoint(int, int, int, int);
int isVertex(int, int);
void drawBezierLine(int, int, int, int);
void drawTriangle(int, int, int, int, int);

int calFactorial(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result = result * i;
	}
	return result;
}

float calCombonation(int k, int n)
{
	return (float)calFactorial(n) / (calFactorial(n - k) * calFactorial(k));
}

void drawBezierLine(int px[], int py[], int n, int color)
{
	float t, x, y;
	int i, xTriangle = 0, yTriangle = 0;
	n = n - 1;
	for (t = 0; t <= 1; t = t + 0.001f)
	{
		x = 0;
		y = 0;
		for (i = 0; i <= n; i++)
		{
			x = x + (calCombonation(i, n) * pow(1 - t, n - i) * pow(t, i) * px[i]);
			y = y + (calCombonation(i, n) * pow(1 - t, n - i) * pow(t, i) * py[i]);
		}
		x = Round(x);
		y = Round(y);
		if (distanceTwoPoint(x, y, px[n], py[n]) > BK && distanceTwoPoint(x, y, px[0], py[0]) >= BK)
		{
			putpixel(x, y, color);
		}
		else if (distanceTwoPoint(x, y, px[n], py[n]) == BK)
		{
			xTriangle = x;
			yTriangle = y;
		}
	}
	drawTriangle(xTriangle, yTriangle, px[n], py[n], color);
}

void drawTriangle(int x, int y, int xDinh, int yDinh, int color)
{
	setlinestyle(SOLID_LINE, 0, 2);
	setfillstyle(SOLID_FILL, color);

	int xtemp, ytemp, x1, y1, x2, y2, xVTPT, yVTPT, lenVTPT;
	float k1, k2;
	k1 = 13.0f / BK;
	xtemp = Round(x + k1 * (x - xDinh));
	ytemp = Round(y + k1 * (y - yDinh));
	xVTPT = yDinh - y;
	yVTPT = x - xDinh;
	lenVTPT = Round(sqrt(pow(xVTPT, 2) + pow(yVTPT, 2)));
	k2 = 7.0f / lenVTPT;
	x1 = Round(xtemp + k2 * xVTPT);
	y1 = Round(ytemp + k2 * yVTPT);
	x2 = Round(abs(xtemp + (-k2) * xVTPT));
	y2 = Round(abs(ytemp + (-k2) * yVTPT));
	int points[] = {x, y, x1, y1, x2, y2, x, y};

	setcolor(color);
	fillpoly(4, points);
}

int distanceTwoPoint(int x1, int y1, int x2, int y2)
{
	return Round(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

int isVertex(int x, int y)
{
	for (int i = 0; i < nVertex; i++)
	{
		if (distanceTwoPoint(x, y, graph[i].x, graph[i].y) <= BK)
		{
			return i;
		}
	}
	return -1;
}
bool isStartVertex(int x, int y, Vertex a)
{
	if (distanceTwoPoint(x, y, a.x, a.y) <= BK)
	{
		return true;
	}
	return false;
}
string coverIntToString(int number)
{
	string result;
	stringstream ss;
	ss << number;
	ss >> result;
	return result;
}
