#include <graphics.h>
#include <iostream>
#include <sstream>
#include <math.h>

#include "include/myHelper.h"
#include "include/myGlobalVariable.h"

using namespace std;

void renewGraph();
void defaultButton(Dinh a)
{
	int c = getcolor();
	setcolor(CORNER_COLOR_BUTTON);
	setlinestyle(0, 0, 1);
	setfillstyle(1, BG_COLOR_MENU);
	bar(a.x, a.y, a.x + 101, a.y + 41);
	rectangle(a.x, a.y, a.x + 101, a.y + 41);
	setcolor(0);
	setbkcolor(BG_COLOR_MENU);
	settextstyle(2, 0, 5);
	outtextxy(a.x + 18, a.y + 14, a.name);
	setcolor(c);
	setfillstyle(1, c);
}
void customButton(Dinh a)
{
	int c = getcolor();
	setcolor(15);
	setlinestyle(0, 0, 1);
	setfillstyle(1, CORNER_COLOR_BUTTON_SELECTED);
	bar(a.x, a.y, a.x + 101, a.y + 41);
	rectangle(a.x, a.y, a.x + 101, a.y + 41);
	setbkcolor(CORNER_COLOR_BUTTON_SELECTED);
	settextstyle(2, 0, 5);
	outtextxy(a.x + 18, a.y + 14, a.name);
	setcolor(c);
	setfillstyle(1, c);
}
void systemMenu(Dinh systemMenu[3])
{
	const int we = 111;
	const int hi = 51;
	setfillstyle(1, BG_COLOR_MENU);
	bar(20, 245, 353, 298);
	for (int i = 0; i < 3; i++)
	{
		systemMenu[i].x = we * i + 26;
		systemMenu[i].y = hi + 201;
		//		systemMenu[i].name = new char[10];
	}
	systemMenu[0].name = "MO FILE";
	systemMenu[1].name = "LUU FILE";
	systemMenu[2].name = "XOA DT";

	for (int i = 0; i < 3; i++)
	{
		defaultButton(systemMenu[i]);
	}
	setlinestyle(0, 0, 1);
	setcolor(CORNER_COLOR_BUTTON_SELECTED);
	rectangle(20, 245, 353, 298);
}
void funcMenu(Dinh menu[10])
{
	const int we = 111;
	const int hi = 51;
	int count = 0;
	setfillstyle(1, BG_COLOR_MENU);
	bar(20, 30, 353, 238);
	for (int i = 0; i < 10;)
	{
		for (int j = 0; j < 3 && i < 10; j++)
		{
			menu[i].x = we * j + 26;
			menu[i].y = hi * count + 41;
			menu[i].name = new char[10];
			i++;
		}
		count++;
	}
	menu[0].name = "DFS";
	menu[1].name = "BFS";
	menu[2].name = "TPLT";
	menu[3].name = "X->Y";
	menu[4].name = "DINH TRU";
	menu[5].name = "DINH THAT";
	menu[6].name = "CANH CAU";
	menu[7].name = "HAMILTON";
	menu[8].name = "EULER";
	menu[9].name = "TOPO SORT";
	for (int i = 0; i < 10; i++)
	{
		defaultButton(menu[i]);
	}
	setcolor(CORNER_COLOR_BUTTON_SELECTED);
	rectangle(20, 30, 353, 238);
}
void controlMenu(Dinh file[5])
{
	const int we = 111;
	const int hi = 81;
	setfillstyle(1, BG_COLOR_MENU);
	bar(357, 30, 466, 480);
	for (int i = 0; i < 5; i++)
	{
		file[i].x = 361;
		file[i].y = hi * i + 61;
		file[i].name = new char[10];
	}
	file[0].name = "TAO DINH";
	file[1].name = "XOA DINH";
	file[2].name = "TAO CUNG";
	file[3].name = "DICH DINH";
	file[4].name = "DOI TEN";
	for (int i = 0; i < 5; i++)
	{
		defaultButton(file[i]);
	}
	setcolor(CORNER_COLOR_BUTTON_SELECTED);
	rectangle(357, 30, 466, 480);
}
void matrixTTTitle()
{
	const int dai = 330;
	setfillstyle(1, BG_COLOR_MENU);
	setlinestyle(0, 0, 1);
	bar(20, 303, 353, 353);
	setcolor(CORNER_COLOR_BUTTON_SELECTED);
	rectangle(20, 303, 353, 353);
	setbkcolor(BG_COLOR_MENU);
	settextstyle(2, 0, 5);
	setcolor(0);
	outtextxy(130, 310, "MA TRAN TRONG SO");
}

