#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

void menu()//主菜单
{
    printf("********************************************\n");
    printf("* 腾讯QQ         *********                 *\n");
    printf("*              *************               *\n");
    printf("*             ****  ***  ****              *\n");
    printf("*             ***************              *\n");
    printf("*            ******************            *\n");
    printf("*           ********************           *\n");
    printf("*          *********************           *\n");
    printf("*          *  ***************  *           *\n");
    printf("*               ***********                *\n");
    printf("*    1.登录   ******* *******    2.注册    *\n");
    printf("********************************************\n");
}

void Register(int ch1, int ch2, int ch3, int ch4, char name[20], char password[16])//注册菜单
{
    printf("********************************************\n");
    printf("* 欢迎注册QQ                               *\n");
    printf("* 每一天，乐在沟通                         *\n");
    printf("*                                          *\n");
    printf("*  昵称：%-20s              *\n",name);
    printf("*  密码：%-16s                  *\n", password);
    printf("*  %3c不能包括空格                         *\n", ch1);
    printf("*  %3c长度为8-16个字符                     *\n", ch2);
    printf("*  %3c必须包含字母、数字、符号中至少两种   *\n", ch3);
    printf("*  %3c请勿输入连续、重复6位以上字母或数字，*\n", ch4);
    printf("*     如abcdefg、1111111、0123456          *\n");
    printf("********************************************\n");
}
void log_in(char name[20], int account[8], char verify[16], char loading[10])//登录菜单
{
    printf("********************************************\n");
    printf("* 腾讯QQ            * * *                  *\n");
    printf("*                 *  ***  *                *\n");
    printf("*                *  *****  *               *\n");
    printf("*                * * *** * *               *\n");
    printf("*                 * ** ** *                *\n");
    printf("*                   * * *                  *\n");
    printf("*      昵称：%-20s          *\n",name);
    printf("*      账号：%d%d%d%d%d%d%d%d                      *\n", account[0],account[1], account[2], account[3], account[4], account[5], account[6], account[7]);
    printf("*      密码：%-16s              *\n", verify);
    printf("*                  %-10s              *\n",loading);
    printf("********************************************\n");
}

