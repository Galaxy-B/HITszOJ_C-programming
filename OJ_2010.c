#include<stdio.h>

int Sumup(int Score[40][3], int i);
int SumupCourse(int Score[40][3], int j, int n);
float Average(int Score[40][3], int i);
float AverageCourse(int Score[40][3], int j, int n);

int main(void)
{
    int n, i, j, temp;
    printf("Input the total number of the students(n<40):\n");
    scanf("%d", &n);
    //初始化学号字符数组
    char id[40][10];
    //进行学号和成绩的读入
    int Score[40][3];
    printf("Input student’s ID and score as: MT  EN  PH:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 9; j++)
        {
            scanf("%1d", &temp);
            id[i][j] = temp + 48;
        }
        id[i][9] = '\0';
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &Score[i][j]);
        }
    }
    //进行运算
    int Sum[40], SumofCourse[3];
    float Aver[40], AverofCourse[3];
    for (i = 0; i < n; i++)
    {
        Sum[i] = Sumup(Score, i);
        Aver[i] = Average(Score, i);
    }
    for (i = 0; i < 3; i++)
    {
        SumofCourse[i] = SumupCourse(Score, i, n);
        AverofCourse[i] = AverageCourse(Score, i, n);
    }
    //打印结果
    printf("Counting Result:\n");
    printf("Student’s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");
    for (i = 0; i < n; i++)
    {
        printf("%12s\t%4d\t%4d\t%4d\t%4d\t%5.1f\n", *(id + i), Score[i][0], Score[i][1], Score[i][2], Sum[i], Aver[i]);
    }
    printf("SumofCourse \t%4d\t%4d\t%4d\t",SumofCourse[0], SumofCourse[1], SumofCourse[2]);
    printf("\nAverofCourse\t%4.1f\t%4.1f\t%4.1f\t",AverofCourse[0], AverofCourse[1], AverofCourse[2]);
    return 0;
}

int Sumup(int Score[40][3], int i)
{
    int j, sum = 0;
    for (j = 0; j < 3; j++)
    {
        sum += Score[i][j];
    }
    return sum;
}

int SumupCourse(int Score[40][3], int j, int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += Score[i][j];
    }
    return sum;
}

float Average(int Score[40][3], int i)
{
    int j, sum = 0;
    for (j = 0; j < 3; j++)
    {
        sum += Score[i][j];
    }
    return (float)sum / 3;
}

float AverageCourse(int Score[40][3], int j, int n)
{
    int i, sum = 0;
    for (i = 0; i < n; i++)
    {
        sum += Score[i][j];
    }
    return (float)sum / n;
}