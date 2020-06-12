#pragma once
#define MAX 20
#define BK 25
#define Round(a) (int)(a + 0.5)

const int BG_COLOR_MENU = 7;
const int BG_COLOR_DINH = 2;
const int CORNER_COLOR_BUTTON = 8;
const int CORNER_COLOR_BUTTON_SELECTED = 4;

struct Dinh
{
	int x;
	int y;
	char *name;
};

int nDinh = 0;
Dinh graph[MAX];
//int nPointDDA = 0;
//Dinh pointDDA[1000];
int MatrixWeight[MAX][MAX];