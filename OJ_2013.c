#include<stdio.h>

int i, j;
int ReadNum(int Array[]);
void ArraySwap(int Array[], int count);
void ArrayScale(int Array[], int count);
int Max(int num1, int num2);

int main(void)
{
    int Array1[50] = {0}, Array2[50] = {0}, count1 = 0, count2 = 0, count = 0;
    //读取数据
    count1 = ReadNum(Array1);
    count2 = ReadNum(Array2);
    //重新排序数组
    ArraySwap(Array1, count1);
    ArraySwap(Array2, count2);
    //运算
    count = Max(count1, count2);
    for (i = 0; i <= count; i++)
    {
        Array1[i] += Array2[i];
    }
    //进位运算
    ArrayScale(Array1, count);
    //再次重新排序后打印
    ArraySwap(Array1, count);
    if (Array1[count + 1] != 0) printf("%d", Array1[count + 1]);    //考虑末位进位的情况
    for (i = 0; i <= count; i++)
    {
        printf("%d", Array1[i]);
    }
    return 0;   
}

int ReadNum(int Array[])
{
    int count;
    for (i = 0, count = -1; (Array[i] = getchar()) != '\n'; i++)
    {
        Array[i] -= 48;
        count++;
    }
    Array[i] = 0;   //将末位读到的换行符归零
    return count;
}

void ArraySwap(int Array[], int count)
{
    int temp;
    for (i = 0, j = count; i < j; i++, j--)
    {
        temp = Array[i];
        Array[i] = Array[j];
        Array[j] = temp;
    }
}

int Max(int num1, int num2)
{
    if (num1 >= num2)   return num1;
    else                return num2;
}

void ArrayScale(int Array[], int count)
{
    for (i = 0; i <= count; i++)
    {
        Array[i + 1] += Array[i] / 10;
        Array[i] = Array[i] % 10;
    }    
}