#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void onePtr(struct Node *head){
    printf("Address head: %p\n", head);

    struct Node *oneNode = malloc(sizeof(struct Node));
    oneNode->data = 15;
    oneNode->next = NULL;

    head = oneNode;

    printf("Next oneNode: %p\n", head);
}

void doublePtr(struct Node **head){
    printf("Address head: %p\n", *head);

    struct Node *doubleNode = malloc(sizeof(struct Node));
    doubleNode->data = 20;
    doubleNode->next = NULL;

    *head = doubleNode;

    printf("Next DoubleNode: %p\n", *head);
}

int main(){
    struct Node *head    = NULL;
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = 10;
    newNode->next = NULL;
    
    head = newNode;

    printf("Original ptr: %p\n", head);
    
    printf("\nDouble ptr result:\n");
    doublePtr(&head);
   
    printf("\nOne ptr result:\n");
    onePtr(head);
  
    printf("\nLast result head: %p\n", head);

    return 0;
}
