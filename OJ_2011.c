#include<stdio.h>

void ReadNum(int Advise[], int n);
int Mean(int Advise[], int n);
int Median(int Advise[], int n);
int Mode(int Advise[], int n);

int i, j;
int main(void)
{
    int Advise[40] = {-1};
    int n;
    scanf("%d%*c",&n);
    ReadNum(Advise, n);
    printf("Mean=%d\n",Mean(Advise, n));
    printf("Median=%d\n",Median(Advise, n));
    printf("Mode=%d\n",Mode(Advise, n));
}

void ReadNum(int Advise[], int n)
{
    for (i = 0; i < n; i++)
    {
        scanf("%d%*c",&Advise[i]);
    }
}

Mean(int Advise[], int n)
{
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += Advise[i];
    }
    return sum / n;
}

int Median(int Advise[], int n)
{
    int temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (Advise[j] > Advise[i])
            {
                temp = Advise[i];
                Advise[i] = Advise[j];
                Advise[j] = temp;
            }
        }
    }
    if (n % 2 == 1) return Advise[n / 2];
    else            return (Advise[n / 2] + Advise[(n / 2) - 1]) / 2;
}

int Mode(int Advise[], int n)
{
    int Judge[11] = {0};
    for (i = 0; i < n; i++)
    {
        Judge[Advise[i]]++;
    }
    int flag = 0;
    for (i = 1; i < 11; i++)
    {
        if (Judge[i] > Judge[flag]) flag = i;
    }
    return flag;
}