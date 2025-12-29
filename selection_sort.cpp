#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CLEAR   "\033[2J\033[H"  // limpia pantalla y mueve cursor a 0,0

struct ArrayRand
{
    int*  arrRand = nullptr;
    char* pointer = nullptr;
};

void printArray(ArrayRand arr, int sizeArr, int first, int second, const char* colorA, const char* colorB)
{
    printf(CLEAR);

    // preparar pointer
    for (int i = 0; i < sizeArr; i++)
        arr.pointer[i] = ' ';

    if (first  >= 0) arr.pointer[first]  = '^';
    if (second >= 0) arr.pointer[second] = '^';

    // imprimir números con color
    for (int i = 0; i < sizeArr; i++)
    {
        if (i == first)
            printf("%s%3d%s", colorA, arr.arrRand[i], RESET);
        else if (i == second)
            printf("%s%3d%s", colorB, arr.arrRand[i], RESET);
        else
            printf("%3d", arr.arrRand[i]);
    }
    printf("\n");

    // imprimir flechas
    for (int i = 0; i < sizeArr; i++)
        printf("%3c", arr.pointer[i]);

    printf("\n");
    usleep(350000); // animación suave
}

void selectionSort(ArrayRand arr, int sizeArr)
{
    for (int i = 0; i < sizeArr - 1; i++) 
    {
        int min_idx = i;

        for (int j = i + 1; j < sizeArr; j++) 
        {
            if (arr.arrRand[j] < arr.arrRand[min_idx])
                min_idx = j;

            printArray(arr, sizeArr, j, min_idx, YELLOW, GREEN); // comparación
        }

        // mostrar antes del swap
        printArray(arr, sizeArr, i, min_idx, RED, GREEN);

        // swap
        int temp = arr.arrRand[i];
        arr.arrRand[i] = arr.arrRand[min_idx];
        arr.arrRand[min_idx] = temp;

        // mostrar después del swap
        printArray(arr, sizeArr, i, min_idx, GREEN, GREEN);
    }
}

ArrayRand generateArray(int arrSize, int minRange, int maxRange)
{
    int* arr = (int*)malloc(arrSize * sizeof(int));
    char* ptr = (char*)malloc(arrSize * sizeof(char));

    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = (rand() % (maxRange - minRange + 1)) + minRange;
        ptr[i] = ' ';
    }

    return {arr, ptr};
}

int main()
{
    srand(time(NULL));

    int arrSize, minRange, maxRange;

    printf("Insert array size: ");
    scanf("%d", &arrSize);
    printf("Insert min range: ");
    scanf("%d", &minRange);
    printf("Insert max range: ");
    scanf("%d", &maxRange);

    ArrayRand test = generateArray(arrSize, minRange, maxRange);

    selectionSort(test, arrSize);

    printf(RESET "\nFinal sorted array:\n");
    for (int i = 0; i < arrSize; i++)
        printf("%3d", test.arrRand[i]);
    printf("\n");

    free(test.arrRand);
    free(test.pointer);

    return 0;
}
