/*
    You are given two non-empty lists representing two non-negative integers.
    The digits are stored in reverse order, and each of their nodes contains a single digit.
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

#include "../include/LinkedList.h"

int getInvertNodeDigits(struct Node *list){
    int inverDigits = 0;
    int i = 1;

    while (list != NULL){
        inverDigits += (list->data) * i;
        list = list->next;
        i *= 10;
    }
    return inverDigits;
}

struct Node *addTwoNumbers(struct Node *list1, struct Node *list2){

    int listNum1 = getInvertNodeDigits(list1);
    int listNum2 = getInvertNodeDigits(list2);

    int sumLists = listNum1 + listNum2;
    
    printf("\n\tINVERT LIST 1: %d\n\tINVERT LIST 2: %d\n\tSUM LISTS: %d\n\n", listNum1, listNum2, sumLists);
    
    struct Node* head = NULL;

    while (sumLists > 0){
        
        int digit = sumLists % 10;
        sumLists /= 10;

        insert(&head, digit);    
    }
    return head;
}

int main(){
    
    uint8_t sizeList1 = 5;
    uint8_t sizeList2 = 5;

    struct Node *list1 = getLinkedList(sizeList1);
    struct Node *list2 = getLinkedList(sizeList2);
    struct Node *ans   = NULL;

    printf("\n\t======== LIST 1 ========\n\n");
    printList(&list1);
    printf("\n\t======== LIST 2 ========\n\n");
    printList(&list2);
    
    printf("\n\t======== ANS ========\n\n");
    ans = addTwoNumbers(list1, list2);
    printList(&ans);
    
    return 0;
}
