#include <iostream>
#include <ctime>
#include <cstdlib>

void showArr(int arr[], int size, int step)
{
    std::cout << "Step " << step << " : ";

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << "\n";
}

void showArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Step" << arr[i] << ", ";
    }
    std::cout << "\n";
}

void bubbleSort(int arr[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        for (int i = 0; i < size - step - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                int temp   = arr[i];
                arr[i]     = arr[i + 1];
                arr[i + 1] = temp;

                
            }

            showArr(arr, size, i);
        }
    }

}

int main()
{
    srand(time(NULL));

    int sizeArr;
    int initialRange;
    int maxRange;

    std::cout << "Insert the size of the array: " << "\n";
    std::cin >> sizeArr;
    std::cout << "Insert the initial range of numbers: " << "\n";
    std::cin >> initialRange; 
    std::cout << "Insert the max range of numbers: " << "\n";
    std::cin >> maxRange;

    int* arr = (int*)malloc(sizeof(int) * sizeArr);

    for (int i = 0; i < sizeArr; i++)
    {
        arr[i] = (rand() % (maxRange - initialRange)) + initialRange; 
    }

    std::cout << "UNORDERED ARRAY OF SIZE " << sizeArr << "\n";
    showArr(arr, sizeArr);

    bubbleSort(arr, sizeArr);
    
    std::cout << "\n\nORDERED ARRAY OF SIZE " << sizeArr << "\n";
    showArr(arr, sizeArr);

    std::cout << "\n";

    return 0;
}