#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
    int num = 0;
    int count = 0;
    scanf("%d", &num);
    for (int i = 0; i < 32; i++)
    {
        if (1 == ((num >> i) & 1))
            count++;
    }
    printf("%d\n", count);
    return 0;
}