int coverStringToInt(string value)
{
	int result;
	stringstream ss;
	ss << value;
	ss >> result;
	return result;
}
void drawMatrixTT()
{
	setlinestyle(0, 0, 1);
	setfillstyle(1, BG_COLOR_MENU);
	bar(20, 358, 353, 688);
	setcolor(CORNER_COLOR_BUTTON_SELECTED);
	rectangle(20, 358, 353, 688);

	int D = 30;
	const int dai = 333;
	int xx = 23;
	int yy = 365;
	int xNew = 33;
	string temp;
	if (nDinh <= 10 && nDinh != 0)
	{
		for (int i = 0; i <= nDinh; i++)
		{
			for (int j = 0; j < nDinh; j++)
			{
				setfillstyle(1, 0);
				line(xNew + j * D + 28, 25 + dai, xNew + j * D + 28, 23 + dai + (nDinh + 1) * D);
				if (i == 0)
				{
					setbkcolor(BG_COLOR_MENU);
					setcolor(0);
					outtextxy(xNew + (j + 1) * D, yy, graph[j].name);
				}
				else
				{
					temp = coverIntToString(MatrixWeight[i - 1][j]);
					outtextxy(xx, yy + i * D, graph[i - 1].name);
					outtextxy(xNew + (j + 1) * D, yy + i * D, &temp[0]);
				}
			}
			setfillstyle(1, 0);
			line(xNew + nDinh * D + 31, 25 + dai, xNew + nDinh * D + 31, 23 + dai + (nDinh + 1) * D);
			line(20, 355 + 30 + i * 30, 35 + (nDinh + 1) * 30, 355 + 30 + i * 30);
		}
	}
}
void drawTutorial()
{
	setlinestyle(0, 0, 1);
	setcolor(CORNER_COLOR_BUTTON_SELECTED);
	setfillstyle(1, BG_COLOR_MENU);
	bar(357, 500, 1255, 688);
	line(357, 500, 370, 500);
	line(430, 500, 1255, 500);
	line(357, 500, 357, 688);
	line(357, 688, 1255, 688);
	line(1255, 688, 1255, 500);
	setcolor(0);
	setbkcolor(BG_COLOR_MENU);
	settextstyle(2, 0, 5);
	outtextxy(370, 493, "HUONG DAN");
	settextstyle(8, 0, 1);
}
void drawGraph()
{
	setfillstyle(1, 8);
	bar(470, 30, 1255, 480);
	setcolor(CORNER_COLOR_BUTTON_SELECTED);
	rectangle(470, 30, 1255, 480);
	drawTutorial();
}

void clearMouseClick()
{
	clearmouseclick(WM_RBUTTONUP);
	clearmouseclick(WM_RBUTTONDOWN);
	clearmouseclick(WM_LBUTTONUP);
	clearmouseclick(WM_LBUTTONDOWN);
}
void drawUI(Dinh a[][10])
{
	setfillstyle(1, 7);
	bar(1, 1, 1279, 719);
	funcMenu(a[0]);
	systemMenu(a[1]);
	controlMenu(a[2]);
	matrixTTTitle();
	drawMatrixTT();
	drawGraph();
}

void drawDinh()
{
	for (int i = 0; i < nDinh; i++)
	{
		setfillstyle(1, BG_COLOR_DINH);
		setcolor(BG_COLOR_DINH);
		pieslice(graph[i].x, graph[i].y, 0, 0, BK);
		setcolor(15);
		setbkcolor(BG_COLOR_DINH);
		outtextxy(graph[i].x - 15, graph[i].y - 12, graph[i].name);
	}
	drawMatrixTT();
}


