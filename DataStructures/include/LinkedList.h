#ifndef LLFUNCTIONS_H
#define LLFUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Node {
    int data;
    struct Node *next;
};

void insert(struct Node **head, struct Node *temp, int value);           // Creates a Node at the beginning for LL generation

void printList(struct Node **head);                                      // Shows the LL in the screen 

void sortList(struct Node *head);                                        // Sorts the LL (selection sort) 

void addNode(struct Node **head, int position, struct Node **newNode);   // Adds a new node to a specific position

void deleteNode(struct Node **head, uint8_t position);                   // Deletes a NODE at a specific position 

void generateRandomList(struct Node **head, uint8_t *size);              // Regenerate the LL 

struct Node *getLinkedList(uint8_t size);                                // Generates a random LL and returns the Head

void freeList(struct Node *head);                                        // Free the LL 

int linkedListTest();                                                    // General test function for LL (main.c)

#endif // LLFUNCTIONS_H!
