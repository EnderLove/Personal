#include <iostream>

int linearSearch(const int list[], int key, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (key == list[i]) return i;
    }
    return -1;
}


int main()
{
    const int ARR_SIZE = 6;

    int dists[ARR_SIZE] = {5, 7, 4, 3, 4, 9};
    int vel[ARR_SIZE]   = {1, 1, 1, 1, 1, 2};

    int time[ARR_SIZE];

    

    return 0;
}   