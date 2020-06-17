#include <graphics.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <math.h>

#include "include/myHelper.h"
#include "include/myGlobalVariable.h"

using namespace std;

void drawTrongSo(Vertex dinhtrongso, int trongso);

void renewGraph();
bool isWorkingZone(int x, int y);
void defaultButton(Vertex a)
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
void customButton(Vertex a)
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
void systemMenu(Vertex systemMenu[3])
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
void funcMenu(Vertex menu[10])
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
void controlMenu(Vertex file[5])
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
	if (nVertex <= 10 && nVertex != 0)
	{
		for (int i = 0; i <= nVertex; i++)
		{
			for (int j = 0; j < nVertex; j++)
			{
				setfillstyle(1, 0);
				line(xNew + j * D + 28, 25 + dai, xNew + j * D + 28, 23 + dai + (nVertex + 1) * D);
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
			line(xNew + nVertex * D + 31, 25 + dai, xNew + nVertex * D + 31, 23 + dai + (nVertex + 1) * D);
			line(20, 355 + 30 + i * 30, 35 + (nVertex + 1) * 30, 355 + 30 + i * 30);
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
void drawWorkingZone()
{
	setfillstyle(1, 8);
	bar(470, 30, 1255, 480);
	setcolor(CORNER_COLOR_BUTTON_SELECTED);
	rectangle(wzLEFT, wzTOP, wzRIGHT, wzBOTTOM);
	drawTutorial();
}

void clearMouseClick()
{
	clearmouseclick(WM_RBUTTONUP);
	clearmouseclick(WM_RBUTTONDOWN);
	clearmouseclick(WM_LBUTTONUP);
	clearmouseclick(WM_LBUTTONDOWN);
}
void drawUI(Vertex a[][10])
{
	setfillstyle(1, 7);
	bar(1, 1, 1279, 719);
	funcMenu(a[0]);
	systemMenu(a[1]);
	controlMenu(a[2]);
	matrixTTTitle();
	drawMatrixTT();
	drawWorkingZone();
}

void drawAllVertex()
{
	for (int i = 0; i < nVertex; i++)
	{
		setfillstyle(1, BG_COLOR_VERTEX);
		setcolor(BG_COLOR_VERTEX);
		pieslice(graph[i].x, graph[i].y, 0, 0, BK);
		setcolor(15);
		setbkcolor(BG_COLOR_VERTEX);
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

char *createVertex()
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

void changeColorVertex(int position, int color)
{
	setfillstyle(1, color);
	setcolor(color);
	pieslice(graph[position].x, graph[position].y, 0, 0, BK);
	setcolor(15);
	setbkcolor(color);
	outtextxy(graph[position].x - 15, graph[position].y - 12, graph[position].name);
}

Vertex drawEdge(int posStart, int posEnd, int color)
{
	Vertex dinhtrongso;
	setcolor(color);

	int x1 = graph[posStart].x;
	int x2 = graph[posEnd].x;
	int y1 = graph[posStart].y;
	int y2 = graph[posEnd].y;

	int xG, yG, xVTPT, yVTPT, xG1, yG1, lenVTPT, lenAG;
	float k;
	xG = Round((x1 + x2) / 2.0f);
	yG = Round((y1 + y2) / 2.0f);
	xVTPT = y1 - y2;
	yVTPT = x2 - x1;
	lenVTPT = Round(sqrt(pow(xVTPT, 2) + pow(yVTPT, 2)));
	lenAG = distanceTwoPoint(x1, y1, xG, yG);
	k = (float)lenAG / (1.5 * lenVTPT);
	xG1 = Round(xG + k * xVTPT);
	yG1 = Round(yG + k * yVTPT);

	if (MatrixWeight[posEnd][posStart] == 0 || posStart < posEnd)
	{
		int px[2] = {x1, x2};
		int py[2] = {y1, y2};
		dinhtrongso.x = Round((x1 + x2) / 2.0f);
		dinhtrongso.y = Round((y1 + y2) / 2.0f);

		drawBezierLine(px, py, 2, color);
	}
	else
	{
		int xtrongso = Round((xG1 + xG) / 2.0f);
		int ytrongso = Round((yG1 + yG) / 2.0f);
		if (xtrongso <= wzLEFT || xtrongso >= wzRIGHT || ytrongso <= wzTOP || ytrongso >= wzBOTTOM)
		{
			xG1 = Round(xG - k * xVTPT);
			yG1 = Round(yG - k * yVTPT);
			xtrongso = Round((xG1 + xG) / 2.0f);
			ytrongso = Round((yG1 + yG) / 2.0f);
		}
		int px[3] = {x1, xG1, x2};
		int py[3] = {y1, yG1, y2};
		dinhtrongso.x = xtrongso;
		dinhtrongso.y = ytrongso;
		drawBezierLine(px, py, 3, color);
	}
	return dinhtrongso;
}

void drawTrongSo(Vertex dinhtrongso, int trongso)
{
	int x, y;
	int currentColor = getcolor();
	setbkcolor(15);
	if (trongso == 0)
	{
		setbkcolor(BG_COLOR_GRAPH);
		setcolor(BG_COLOR_GRAPH);
	}
	else
	{
		setcolor(COLOR_TEXT);
	}
	outtextxy(dinhtrongso.x, dinhtrongso.y, &coverIntToString(trongso)[0]);
	setcolor(currentColor);
}

void drawAllEdge()
{
	Vertex vertexweightnumber;
	for (int i = 0; i < nVertex; ++i)
		for (int j = 0; j < nVertex; ++j)
			if (MatrixWeight[i][j] != 0)
			{
				vertexweightnumber = drawEdge(i, j, 15);
				drawTrongSo(vertexweightnumber, MatrixWeight[i][j]);
			}
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

void drawVertex()
{
	while (nVertex <= MAX - 1)
	{
		delay(1);
		drawTutorial();
		settextstyle(8, 0, 1);
		outtextxy(370, 520, "Click chuot trai de them dinh");
		delay(1);
		int x, y;

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (isWorkingZone(x, y) && isVertex(x, y) == -1)
			{
				graph[nVertex].x = x;
				graph[nVertex].y = y;

				setfillstyle(1, BG_COLOR_VERTEX);
				setcolor(BG_COLOR_VERTEX);
				pieslice(graph[nVertex].x, graph[nVertex].y, 0, 0, BK);
				graph[nVertex].name = new char[3];
			back:
				char *result = new char[3];
				result = createVertex();

				if (nVertex > 0)
				{
					for (int i = 0; i < nVertex; i++)
					{
						if (strcmp(result, graph[i].name) == 0)
						{
							goto back;
						}
					}
				}

				for (int i = 0; i < 4; i++)
				{
					graph[nVertex].name[i] = result[i];
				}

				setcolor(15);
				setbkcolor(BG_COLOR_VERTEX);
				outtextxy(graph[nVertex].x - 15, graph[nVertex].y - 12, graph[nVertex].name);
				nVertex++;
				drawMatrixTT();
			}
			clearMouseClick();
		}
		else if (ismouseclick(WM_RBUTTONDOWN))
		{
			renewGraph();
			clearMouseClick();
			break;
		}
	};
}
void createEdge()
{
	while (1)
	{
		clearMouseClick();
		drawTutorial();
		outtextxy(370, 520, "Click vao dinh bat dau");
		int x, y;
		int posStart, posEnd;
		delay(1);
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			while (isVertex(x, y) == -1 && x != -1 && y != -1)
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
			posStart = isVertex(x, y);
			changeColorVertex(isVertex(x, y), 12);

			clearMouseClick();
			drawTutorial();
			x = 0;
			y = 0;
			outtextxy(370, 520, "Click vao dinh ket thuc");

			while (isVertex(x, y) == -1 || isStartVertex(x, y, graph[posStart]) == 1)
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
			posEnd = isVertex(x, y);
			changeColorVertex(isVertex(x, y), 12);

			if (MatrixWeight[posEnd][posStart] != 0)
			{
				//do nothing.
			}

			MatrixWeight[posStart][posEnd] = 0;

			Vertex dinhtrongso = drawEdge(posStart, posEnd, 4);

			int trongso = createTrongSo();
			if (trongso == 0)
			{
				MatrixWeight[posStart][posEnd] = 0;
				drawEdge(posStart, posEnd, BG_COLOR_GRAPH);
			}
			else
			{
				MatrixWeight[posStart][posEnd] = trongso;
				drawEdge(posStart, posEnd, 15);
			}
			drawTrongSo(dinhtrongso, trongso);
			changeColorVertex(posStart, 2);
			changeColorVertex(posEnd, 2);
			drawMatrixTT();
		}
		else if (ismouseclick(WM_RBUTTONDOWN))
		{
			break;
		}
	}
}
string processFileName()
{
	drawTutorial();
	char c;
	string fileName;
	char *result = new char[20];
	string s;
	outtextxy(370, 520, "Nhap toi da 15 chu va so. Nhan ENTER de ket thuc");
	outtextxy(370, 540, "Ten file: ");
	outtextxy(485, 540, &s[0]);
	int i = 0;
	do
	{
		fflush(stdin);
		while (!kbhit())
			;
		c = getch();
		if (c != 13 && c != 8 && i < 15 && ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)))
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
		outtextxy(370, 520, "Nhap toi da 15 chu va so. Nhan ENTER de ket thuc");
		outtextxy(370, 540, "Ten file: ");
		outtextxy(485, 540, &s[0]);
	} while (c != 13 || i == 0);
	return s;
}
void saveFile()
{
	string fileName = processFileName();
	ofstream f;
	fileName += ".txt";
	f.open(&fileName[0]);

	f << nVertex << endl;
	for (int i = 0; i < nVertex; i++)
	{
		for (int j = 0; j < nVertex; j++)
		{
			f << MatrixWeight[i][j] << " ";
		}
		f << endl;
	}
	for (int i = 0; i < nVertex; i++)
	{
		f << graph[i].x << " " << graph[i].y << " " << graph[i].name << endl;
	}
	outtextxy(370, 560, "LUU FILE HOAN TAT !!!");
	f.close();
	outtextxy(370, 580, "Nhap 1 phim bat ki de tiep tuc ...");
	getch();
	drawTutorial();
}
void openFile()
{
	string fileNames = processFileName();
	ifstream f;
	fileNames += ".txt";
	f.open(&fileNames[0]);
	if (f.fail())
	{
		drawTutorial();
		outtextxy(370, 520, "File khong ton tai");
		return;
	}
	else
	{
		fileName = strupr(&fileNames[0]);
	}
	f >> nVertex;
	for (int i = 0; i < nVertex; i++)
	{
		for (int j = 0; j < nVertex; j++)
		{
			f >> MatrixWeight[i][j];
		}
	}
	for (int i = 0; i < nVertex; i++)
	{
		graph[i].name = new char[3];
		f >> graph[i].x;
		f >> graph[i].y;
		f >> graph[i].name;
	}
	outtextxy(370, 560, "DOC FILE HOAN TAT !!!");
	f.close();
	renewGraph();
}
void clearGraph()
{
	for (int i = 0; i < nVertex; i++)
	{
		graph[i].x = NULL;
		graph[i].y = NULL;
		graph[i].name = NULL;
		for (int j = 0; j < nVertex; j++)
		{
			MatrixWeight[i][j] = NULL;
		}
	}
	nVertex = 0;
	fileName = "";
	renewGraph();
}
void changeNameDinh()
{
	int x, y, position;
	outtextxy(370, 520, "Nhap vao dinh can doi ten, khong duoc trung voi dinh da ton tai");
	while (isVertex(x, y) == -1 && x != -1 && y != -1)
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
	position = isVertex(x, y);
back:
	char *result = new char[3];
	result = createVertex();

	if (nVertex > 0)
	{
		for (int i = 0; i < nVertex; i++)
		{
			if (strcmp(result, graph[i].name) == 0)
			{
				goto back;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		graph[position].name[i] = result[i];
	}
	changeColorVertex(position, 2);
	drawTutorial();
	drawMatrixTT();
}
void deleteVertex(Vertex &one, Vertex &two)
{
	one.x = two.x;
	one.y = two.y;
	strcpy(one.name, two.name);
}
void deleteLastVertex()
{
	graph[nVertex - 1].x = NULL;
	graph[nVertex - 1].y = NULL;
	graph[nVertex - 1].name = NULL;
}
void coutMt()
{
	for (int i = 0; i < nVertex; i++)
	{
		for (int j = 0; j < nVertex; j++)
		{
			cout << MatrixWeight[i][j];
		}
	}
}
void removeVertex()
{
	int x, y, position;
	outtextxy(370, 520, "Nhap vao dinh can xoa");

	while (isVertex(x, y) == -1 && x != -1 && y != -1)
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

	position = isVertex(x, y);

	// X?a dinh cuoi c?ng
	if (position == nVertex - 1)
	{
		deleteLastVertex();
	}
	// X?a dinh bat ky
	else
	{
		for (int i = position; i < nVertex - 1; i++)
		{
			deleteVertex(graph[i], graph[i + 1]);
		}
	}
	deleteLastVertex();

	// X?a canh cuoi c?ng
	if (position == nVertex - 1)
	{
		for (int i = 0; i < nVertex; i++)
		{
			MatrixWeight[i][nVertex - 1] = 0;
			MatrixWeight[nVertex - 1][i] = 0;
		}
	}
	// X?a canh bat ki
	else
	{
		for (int i = position; i < nVertex - 1; ++i)
		{
			for (int j = 0; j < nVertex; ++j)
			{
				MatrixWeight[i][j] = MatrixWeight[i + 1][j];
			}
		}

		for (int i = 0; i < nVertex; ++i)
		{
			for (int j = position; j < nVertex - 1; ++j)
			{
				MatrixWeight[i][j] = MatrixWeight[i][j + 1];
			}
		}
	}
	nVertex--;
	renewGraph();
}
bool isWorkingZone(int x, int y)
{
	if (x >= (470 + BK) && x <= (1255 - BK) && y >= (30 + BK) && y <= (480 - BK) && x != -1 && y != -1)
	{
		return true;
	}
	return false;
}
void moveVertex()
{
	int x, y, position;

	outtextxy(370, 520, "Chon dinh va keo toi vi tri can toi !");
	while (true)
	{
		drawTutorial();
		outtextxy(370, 520, "Chon dinh va keo toi vi tri can toi !");
		x = 0;
		y = 0;
		delay(1);
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			while (isVertex(x, y) == -1 && x != -1 && y != -1)
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
			position = isVertex(x, y);
			clearMouseClick();
			while (true)
			{
				delay(.001);
				if (ismouseclick(WM_LBUTTONUP))
				{
					getmouseclick(WM_LBUTTONUP, x, y);
				}
				if (isWorkingZone(x, y) && isVertex(x, y) == -1)
				{
					graph[position].x = x;
					graph[position].y = y;
					break;
				}
			}
			clearMouseClick();
			renewGraph();
		}
		else if (ismouseclick(WM_RBUTTONDOWN))
		{
			clearMouseClick();
			renewGraph();
			break;
		}
	}

	//		position=isVertex(x,y);
	//		drawTutorial();
	//		outtextxy(370, 520, "Chon vao noi di chuyen toi!")
	//		while(true)
	//		{
	//			delay(.001);
	//			if(ismouseclick(WM_LBUTTONDOWN))
	//			{
	//				getmouseclick(WM_LBUTTONDOWN,x,y);
	//			}
	//			if (x >= (470 + BK) && x <= (1255 - BK) && y >= (30 + BK) && y <= (480 - BK) && x != -1 && y != -1 && isVertex(x, y) == -1){
	//				graph[position].x=x;
	//				graph[position].y=y;
	//				break;
	//			}
	//		}
	//		renewGraph();
}
void initTrace()
{
	for (int i = 0; i < nVertex; i++)
	{
		trace[i] = 0;
	}
}
void setTextPrintStyle()
{
	settextstyle(8, 0, 1);
	setcolor(0);
	setbkcolor(BG_COLOR_MENU);
}
void processDFS(int position)
{
	initTrace();
	int stack[MAX];
	int sp = 1;
	stack[sp] = position;
	trace[position] = 1;
	int temp = position;
	int result[MAX];
	int x = 420;
	int j = 0;
	while (sp > 0)
	{
		position = stack[sp];
		result[j] = position;
		j++;
		sp--;
		changeColorVertex(position, 12);
		setTextPrintStyle();
		outtextxy(370, 550, "DFS:");
		outtextxy(x, 550, graph[position].name);
		x += 35;
		outtextxy(x, 550, "->");
		x += 30;
		delay(500);
		for (int i = 0; i < nVertex; i++)
		{
			if ((MatrixWeight[position][i] != 0) && (trace[i] == 0))
			{
				stack[++sp] = i;
				trace[i] = 1;
				drawEdge(position, i, 4);
				changeColorVertex(position, 12);
				delay(500);
			}
		}
		changeColorVertex(position, 6);
	}
	drawTutorial();
	outtextxy(370, 520, "Chon dinh bat dau: ");
	outtextxy(575, 520, graph[temp].name);
	x = 420;
	for (int k = 0; k < j; k++)
	{
		setTextPrintStyle();
		outtextxy(370, 550, "DFS:");
		outtextxy(x, 550, graph[result[k]].name);
		x += 35;
		if (k != j - 1)
		{
			outtextxy(x, 550, "->");
			x += 30;
		};
	}
}
void DFS()
{
	// Chon dinh
	drawTutorial();
	outtextxy(370, 520, "Chon dinh bat dau: ");
	int x, y, position;

	while (isVertex(x, y) == -1 && x != -1 && y != -1)
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
	position = isVertex(x, y);
	outtextxy(575, 520, graph[position].name);
	//DFS
	processDFS(position);
	outtextxy(370, 580, "Nhap 1 phim bat ki de tiep tuc ...");
	getch();
	renewGraph();
}
void processBFS (int position)
{
	initTrace();
	int x= 420;
	int queue[MAX*MAX];
	int tail =1;
	int head =1;
	queue[head]=position;
	trace[position]=1;
	int j =0;
	int result[MAX];
	int temp = position;
	while (head<=tail)
	{
		position=queue[head];
		result[j]=position;
		j++;
		head ++;
		changeColorVertex(position, 12);
		setTextPrintStyle();
		outtextxy(370, 550, "BFS:");
		outtextxy(x, 550, graph[position].name);
		x += 35;
		outtextxy(x, 550, "->");
		x += 30;
		delay(500);
		for (int i=0;i<nVertex;i++)
		{
			if (MatrixWeight[position][i]!=0 && trace[i]==0)
			{	
				tail++;
				queue[tail]=i;
				drawEdge(position, i, 4);
				trace[i]=1;
				delay(500);
			}
		}
		changeColorVertex(position, 6);
	}
	drawTutorial();
	outtextxy(370, 520, "Chon dinh bat dau: ");
	outtextxy(575, 520, graph[temp].name);
	x = 420;
	for (int k = 0; k < j; k++)
	{
		setTextPrintStyle();
		outtextxy(370, 550, "BFS:");
		outtextxy(x, 550, graph[result[k]].name);
		x += 35;
		if (k != j - 1)
		{
			outtextxy(x, 550, "->");
			x += 30;
		};
	}
}
void BFS()
{
	// Chon dinh
	drawTutorial();
	outtextxy(370, 520, "Chon dinh bat dau: ");
	int x, y, position;

	while (isVertex(x, y) == -1 && x != -1 && y != -1)
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
	position = isVertex(x, y);
	outtextxy(575, 520, graph[position].name);
	//BFS
	processBFS(position);
	outtextxy(370, 580, "Nhap 1 phim bat ki de tiep tuc ...");
	getch();
	renewGraph();
}
void initDijkstra(int start, bool isVisited[], int dist[])
{
	for (int i = 0; i < nVertex; i++)
	{
		trace[i] = start;
		isVisited[i] = 1;
		dist[i] = MAX_VALUE;
	}
}
void drawXtoY(int dist[],int trace[],int posStart,int posEnd){
	if(dist[posEnd]==MAX_VALUE){
		drawTutorial();
		outtextxy(370,520, "Chon dinh bat dau: ");
		outtextxy(575,520, graph[posStart].name);
		outtextxy(370, 540, "Chon dinh ket thuc: ");
		outtextxy(575,540, graph[posEnd].name);
		outtextxy(370,560,"KHONG CO DUONG DI");
	}else{
		int result[nVertex];
		int n = 0;
		result[n]=posEnd;
		n++;
		int temp = trace[posEnd];
		while(posStart!=temp){
			result[n]=temp;
			n++;
			temp=trace[temp];
		}
		result[n]=posStart;
	
		drawTutorial();
		outtextxy(370,520, "Chon dinh bat dau: ");
		outtextxy(575,520, graph[posStart].name);
		outtextxy(370, 540, "Chon dinh ket thuc: ");
		outtextxy(590,540, graph[posEnd].name);
		outtextxy(370, 560, "Tong trong so: ");
		outtextxy(530,560, &coverIntToString(dist[posEnd])[0]);
		outtextxy(370, 580, "Duong di ngan nhat: ");
		int x = 600;

		int first = result[n];
		int next ;
		
		changeColorVertex(first, 12);
		setTextPrintStyle();
		outtextxy(x, 580,graph[first].name);
		while(n>0){
			setTextPrintStyle();
			n--;
			next = result[n];
			x += 35;
			outtextxy(x,580,"=>");
			x += 30;
			outtextxy(x, 580,graph[next].name);
			changeColorVertex(next, 12);
			drawEdge(first, next, 14);
			first=next;
			delay(500);
		}
	}

}
void processXtoY(int posStart, int posEnd)
{
	bool isVisited[nVertex];
	int dist[nVertex];
	int truoc,sau;
	initDijkstra(posStart, isVisited, dist);
	dist[posStart] = 0;
	while (1)
	{
		truoc = MAX_VALUE;
		sau = -1;
		for (int i = 0; i < nVertex; ++i){
			if (isVisited[i] && dist[i] < truoc)
			{
				truoc = dist[i]; // Find Min(truoc,sau)
				sau = i;
			}
		}
		
		if (sau == -1 || sau == posEnd)	break;
		isVisited[sau] = 0;
		for (int i = 0; i < nVertex; ++i)
		{
			int weight = MatrixWeight[sau][i];
			if (isVisited[i] && weight != 0 && dist[i] > truoc + weight)
			{
				dist[i] = truoc + weight; // (truoc,sau) ->(1,a)
				trace[i] = sau;
			}
		}
	}
	drawXtoY(dist,trace,posStart,posEnd);
}
void XtoY()
{
	clearMouseClick();
	drawTutorial();
	outtextxy(370, 520, "Chon dinh bat dau");
	int x, y;
	int posStart, posEnd;
	while(1){
	delay(1);
	if (ismouseclick(WM_LBUTTONDOWN))
	{
	getmouseclick(WM_LBUTTONDOWN, x, y);
	while (isVertex(x, y) == -1 && x != -1 && y != -1)
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
	posStart = isVertex(x, y);
	changeColorVertex(isVertex(x, y), 12);
	
	clearMouseClick();
	drawTutorial();
	x = 0;
	y = 0;
	outtextxy(370, 540, "Chon dinh ket thuc");
	
	while (isVertex(x, y) == -1 || isStartVertex(x, y, graph[posStart]) == 1)
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
	posEnd = isVertex(x, y);
	changeColorVertex(isVertex(x, y), 12);
	processXtoY(posStart, posEnd);
	setTextPrintStyle();
	outtextxy(370, 600, "Nhap 1 phim bat ki de tiep tuc ...");
	getch();
	renewGraph();
	break;
	}
	else if(ismouseclick(WM_RBUTTONDOWN))
	{
		renewGraph();
		break;	
	}	
	}
}
void processFunction(int type)
{
	switch (type)
	{
	case 1:
		//DFS
		drawTutorial();
		if (nVertex != 0)
		{
			DFS();
		}
		else
		{
			outtextxy(370, 520, "Khong du dinh!");
		}
		break;
	case 2:
		//BFS
		drawTutorial();
		if (nVertex != 0)
		{
			BFS();
		}
		else
		{
			outtextxy(370, 520, "Khong du dinh!");
		}
		break;
	case 3:
		//X->Y
			drawTutorial();
			if (nVertex != 0)
			{
				XtoY();
			}
			else
			{
				outtextxy(370, 520, "Khong du dinh!");
			}
			break;
	case 4:
		//Vertex TRU
			drawTutorial();
			if (nVertex != 0)
			{
				XtoY();
			}
			else
			{
				outtextxy(370, 520, "Khong du dinh!");
			}
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
		if (nVertex != 0)
		{
			char a;
			drawTutorial();
			outtextxy(370, 520, "Ban co muon xoa do thi hien tai? (Y/N)");
			a = getch();
			if (a == 89 || a == 121)
			{
				clearGraph();
				openFile();
			}
			else
			{
				drawTutorial();
				break;
			}
		}
		else
		{
			openFile();
		}
		break;
	case 12:
		drawTutorial();
		if (nVertex != 0)
		{
			saveFile();
		}
		else
		{
			outtextxy(370, 520, "Khong co gi de luu !");
		}
		break;
	case 13:
		drawTutorial();
		if (nVertex != 0)
		{
			char a;
			outtextxy(370, 520, "Ban co muon xoa do thi hien tai? (Y/N)");
			a = getch();
			if (a == 89 || a == 121)
			{
				clearGraph();
			}
			else
			{
				drawTutorial();
				break;
			}
		}
		else
		{
			outtextxy(370, 520, "Khong co gi de xoa !");
		}
		break;
	case 14:
		if (nVertex < MAX)
		{
			drawTutorial();
			drawVertex();
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
		drawTutorial();
		if (nVertex > 0)
		{
			removeVertex();
		}
		else
		{
			drawTutorial();
			outtextxy(370, 520, "KHONG DU DINH ");
			break;
		}
		break;
	case 16:
		//TAO CUNG
		if (nVertex >= 2)
		{
			drawTutorial();
			createEdge();
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

		if (nVertex > 0)
		{
			drawTutorial();
			clearMouseClick();
			moveVertex();
		}
		else
		{
			drawTutorial();
			outtextxy(370, 520, "Khong du dinh");
			break;
		}
		break;
	case 18:
		drawTutorial();
		if (nVertex > 0)
		{
			changeNameDinh();
		}
		else
		{
			outtextxy(370, 520, "Khong du dinh");
			break;
		}
		break;
	}
}
bool chooseFunction(Vertex s)
{
	int x, y;

	getmouseclick(WM_RBUTTONDOWN, x, y);

	if ((x != -1 && y != -1) && (x >= s.x && x <= s.x + 101) && (y >= s.y && y <= s.y + 41))
	{
		return true;
	}
	return false;
}
void addMouse(Vertex s, int &x, int &y, bool &isSelected, int type)
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
void processMouse(Vertex s[][10])
{
	int x, y = 0;
	bool isSelected = false;
	while (1)
	{
		delay(1);
		getmouseclick(WM_MOUSEMOVE, x, y);
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			cout << x << y << endl;
			clearmouseclick(WM_LBUTTONDOWN);
		}

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
	clearMouseClick();
	drawWorkingZone();
	drawAllVertex();
	drawAllEdge();
}
int main(int argc, char *argv[])
{
	Vertex a[3][10];
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
