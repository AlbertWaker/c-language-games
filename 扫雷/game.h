#define ROW 9//列9
#define COL 9//行9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 10//雷的数量

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROWS][COLS], int rows, int cols);//初始化棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);//打印棋盘
void SetMine(char board[ROWS][COLS], int row, int col);//布置雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//排查雷
