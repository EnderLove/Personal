/*
    You are given two non-empty lists representing two non-negative integers.
    The digits are stored in reverse order, and each of their nodes contains a single digit.
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

#include "../include/LinkedList.h"

int getInvertNodeDigits(struct Node *list){
    
    struct Node *temp = list;
    int invertDigits= 0; 
    int i = 1;

    while (temp != NULL){
       invertDigits += (temp->data) * i;
       temp = temp->next;
       i *= 10;
    }
    
    printf("\nINVERT DIGITS: %d\n", invertDigits);

    return invertDigits;
}

struct Node *addTwoNumbers(struct Node *list1, struct Node *list2){

    int listNum1 = getInvertNodeDigits(list1);
    int listNum2 = getInvertNodeDigits(list2);

    int sumLists = listNum1 + listNum2;
    
    struct Node* head = NULL;

    while (sumLists > 0){
        
        int digit = sumLists % 10;
        sumLists /= 10;

    
    }
    
    return 0;
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
    
//    ans = addTwoNumbers(list1, list2);
    getInvertNodeDigits(list1);

    return 0;
}