string removeCharater(string a)
{
	string s = "";
	for (int i = 0; i < a.length() - 1; i++)
		s += a[i];
	return s;
}

char *createNameDinh()
{
	drawTutorial();
	char c;
	char *result = new char[3];
	string s;
	int i = 0;
	outtextxy(370, 520, "Nhap toi da 3 chu, nhan ENTER de ket thuc");
	outtextxy(370, 540, "Ten dinh: ");
	outtextxy(480, 540, &s[0]);
	do
	{

		fflush(stdin);
		while (!kbhit())
			;
		c = getch();
		if (c != 13 && c != 8 && i < 3 && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)))
		{
			i++;
			s += c;
		}
		else if (c == 8 && i > 0)
		{
			i--;
			s = removeCharater(s);
		}

		result = &s[0];

		drawTutorial();
		outtextxy(370, 520, "Nhap toi da 3 chu, nhan ENTER de ket thuc");
		outtextxy(370, 540, "Ten dinh: ");
		outtextxy(480, 540, &s[0]);

	} while (c != 13 || i == 0);
	return strupr(result);
}

void changeColorDinh(int position, int color)
{
	setfillstyle(1, color);
	setcolor(color);
	pieslice(graph[position].x, graph[position].y, 0, 0, BK);
	setcolor(15);
	setbkcolor(color);
	outtextxy(graph[position].x - 15, graph[position].y - 12, graph[position].name);
}

Dinh drawArrow(int posStart, int posEnd, int color)
{
	Dinh dinhtrongso;
	setcolor(color);

	int x1 = graph[posStart].x;
	int x2 =  graph[posEnd].x;
	int y1 =  graph[posStart].y;
	int y2 =  graph[posEnd].y;

	int xG, yG, xVTPT, yVTPT, xG1, yG1, lenVTPT, lenAG;
	float k;
	xG = Round((x1 + x2) / 2.0f);
	yG = Round((y1 + y2) / 2.0f);
	xVTPT = y1 - y2;
	yVTPT = x2 - x1;
	lenVTPT = Round(sqrt(pow(xVTPT, 2) + pow(yVTPT, 2)));
	lenAG = distanceTwoPoint(x1, y1, xG, yG);
	k = (float)lenAG / lenVTPT;
	xG1 = Round(xG + k * xVTPT);
	yG1 = Round(yG + k * yVTPT);
	
	if (MatrixWeight[posEnd][posStart]==0 ||posStart<posEnd )
	{
		int px[2] = {x1, x2};
		int py[2] = {y1, y2};
		dinhtrongso.x = Round((x1 + x2) / 2.0f);
		dinhtrongso.y = Round((y1 + y2) / 2.0f);
		
		drawBezier(px, py, 2, color,dinhtrongso,MatrixWeight[posStart][posEnd]);
	}
	else
	{
		int px[3] = {x1, xG1, x2};
		int py[3] = {y1, yG1, y2};
		dinhtrongso.x = Round((xG1 + xG) / 2.0f);
		dinhtrongso.y = Round((yG1 + yG) / 2.0f);
		
		drawBezier(px, py, 3, color,dinhtrongso,MatrixWeight[posStart][posEnd]);
	
	}
	changeColorDinh(posStart, 2);
	changeColorDinh(posEnd, 2);
	return dinhtrongso;
}
void drawAllCanh()
{
	for (int i = 0; i < nDinh; ++i)
		for (int j = 0; j < nDinh; ++j)
			if (MatrixWeight[i][j] != 0)
				drawArrow(i, j, 15);
}

