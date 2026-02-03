#ifndef MIN_HEAP_LIB_H
#define MIN_HEAP_LIB_H

#include <iostream>
#include <math.h>
class MinHeap{
    private:
        int *heapArr; //Pointer to array of elements in heap
        int capacity; //Maximun possible size of min heap
        int heapSize; //Current number of elements in min heap

    public:
        MinHeap(int capacity);
        MinHeap();

        bool linearSearch(int val) const;

        void printHeap() const;
        int getHeight() const;


};

#endif // MIN_HEAP_LIB_H!
