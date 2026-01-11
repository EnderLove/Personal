#include <stdio.h>

int *getMaxVal(int arr[], int size){
    int maxId = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] > arr[maxId]) maxId = i;
    }
    return  &arr[maxId]; 
}

int main(){

    int arr[] = {10, 11, 12, 13, 14, 15};
    
    int size = sizeof(arr) / sizeof(arr[0]);
        
    int *x = getMaxVal(arr, size);
    
    printf("ADDRESS: %p  || VALUE: %d \n", x, *x);
    printf("ADDRESS: %p  || VALUE: %d \n", &(arr[5]), arr[5]);

    *x = 20;

    printf("ADDRESS: %p  || VALUE: %d \n", x, *x);
    printf("ADDRESS: %p  || VALUE: %d \n", &(arr[5]), arr[5]);

    return 0;
}