int main()
{
    int input = 0;//用户选择
    int Account = 0;//判断有无账号
    int number = 0;//数字
    int letter = 0;//字母
    int symbol = 0;//符号
    int count = 1;//计数
    char ch1 = ' ';//判断条件1
    char ch2 = ' ';//判断条件2
    char ch3 = ' ';//判断条件3
    char ch4 = ' ';//判断条件4
    char name[20] = "";//昵称
    char password[16] = "";//密码
    char verify[16] = "";//密码验证
    char loading[10] = "";//登录中
    int account[8] = { 0 };//账号
    int i;//循环用
    int ch;//缓冲
    do
    {
        system("cls");//清屏
        menu();//主菜单
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1://登录
            if (Account == 0)//无账号
            {
                system("cls");
                menu();
                printf("当前暂无账号，请注册\n");
                printf("\a");
                Sleep(1000);
            }
            else if (Account == 1)//有账号
            {
                srand((unsigned int)time(NULL));
                account[0] = rand() % 9 + 1;//账号开头不能是0 生成1-9随机数
                for (i = 1; i < 8; i++)//生成剩下7位
                {
                    account[i] = rand() % 10;//生成0-9随机数
                }
            verify://验证密码
                system("cls");
                log_in(name, account, verify, loading);
                printf("请输入密码:");
                scanf("%s", verify);
                if (strcmp(verify, password) == 0)
                {
                    strcpy(loading, "登录中");
                    system("cls");
                    log_in(name, account, verify, loading);
                    Sleep(5000);
                    system("cls");
                    printf("登录成功\n");
                    return 0;
                }
                else
                {
                    strcpy(verify, "");
                    system("cls");
                    log_in(name, account, verify, loading);
                    printf("密码错误，请重新输入");
                    printf("\a");
                    Sleep(1000);
                    goto verify;//密码不正确，重新验证密码
                }
            }
            break;
        case 2://注册
            if (Account == 0)//无账号
            {
                ch = getchar();//缓冲区
            name://设置昵称
                system("cls");
                Register(ch1, ch2, ch3, ch4, name, password);
                printf("请输入昵称:");
                gets(name);
                //判断昵称长度是否符合标准
                if (strlen(name) > 20)
                {
                    strcpy(name, "");
                    system("cls");
                    Register(ch1, ch2, ch3, ch4, name, password);
                    printf("昵称过长，请重新输入");
                    printf("\a");
                    Sleep(1000);
                    goto name;//重新设置昵称
                }
                //判断昵称是否存在空格
                for (i = 0; i < strlen(name); i++)
                {
                    if (name[i] == ' ')
                    {
                        strcpy(name, "");
                        system("cls");
                        Register(ch1, ch2, ch3, ch4, name, password);
                        printf("昵称不能出现空格，请重新输入");
                        printf("\a");
                        Sleep(1000);
                        goto name;//重新设置昵称
                    }
                }
            password://设置密码
                system("cls");
                Register(ch1, ch2, ch3, ch4, name, password);
                printf("请输入密码:");
                gets(password);
                //判断密码长度是否符合标准
                if (strlen(password) > 16)//长度大于16
                {
                    ch2 = 'F';
                    strcpy(password, "");
                    system("cls");
                    Register(ch1, ch2, ch3, ch4, name, password);
                    printf("密码过长，请重新输入");
                    printf("\a");
                    Sleep(1000);
                    goto password;//重新设置密码
                }
                if (strlen(password) < 8)//长度小于8
                {
                    ch2 = 'F';
                    strcpy(password, "");
                    system("cls");
                    Register(ch1, ch2, ch3, ch4, name, password);
                    printf("密码过短，请重新输入");
                    printf("\a");
                    Sleep(1000);
                    goto password;//重新设置密码
                }
                else//长度8-16 符合标准
                {
                    ch2 = 'T';
                    system("cls");
                    Register(ch1, ch2, ch3, ch4, name, password);
                }
                //判断密码是否存在空格
                for (i = 0; i < strlen(password); i++)
                {
                    if (password[i] == ' ')
                    {
                        ch1 = 'F';
                        strcpy(password, "");
                        system("cls");
                        Register(ch1, ch2, ch3, ch4, name, password);
                        printf("密码不能出现空格，请重新输入");
                        printf("\a");
                        Sleep(1000);
                        goto password;//重新设置密码
                    }
                }
                if (i == strlen(password))//密码不存在空格
                {
                    ch1 = 'T';
                    system("cls");
                    Register(ch1, ch2, ch3, ch4, name, password);
                }
                //判断密码必须包含字母、数字、符号中至少两种
                number = 0;
                letter = 0;
                symbol = 0;
                for (i = 0; i < strlen(password); i++)
                {
                    if (password[i] >= '0' && password[i] <= '9')//数字
                    {
                        number = 1;
                    }
                    else if (((password[i] >= 'a') && (password[i] <= 'z')) || ((password[i] >= 'A') && (password[i] <= 'Z')))//字母
                    {
                        letter = 1;
                    }
                    else//符号
                    {
                        symbol = 1;
                    }
                }
                //密码包含两种几以上
                if (number + letter + symbol >= 2)
                {
                    ch3 = 'T';
                    system("cls");
                    Register(ch1, ch2, ch3, ch4, name, password);
                }
                else
                {
                    ch3 = 'F';
                    strcpy(password, "");
                    system("cls");
                    Register(ch1, ch2, ch3, ch4, name, password);
                    printf("密码必须包含字母、数字、符号中至少两种，请重新输入");
                    printf("\a");
                    Sleep(1000);
                    goto password;//重新设置密码
                }
                //判断密码是否为连续
                for (i = 0; i < strlen(password); i++)
                {
                    if (password[i + 1] - password[i] == 1)
                    {
                        count++;
                    }
                    else
                    {
                        count = 1;
                    }
                    if (count > 6)
                    {
                        ch4 = 'F';
                        strcpy(password, "");
                        system("cls");
                        Register(ch1, ch2, ch3, ch4, name, password);
                        printf("密码连续6位以上，请重新输入");
                        printf("\a");
                        Sleep(1000);
                        goto password;//重新设置密码
                    }
                }
                //密码不存在6位以上连续
                if (i == strlen(password))
                {
                    ch4 = 'T';
                    system("cls");
                    Register(ch1, ch2, ch3, ch4, name, password);
                }
                //判断密码是否重复6位以上
                for (i = 0; i < strlen(password); i++)
                {
                    if (password[i] == password[i + 1])
                    {
                        count++;
                    }
                    else
                    {
                        count = 1;
                    }
                    if (count > 6)
                    {
                        ch4 = 'F';
                        strcpy(password, "");
                        system("cls");
                        Register(ch1, ch2, ch3, ch4, name, password);
                        printf("密码重复6位以上，请重新输入");
                        printf("\a");
                        Sleep(1000);
                        goto password;//重新设置密码
                    }
                }
                //密码不存在6位以上连续
                if (i == strlen(password))
                {
                    ch4 = 'T';
                    system("cls");
                    Register(ch1, ch2, ch3, ch4, name, password);
                }
                if (ch1 == 'T' && ch2 == 'T' && ch3 == 'T' && ch4 == 'T')
                {
                    system("cls");
                    Register(ch1, ch2, ch3, ch4, name, password);
                    printf("注册成功\n");
                    Sleep(5000);
                    Account = 1;
                }
                break;
            }
            else if (Account == 1)//有账号
            {
                system("cls");
                menu();
                printf("已有账号，请登录\n");
                printf("\a");
                Sleep(1000);
                break;
            }
        default://非法输入
            system("cls");
            menu();
            printf("输入错误,请重新输入\n");
            printf("\a");
            Sleep(1000);
            break;
        }
    } while (1);
    return 0;
}