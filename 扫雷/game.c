#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)//打印棋盘
{
	int i = 0;
	int j = 0;
	printf("-----扫雷游戏------\n");
	//打印列号
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)//布置雷
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;//1-9
		int y = rand() % col + 1;//1-9
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS], int x, int y)//周围雷的个数
{
	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}

void spread(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)//显示周围雷的个数
{
	int count = get_mine_count(mine, x, y);
	if (x >= 1 && x <= row && y >= 1 && y <= col)
	{
		if (count)
		{
			show[x][y] = count + '0';
		}
		else if (show[x][y] == '*')
		{
			show[x][y] = ' ';
			int i = 0, j = 0;
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					spread(mine, show, row, col, i, j);
				}
			}
		}
	}
}
int  win(char show[ROWS][COLS], int row, int col)//胜利条件
{
	int number = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
			{
				number++;
			}
		}
	}
	if (number == EASY_COUNT)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//排查雷
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("请输入排查雷的坐标:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("该坐标被排查过了，不能重复排查\n");
			}
			else
			{
				//踩雷
				if (mine[x][y] == '1')
				{
					printf("很遗憾，你被炸死了\n");
					DisplayBoard(mine, row, col);
					break;
				}
				else//不是雷
				{
					//计算x，y坐标周围有几个雷
					spread(mine, show, row, col, x, y);
					DisplayBoard(show, row, col);
					if (win(show, row, col))//胜利条件
					{
						printf("恭喜你，排雷成功\n");
						DisplayBoard(mine, row, col);
						break;
					}
				}
			}
		}
		else
		{
			printf("输入坐标非法，请重新输入！\n");
		}
	}
}
