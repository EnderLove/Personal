#include <stdlib.h>
#include <stdio.h>

void mulTable(const int &mulValue)
{
    for (int i = 1; i <= 12; i++)
        printf("%2d x %d = %3d\n", i, mulValue, mulValue * i);
}

int main()
{
    int num = 10;
    int* ptrNum = &num;

    *ptrNum = 5;

    mulTable(num);

    printf("%d\n", num);

    return 0;
}