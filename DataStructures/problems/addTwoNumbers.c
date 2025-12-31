#include "../include/LinkedList.h"

int main(){
    
    uint8_t sizeList1 = 5;
    uint8_t sizeList2 = 5;

    struct Node *list1 = getLinkedList(sizeList1);
    struct Node *list2 = getLinkedList(sizeList2);
    
    printf("\n\t======== LIST 1 ========\n\n");
    printList(&list1);
    printf("\n\t======== LIST 2 ========\n\n");
    printList(&list2);

    return 0;
}
