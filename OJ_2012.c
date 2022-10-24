#include<stdio.h>
#define M 10
#define N 10

void Transpose1(int a[][N], int at[][M], int m, int n);

int main(void)
{
    int m, n, i, j, Array[M][N], ArrayT[N][M];
    scanf("%d%d",&m, &n);
    //为矩阵赋值
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",&Array[i][j]);
        }
    }
    //进行转置
    Transpose1(Array, ArrayT, m, n);
    //打印矩阵
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ",ArrayT[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void Transpose1(int a[][N], int at[][M], int m, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            at[i][j] = a[j][i];
        }
    }
}