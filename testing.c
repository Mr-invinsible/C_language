#include <stdio.h>

int print(int a[][3]);

int main()
{
    int i, j, a[3][3], sum = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (i == 1 && j == 1)
                continue;
            scanf("%d", &a[i][j]);
            sum += a[i][j];
        }
        printf("\n");
    }
    a[1][1] = sum;
    print(a);
    return 0;
}

int print(int a[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
