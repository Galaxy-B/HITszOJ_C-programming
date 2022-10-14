#include<stdio.h>

void ArrayIn(int Num[], int num);
int Judge(int Num1[], int Num2[], int Num3[]);

int i, j;
int Standard[9] = {0};

int main(void)
{
    int num1, num2, num3;
    int Num1[3], Num2[3], Num3[3];
    for (j = 123; j <= 329; j++)
    {
        num1 = j, num2 = j * 2; num3 = j * 3;
        ArrayIn(Num1, num1);
        ArrayIn(Num2, num2);
        ArrayIn(Num3, num3);
        if (Judge(Num1, Num2, Num3) == 1)
        printf("%d,%d,%d\n",num1, num2, num3);
    }
    return 0;
}

void ArrayIn(int Num[], int num)
{
    Num[0] = num / 100;
    Num[1] = (num - Num[0] * 100) / 10;
    Num[2] = num % 10;
}

int Judge(int Num1[], int Num2[], int Num3[])
{
    for(i = 0; i < 9; i++)
    {
        Standard[i] = 0;
    }
    
    for (i = 0; i < 3; i++)
    {
        Standard[Num1[i] - 1]++;
    }
    for (i = 0; i < 3; i++)
    {
        Standard[Num2[i] - 1]++;
    }
    for (i = 0; i < 3; i++)
    {
        Standard[Num3[i] - 1]++;
    }

    if (Standard[0] == 1 && Standard[1] == 1 && Standard[2] == 1  && Standard[3] == 1 && Standard[4] == 1 && Standard[5] == 1 && Standard[6] == 1  && Standard[7] == 1 && Standard[8] == 1) return 1;
    else    return 0;
}