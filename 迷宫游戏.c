#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main()
{
	int i;
	char a[50][50] = { "##########",
					   "#@   #   #",
					   "### ## # #",
					   "# #    # #",
					   "#    # #  ",
					   "##########",};
	char ch;
	int x, y, startx, starty, endx, endy;
	startx = 1, starty = 1, endx = 10, endy = 4;
	x = startx;
	y = starty;
	while (1)
	{
		if (x == endx && y == endy)
			break;
		for (i = 0; i <= 5; i++)
			puts(a[i]);
		ch = _getch();
		if (ch == 'w')
		{
			if (a[y - 1][x] != '#')
			{
				a[y][x] = ' ';
				y--;
				a[y][x] = '@';
			}
		}
		if (ch == 's')
		{
			if (a[y + 1][x] != '#')
			{
				a[y][x] = ' ';
				y++;
				a[y][x] = '@';
			}
		}
		if (ch == 'a')
		{
			if (a[y][x - 1] != '#')
			{
				a[y][x] = ' ';
				x--;
				a[y][x] = '@';
			}
		}
		if (ch == 'd')
		{
			if (a[y][x + 1] != '#')
			{
				a[y][x] = ' ';
				x++;
				a[y][x] = '@';
			}
		}
		system("cls");
	}
	system("cls");
	printf("完成！\n");
	return 0;
}