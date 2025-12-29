#include "../include/LinkedList.h"
#include "../include/common.h"

int main(){
    printf("Start test:\n1. LinkedList\n");
    uint8_t choice = getInputUint8();

    if (choice == 1) linkedListTest();

    return 0;
}