int createTrongSo()
{
	drawTutorial();
	int kq;
	char c;
	string s;
	outtextxy(370, 520, "Nhap toi da 3 chu so, nhan ENTER de ket thuc");
	outtextxy(370, 540, "Trong so thuoc 001 den 999");
	outtextxy(370, 560, "Nhap trong so: ");
	outtextxy(370, 580, "Nhap trong so bang 0 neu muon xoa canh");
	outtextxy(525, 560, &s[0]);

	int i = 0;
	do
	{
		fflush(stdin);
		while (!kbhit())
			;
		c = getch();
		if (c != 13 && c != 8 && i < 3 && toupper(c) >= '0' && toupper(c) <= '9')
		{
			i++;
			s += c;
		}
		else if (c == 8 && i > 0)
		{
			i--;
			s = removeCharater(s);
		}
		drawTutorial();
		outtextxy(370, 520, "Nhap toi da 3 chu so, nhan ENTER de ket thuc");
		outtextxy(370, 540, "Trong so thuoc 001 den 999");
		outtextxy(370, 560, "Nhap trong so: ");
		outtextxy(370, 580, "Nhap trong so bang 0 neu muon xoa canh");
		outtextxy(525, 560, &s[0]);
	} while (c != 13 || i == 0);
	kq = coverStringToInt(s);
	return kq;
}

