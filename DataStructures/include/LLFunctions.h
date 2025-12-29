#ifndef LLFUNCTIONS_H
#define LLFUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef _WIN32
    #define CLEAR "clear"
#else
    #define CLEAR "cls"
#endif

struct Node {
    int data;
    struct Node *next;
};

void insert(struct Node **head, struct Node *temp, int value); 

void printList(struct Node **head); 

void sortList(struct Node *head); 

void addNode(struct Node **head, int position, struct Node **newNode);

void deleteNode(struct Node **head, int position, uint8_t size); 

void generateRandomList(struct Node **head, uint8_t *size); 

void freeList(struct Node *head); 

#endif // LLFUNCTIONS_H!
