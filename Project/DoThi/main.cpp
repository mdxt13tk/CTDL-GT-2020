/*	Test thu vien winbgim.h	*/

#include <graphics.h> 
#include <iostream> 
using namespace std;


struct dinh
{
	int x;
	int y;
	char* name;
};

void defaultButton(dinh a)
{
	int c = getcolor();
	setcolor(3);
	setfillstyle(1, 4);
	bar(a.x, a.y, a.x + 100, a.y + 40);
	rectangle(a.x, a.y, a.x + 100, a.y + 40);
	setcolor(15);
	setbkcolor(4);
	settextstyle(2,0,5);
	outtextxy(a.x + 17, a.y + 13, a.name);
	setcolor(c);
	setfillstyle(1, c);
}
void systemMenu(dinh systemMenu[3])
{
	const int weight = 110;
	const int height = 50;
	setfillstyle(1, 3);
	bar(20, 245, 350, 295);
	for (int i = 0; i < 3; i++)
	{
		systemMenu[i].x = weight*i + 25;
		systemMenu[i].y = height + 200;
		systemMenu[i].name = new char[10];
	}
	systemMenu[0].name = "MO";
	systemMenu[1].name = "LUU";
	systemMenu[2].name = "XOA";

	for (int i = 0; i < 3; i++)
	{
		defaultButton(systemMenu[i]);
	}
	setcolor(0);
	rectangle(20, 245, 350, 295);

}
void funcMenu(dinh menu[10])
{	
	const int weight = 110;
	const int height = 50;
	int count = 0;
	setfillstyle(1, 3);
	bar(20, 30, 350, 235);
	for (int i = 0; i < 10;)
	{
		for (int j = 0; j < 3 && i<10; j++)
		{
			menu[i].x = weight*j + 25;
			menu[i].y = height*count + 40;
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
	setcolor(0);
	rectangle(20, 30, 350, 235);
}
void controlMenu(dinh file[5])
{
	const int weight = 110;
	const int height = 80;
	setfillstyle(1, 3);
	bar(355, 30, 355 + weight, 00 + height * 6);
	for (int i = 0; i < 5; i++)
	{
		file[i].x = 360;
		file[i].y = height*i + 60;
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
	rectangle(355, 30, 355 + weight, 00 + height * 6);

}
void matrixTTTitle()
{
	const int dai = 330;
	setfillstyle(1, 3);
	bar(20, 300, 350, 350);
	setcolor(0);
	rectangle(20, 300, 350, 350);
	setbkcolor(3);
	settextstyle(2,0,5);
	setcolor(0);
	outtextxy(130, 310, "WEIGHING MATRIX");
}	
void drawMatrixTT(){
	int D=30;
	const int dai = 330;
	setfillstyle(1, 3);
	bar(20, 355, 20 + dai, 355 + dai);
	setcolor(0);
	rectangle(20, 355, 20 + dai, 355 + dai);
}
void tutorial()
{
	setcolor(0);
	line(355,500,370,500);
	line(430,500,1250,500);
	line(355,500,355,685);
	line(355,685,1250,685);
	line(1250,685,1250,500);
	setbkcolor(7);
	outtextxy(370, 493, "TUTORIAL");
}
void drawGraphic()
{
	setfillstyle(1, 8);
	bar(465, 30, 1250, 480);
	setcolor(0);
	rectangle(465, 30, 1250, 480);
	tutorial();
}

void clearMouseClick(){
	clearmouseclick(WM_RBUTTONUP);
	clearmouseclick(WM_RBUTTONDOWN);
	clearmouseclick(WM_LBUTTONUP);
	clearmouseclick(WM_LBUTTONDOWN);	
}
void drawUI(dinh a[][10]){
	setfillstyle(1, 7);
	bar(1, 1, 1279, 719);
	funcMenu(a[0]);
	systemMenu(a[1]);
	controlMenu(a[2]);
	matrixTTTitle();
	drawMatrixTT();
	drawGraphic();
}
void processMouse(dinh a[][10]){
	int x,y=0;
	dinh s = a[0][0];
	while (1)
		{
			delay(1);
			if (ismouseclick((WM_LBUTTONDOWN))){
					getmouseclick(WM_MOUSEMOVE, x, y);
					
			if ((x != -1 && y != -1) && (x >= s.x && x <= s.x + 100) && (y >= s.y && y <= s.y + 40))
				{
					cout<<s.name;
				}
					
					clearMouseClick();
			}
		
		}
}
int main(int argc, char *argv[])
{
	dinh a[3][10];
	initwindow(1280,720);		// init window graphics						// set background
   	cleardevice();
   	drawUI(a);
   	processMouse(a);

	while(!kbhit()) delay(1);				// pause screen	
	return 0;
}

