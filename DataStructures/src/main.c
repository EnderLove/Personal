#include "../include/LinkedList.h"
#include "../include/temp.h"
#include "../include/common.h"

int main(){
    printf("Start test:\n1. LinkedList\n2. Temp");
    uint8_t choice = getInputUint8();

    if (choice == 1) linkedListTest();
    else if (choice == 2) tempTest();

    return 0;
}
