#include<stdio.h>
void DataRank(int Number[], int n);
void ReadNum(int Number[], int num, int i);
void PrintData(int Number[], int n);
int main(void)
{
    int n, i, num, Number[100] = {0};
    scanf("%d%*c",&n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%*c",&num);
        ReadNum(Number, num, i);
    }
    DataRank(Number, n);
    PrintData(Number, n);
    return 0;
}

void ReadNum(int Number[], int num, int i)
{
    int j, flag = 0;
    if (i == 0) Number[i] = num;
    else
    {
        for (j = 0; j < i; j++)
        {
            if (Number[j] == num)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)  Number[i] = num;
    }
}

void DataRank(int Number[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (Number[j] < Number[i])
            {
                temp = Number[i];
                Number[i] = Number[j];
                Number[j] = temp;
            }
        }
    }
}

void PrintData(int Number[], int n)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
    {
        if (Number[i] != 0) count++;
    }
    printf("%d\n",count);
    for (i = 0; i < n; i++)
    {
        if (Number[i] != 0) printf("%d ",Number[i]);
    }
}