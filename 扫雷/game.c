#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)//��ʼ������
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

void DisplayBoard(char board[ROWS][COLS], int row, int col)//��ӡ����
{
	int i = 0;
	int j = 0;
	printf("-----ɨ����Ϸ------\n");
	//��ӡ�к�
	printf("");
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-------------------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)//������
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

int get_mine_count(char mine[ROWS][COLS], int x, int y)//��Χ�׵ĸ���
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

void spread(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)//��ʾ��Χ�׵ĸ���
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
int  win(char show[ROWS][COLS], int row, int col)//ʤ������
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

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//�Ų���
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("�������Ų��׵�����:>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("�����걻�Ų���ˣ������ظ��Ų�\n");
			}
			else
			{
				//����
				if (mine[x][y] == '1')
				{
					printf("���ź����㱻ը����\n");
					DisplayBoard(mine, row, col);
					break;
				}
				else//������
				{
					//����x��y������Χ�м�����
					spread(mine, show, row, col, x, y);
					DisplayBoard(show, row, col);
					if (win(show, row, col))//ʤ������
					{
						printf("��ϲ�㣬���׳ɹ�\n");
						DisplayBoard(mine, row, col);
						break;
					}
				}
			}
		}
		else
		{
			printf("��������Ƿ������������룡\n");
		}
	}
}