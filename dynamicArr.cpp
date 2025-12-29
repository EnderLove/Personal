#include <stdlib.h>
#include <stdio.h>

int allocFunc()
{
    int size;

    printf("Enter the size of the array\n");
    scanf("%d", &size);

    int *A = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        A[i] = i;
    }

    int *B = (int*)realloc(A, 0); //equivalent to free(A)
    int *B = (int*)realloc(NULL, size * sizeof(int)); //equivalent to malloc

    for (int i = 0; i < size; i++)
    {
        printf("%d\n", B[i]);
    }

    return 0;
}


int main()
{
    int arrSize = 1;

    int *ptrArr;

    while (arrSize > 0)
    {
        printf("Insert the size of the array:\n");
        scanf("%d", &arrSize);

        ptrArr = (int*)malloc(arrSize * sizeof(int));

        for (int i = 0; i < arrSize; i++)
        {
            ptrArr[i] = i;
            printf("%d\n", *(ptrArr + i));
        }

        free(ptrArr);
        ptrArr = NULL;

        printf("Done!\n");
    }



    return 0;
}