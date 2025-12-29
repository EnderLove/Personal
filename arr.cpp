#include <iostream>
using namespace std;

int main() 
{
    const int SIZE = 10;

    int nums[SIZE];
    int newArr[SIZE];
    int iterator = 0;
    bool repeated;

    cout << "Ingrese 10 numeros: " << endl;
    for (int i = 0; i < SIZE; i++) 
    {
        cin >> nums[i];
    }

    for (int i = 0; i < SIZE; i++) 
    {
        repeated = false;

        for (int j = 0; j < iterator; j++)
        {
            if (nums[i] == newArr[j]) 
            {
                repeated = true;
                break;
            }
        }
        if (!repeated) 
        {
            newArr[iterator] = nums[i];
            iterator++;
        }
    }

    cout << "\nElementos sin repetir: " << endl;
    for (int i = 0; i < iterator; i++) 
    {
        cout << newArr[i] << " ";
    }

    cout << endl;
    return 0;
}
