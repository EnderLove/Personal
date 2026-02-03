#include "../include/minHeapLib.h"

MinHeap::MinHeap(int capacity) : capacity(capacity), heapSize(0), heapArr(new int[capacity]) {}
MinHeap::MinHeap() : heapSize(0) {}

bool MinHeap::linearSearch(int val) const{
    for (int i = 0; i < heapSize; i++){
        if (heapArr[i] == val) return true;
        else return false;
    }
    return false;
}

void MinHeap::printHeap() const{
    for (int i = 0; i < heapSize; i++){ std::cout << heapArr[i] << " " << std::endl; }
}

int MinHeap::getHeight() const{ return ceil(log2(heapSize + 1) - 1); }