void createDinh()
{
	while (nDinh <= MAX - 1)
	{
		delay(1);
		drawTutorial();
		settextstyle(8, 0, 1);
		outtextxy(370, 520, "Click chuot de them dinh");
		delay(1);
		int x, y;

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (x >= (470 + BK) && x <= (1255 - BK) && y >= (30 + BK) && y <= (480 - BK) && x != -1 && y != -1 && isDinh(x, y) == -1)
			{
				graph[nDinh].x = x;
				graph[nDinh].y = y;

				setfillstyle(1, BG_COLOR_DINH);
				setcolor(BG_COLOR_DINH);
				pieslice(graph[nDinh].x, graph[nDinh].y, 0, 0, BK);
				graph[nDinh].name = new char[3];
			back:
				char *result = new char[3];
				result = createNameDinh();

				if (nDinh > 0)
				{
					for (int i = 0; i < nDinh; i++)
					{
						if (strcmp(result, graph[i].name) == 0)
						{
							goto back;
						}
					}
				}

				for (int i = 0; i < 4; i++)
				{
					graph[nDinh].name[i] = result[i];
				}

				setcolor(15);
				setbkcolor(BG_COLOR_DINH);
				outtextxy(graph[nDinh].x - 15, graph[nDinh].y - 12, graph[nDinh].name);
				nDinh++;
				drawMatrixTT();
			}
		}
		else if (ismouseclick(WM_RBUTTONDOWN))
		{
			renewGraph();
			clearMouseClick();
			break;
		}
	};
}
void createCanh()
{
	clearMouseClick();
	drawTutorial();
	outtextxy(370, 520, "Click vao dinh bat dau");
	int x, y;
	int startPosition, endPosition;

	while (isDinh(x, y) == -1 && x != -1 && y != -1)
	{
		while (true)
		{
			delay(1);
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, x, y);
				break;
			}
		}
	}
	startPosition = isDinh(x, y);
	changeColorDinh(isDinh(x, y), 12);

	clearMouseClick();
	drawTutorial();
	x = 0;
	y = 0;
	outtextxy(370, 520, "Click vao dinh ket thuc");
	
	while (isDinh(x, y) == -1 || isStartDinh(x,y,graph[startPosition])==1)
	{
		while (true)
		{
			delay(1);
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, x, y);
				break;
			}
		}
	}
	endPosition = isDinh(x, y);
	changeColorDinh(isDinh(x, y), 12);
	MatrixWeight[startPosition][endPosition]=0;
	Dinh dinhtrongso = drawArrow(startPosition, endPosition, 15);

	changeColorDinh(startPosition, 2);
	changeColorDinh(endPosition, 2);

	int trongSo = createTrongSo();
	if (trongSo == 0)
	{
		MatrixWeight[startPosition][endPosition] = 0;
		drawArrow(startPosition, endPosition, CORNER_COLOR_BUTTON);
	}
	else
		MatrixWeight[startPosition][endPosition] = trongSo;
	
	drawTrongSo(dinhtrongso, trongSo);
	drawMatrixTT();
	//renewGraph();
}
void processFunction(int type)
{
	switch (type)
	{
	case 1:
		//DFS
		break;
	case 2:
		//BFS
		break;
	case 3:
		//X->Y
		break;
	case 4:
		//Dinh TRU
		break;
	case 5:
		//DINH THAT
		break;
	case 6:
		//CANH CAU
		break;
	case 7:
		//HAMILTON
		break;
	case 8:
		//EULER
		break;
	case 9:
		//TOPOSHORT
		break;
	case 10:
		//TPLT
		break;
	case 11:
		//OPEN FILE
		break;
	case 12:
		//SAVE FILE
		break;
	case 13:
		//CLEAR GRAPH
		break;
	case 14:
		if (nDinh < MAX)
		{
			drawTutorial();
			createDinh();
			clearMouseClick();
		}
		else
		{
			drawTutorial();
			outtextxy(370, 520, "So luong dinh vuot qua so luong cho phep");
			break;
		}
		break;
	case 15:
		//XOA DINH
		break;
	case 16:
		//TAO CUNG
		if (nDinh >= 2)
		{
			drawTutorial();
			createCanh();
			clearMouseClick();
		}
		else
		{
			drawTutorial();
			outtextxy(370, 520, "Khong du dinh");
			break;
		}
		break;
	case 17:

		//DICH DINH
		break;
	case 18:
		//DOI TEN
		break;
	}
}
bool chooseFunction(Dinh s)
{
	int x, y;

	getmouseclick(WM_RBUTTONDOWN, x, y);
	if ((x != -1 && y != -1) && (x >= s.x && x <= s.x + 101) && (y >= s.y && y <= s.y + 41))
	{
		return true;
	}
	return false;
}
void addMouse(Dinh s, int &x, int &y, bool &isSelected, int type)
{
	if ((x != -1 && y != -1) && (x >= s.x && x <= s.x + 101) && (y >= s.y && y <= s.y + 41))
	{
		customButton(s);
		if (chooseFunction(s))
		{
			processFunction(type);
		}
		//isSelected=true;
	}
	else if ((x != -1 && y != -1) && (!(x >= s.x && x <= s.x + 100) || !(y >= s.y && y <= s.y + 40)))
	{
		defaultButton(s);
	}

	//	clearMouseClick();
}
void processMouse(Dinh s[][10])
{
	int x, y = 0;
	bool isSelected = false;
	while (1)
	{
		delay(1);
		getmouseclick(WM_MOUSEMOVE, x, y);

		addMouse(s[0][0], x, y, isSelected, 1);
		addMouse(s[0][1], x, y, isSelected, 2);
		addMouse(s[0][2], x, y, isSelected, 3);
		addMouse(s[0][3], x, y, isSelected, 4);
		addMouse(s[0][4], x, y, isSelected, 5);
		addMouse(s[0][5], x, y, isSelected, 6);
		addMouse(s[0][6], x, y, isSelected, 7);
		addMouse(s[0][7], x, y, isSelected, 8);
		addMouse(s[0][8], x, y, isSelected, 9);
		addMouse(s[0][9], x, y, isSelected, 10);
		addMouse(s[1][0], x, y, isSelected, 11);
		addMouse(s[1][1], x, y, isSelected, 12);
		addMouse(s[1][2], x, y, isSelected, 13);
		addMouse(s[2][0], x, y, isSelected, 14);
		addMouse(s[2][1], x, y, isSelected, 15);
		addMouse(s[2][2], x, y, isSelected, 16);
		addMouse(s[2][3], x, y, isSelected, 17);
		addMouse(s[2][4], x, y, isSelected, 18);
	}
}

void initMatrixWeight()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			MatrixWeight[i][j] = 0;
		}
	}
}
void renewGraph()
{
	drawGraph();
	drawDinh();
	drawAllCanh();
}
int main(int argc, char *argv[])
{
	Dinh a[3][10];
	initwindow(1280, 720); // init window graphics						// set background
	cleardevice();
	drawUI(a);
	initMatrixWeight();
	processMouse(a);
	while (!kbhit())
		delay(1); // pause screen
	getch();
	closegraph();
	return 0;
}
