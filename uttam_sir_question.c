#include <stdio.h>

int lcm_2(int smallest, int a, int b)
{
    int lcm = 1;
    for (int i = 1; i <= smallest; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            printf("%d\n",i);
            lcm *= i;
            printf("%d\n",lcm);
            a /= i;
            printf("%d\n",a);
            b = b / i;
            printf("%d\n",b);
        }
    }printf("final lcm %d\n",lcm);
    lcm = lcm * a * b;
    printf("super final lcm %d\n",lcm);
    return lcm;
}

int main(int argc, char const *argv[])
{
    int a, b, smallest;
    printf("enter the value of a,b : \n");
    scanf("%d%d", &a, &b);
    smallest = (b > a) ? a : b;
    printf("%d\n",smallest);
    printf("your lcm is : %d\n", lcm_2(smallest, a, b));
    return 0;
}
