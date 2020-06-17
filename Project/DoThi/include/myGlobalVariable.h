#pragma once
#define MAX 20
#define BK 25
#define MAX_VALUE 19981
#define Round(a) (int)(a + 0.5)

const int BG_COLOR_MENU = 7;
const int BG_COLOR_VERTEX = 2;
const int BG_COLOR_GRAPH = 8;
const int COLOR_TEXT = 0;
const int CORNER_COLOR_BUTTON = 8;
const int CORNER_COLOR_BUTTON_SELECTED = 4;

//Working zone.
int wzLEFT = 470;
int wzTOP = 30;
int wzRIGHT = 1255;
int wzBOTTOM = 480;

struct Vertex
{
	int x;
	int y;
	char *name;
};

int nVertex = 0;
Vertex graph[MAX];
//int nPointDDA = 0;
//Dinh pointDDA[1000];
int trace[MAX];
int MatrixWeight[MAX][MAX];
string fileName = "";
