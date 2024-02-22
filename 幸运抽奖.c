#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void Start_menu()
{
	printf("\033[36m欢迎来到幸运抽奖\033[0m\n");
	printf("***********************************\n");
	printf("****     1.play     0.exit     ****\n");
	printf("***********************************\n");
}

void Game_menu(int Special, int First, int  Second, int Third, int Count)
{
	printf("**********************************\n");
	printf("*     奖项     奖品     剩余     *\n");
	printf("**********************************\n");
	printf("*    特等奖    1298元   %d份	 *\n", Special);
	printf("*    一等奖    648元    %d份	 *\n", First);
	printf("*    二等奖    168元    %d份	 *\n", Second);
	printf("*    三等奖    88元     %d份     *\n", Third);
	printf("**********************************\n");
	printf("* 当前抽奖次数:%d  按回车键抽奖	 *\n", Count);
	printf("**********************************\n");
}

void game()
{
	int number;
	int ch;
	int Special = 1;//特等奖
	int First = 3;//一等奖
	int Second = 5;//二等奖
	int Third = 10;//三等奖
	int Count = 0;//抽奖次数
	Game_menu(Special, First, Second, Third, Count);
	ch=getchar();//缓冲区
	while (Special + First + Second + Third > 0)
	{
		if ((ch = getchar()) == '\n')
		{
			srand((unsigned int)time(NULL));
			Random:
			number = rand() % 100 + 1;
			switch (number)
			{
			case 1:
				if (Special > 0)
				{
					system("cls");
					Special--;
					Count++;
					Game_menu(Special, First, Second, Third, Count);
					printf("抽奖结果:\033[31m特等奖\033[0m\n");
					break;
				}
				else
					goto Random;
			case 2:
			case 3:
			case 4:
				if (First > 0)
				{
					system("cls");
					First--;
					Count++;
					Game_menu(Special, First, Second, Third, Count);
					printf("抽奖结果:\033[33m一等奖\033[0m\n");
					break;
				}
				else
					goto Random;
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				if (Second > 0)
				{
					system("cls");
					Second--;
					Count++;
					Game_menu(Special, First, Second, Third, Count);
					printf("抽奖结果:\033[35m二等奖\033[0m\n");
					break;
				}
				else
					goto Random;
			case 10:
			case 11:
			case 12:
			case 13:
			case 14:
			case 15:
			case 16:
			case 17:
			case 18:
			case 19:
				if (Third > 0)
				{
					system("cls");
					Third--;
					Count++;
					Game_menu(Special, First, Second, Third, Count);
					printf("抽奖结果:\033[34m三等奖\033[0m\n");
					break;
				}
				else
					goto Random;
			default:
				system("cls");
				Count++;
				Game_menu(Special, First, Second, Third, Count);
				printf("抽奖结果:谢谢参与\n");
				break;
			}
		}
	} 
	Sleep(1000);
	for (int i = 5; i > 0; i--)
	{
		system("cls");
		Game_menu(Special, First, Second, Third, Count);
		printf("本次奖池已无奖品，%d秒后将自动回到主菜单\n",i);
		Sleep(1000);
	}
}

int main()
{
	int input;
	Start_menu();
	do
	{
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			game();
			system("cls");
			Start_menu();
			break;
		case 0:
			system("cls");
			printf("退出游戏\n");
			break;
		default:
			system("cls");
			Start_menu();
			printf("输入错误,请重新输入\n");
			printf("\a");
			Sleep(1000);
			system("cls");
			Start_menu();
			break;
		}
	} while (input);
	return 0;
}
