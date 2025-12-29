#include <stdio.h>

int sum_digit(int num)
{
    if (num == 0) return 0; 
    int digit = num % 10;
    int sum = digit + sum_digit(num / 10);
    printf("digit: %3d  || sum: %3d\n", digit, sum);
    return sum;
}

int main()
{
    int num = 0;

    printf("Insert a num:\n");
    scanf("%d", &num);

    int sum = sum_digit(num);

    printf("%d\n", sum);

    return 0;
}