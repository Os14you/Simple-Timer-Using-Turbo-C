#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <stdio.h>
#include <mouse_c.h>
int clrths(int x1, int y1);
void design();
void main()
{
	initmouse();
	int pxx = 70, pyx = 210, pzx = 350, pax = 490, py = 200;
	char msg1[1], msg2[1], msg3[1], msg4[1];
	int gd = 0, gm, errorcode;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	design();
	for (;;)
	{
		int b, xx, yy;
		showmouse();
		getmouse(&b, &xx, &yy);
		if (b == 1 && 133 <= xx && xx <= 233 && 300 <= yy && yy <= 350)
		{
			for (int x = 0; x <= 24; x++)
			{
				setcolor(14);
				settextstyle(1, 0, 1);
				clrths(pxx, py);
				sprintf(msg1, "%d", x);
				outtextxy(pxx, py, msg1);
				for (int y = 0; y <= 59; y++)
				{
					clrths(pyx, py);
					sprintf(msg2, "%d", y);
					outtextxy(pyx, py, msg2);
					for (int z = 0; z <= 59; z++)
					{
						clrths(pzx, py);
						sprintf(msg3, "%d", z);
						outtextxy(pzx, py, msg3);
						for (int a = 0; a <= 99; a++)
						{
							clrths(pax, py);
							sprintf(msg4, "%d", a);
							outtextxy(pax, py, msg4);
							showmouse();
							getmouse(&b, &xx, &yy);
							delay(9);
						      /*	if (a == 100)
								a = 0; */
							if (b == 1 && 346 <= xx && xx <= 446 && 300 <= yy && yy <= 350)
								break;
						}
						if (z == 60)
							z = 0;
						if (b == 1 && 346 <= xx && xx <= 446 && 300 <= yy && yy <= 350)
							break;
					}
					if (y == 60)
						y = 0;
					if (b == 1 && 346 <= xx && xx <= 446 && 300 <= yy && yy <= 350)
						break;
				}
				if (x == 24)
					x = 0;
				if (b == 1 && 346 <= xx && xx <= 446 && 300 <= yy && yy <= 350)
					break;
			}
			/*if (b == 1 && 233 <= xx && xx <= 364 && 380 <= yy && yy <= 430)
				break;    */
		}
		if (b == 1 && 233 <= xx && xx <= 364 && 380 <= yy && yy <= 430)
			break;
	}
	getch();
	closegraph();
}
int clrths(int x1, int y1)
{
	setfillstyle(0, 0);
	bar(x1, y1, x1 + 40, y1 + 25);
}
void design()
{
	setlinestyle(3, 5, 3);
	ellipse(80, 210, 0, 0, 60, 40); // hours
	ellipse(80, 210, 0, 0, 56, 36);
	ellipse(220, 210, 0, 0, 60, 40); // minutes
	ellipse(220, 210, 0, 0, 56, 36);
	ellipse(360, 210, 0, 0, 60, 40); // seconds
	ellipse(360, 210, 0, 0, 56, 36);
	ellipse(500, 210, 0, 0, 60, 40); // pseconds
	ellipse(500, 210, 0, 0, 56, 36);
	setfillstyle(5, 2);
	bar(133, 300, 233, 350); // start bottom
	rectangle(133, 300, 233, 350);
	setfillstyle(5, 4);
	bar(346, 300, 446, 350); // stop bottom
	rectangle(346, 300, 446, 350);
	setfillstyle(5, 6);
	bar(233, 380, 346, 430); // exit bottom
	rectangle(233, 380, 346, 430);
	settextstyle(1, 0, 1);
	outtextxy(159, 310, "START");
	outtextxy(373, 310, "STOP");
	outtextxy(269, 394, "EXIT");
	circle(150, 220, 4);
	circle(290, 220, 4);
	circle(430, 220, 4);
	circle(150, 200, 4);
	circle(290, 200, 4);
	circle(430, 200, 4);
	outtextxy(70, 200, "0");
	outtextxy(210, 200, "0");
	outtextxy(350, 200, "0");
	outtextxy(490, 200, "0");
	outtextxy(50, 135, "Hours");
	outtextxy(190, 135, "Minutes");
	outtextxy(330, 135, "Seconds");
	outtextxy(460, 135, "p_Seconds");
}