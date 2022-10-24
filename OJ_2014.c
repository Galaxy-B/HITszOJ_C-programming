#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void)
{
    char str[101], num[11];
    gets(str);
    int length = strlen(str), i, j, k;
    for (i = 0; i < length; i++)
    {
        j = 0, k = i;
        while (isdigit(str[k]) == 1)
        {
            num[j] = str[k];
            if (isdigit(str[k + 1]) == 1)
            {
                i++;
                j++;
                k++;
                continue;
            }
            else
            {
                k++;
                num[j + 1] = '\0';
                printf("%10s\n", num);
            }
        }
    }
    return 0;
}