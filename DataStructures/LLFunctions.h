#ifndef LLFUNCTIONS_H
#define LLFUNCTIONS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

#ifdef _WIN32
const char *clear = "cls";
#else
const char *clear = "clear";
#endif

struct Node {
    int data;
    struct Node *next;
};

void insert(struct Node **head, struct Node *temp, int value) {
    temp->data = value;

    if (head != NULL)
        temp->next = *head;
    else
        temp->next = NULL;

    *head = temp;
}

void printList(struct Node **head) {
    struct Node *it = *head;
    int i = 0;

    while (it != NULL) {
        //printf("\tPos: %3d || Value: %3d || Address: %p || Next: %p\n", i, it->data, it, it->next);
        printf("\t|| Pos: %3d || Value: %3d || \n", i, it->data);
        it = it->next;
        i++;
    }
}

void sortList(struct Node *head) {
    struct Node *scope = head;

    while (scope != NULL) {
        struct Node *lowest = scope;
        struct Node *it     = scope->next;

        while (it != NULL) {
            if (it->data < lowest->data) {
                lowest = it;
            }
            it = it->next;
        }

        int tempVal  = scope->data;
        scope->data  = lowest->data;
        lowest->data = tempVal;

        scope = scope->next;
    }
}

void addNode(struct Node **head, int position, struct Node **newNode)
{
    struct Node *it = *head;

    if (position != 0) {
        for (int i = 0; i < position - 1 && it != NULL; i++) {
            it = it->next;
        }
        if (it == NULL) {
            printf("OUT OF SCOPE!!!");
            return;
        }
        (*newNode)->next = it->next;
        it->next = *newNode;
    } else {
        (*newNode)->next = *head;
        *head = *newNode;
    }
}

void deleteNode(struct Node **head, int position, u_int8_t size) {
    if (*head == NULL || position < 0) return; // If the list is empty and the position is less than 0 then return;

    struct Node *temp = *head;

    if (position == 0){     // If possition == 0 then head goes to next and temp is free()
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++){
        temp = temp->next; // While not in the end of the list and in a valid position then temp reach the position
    }
    
    if (temp == NULL || temp->next == NULL) return; // If position is out of scope then return

    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void generateRandomList(struct Node **head, u_int8_t *size) {
    int minRange = 0;
    int maxRange = 0;
    int value    = 0;

    printf("Insert the size of the list: \n"); // Set the size of the list
    scanf("%hhu", size);

    do {
        printf("Insert the minimal range of elements value: "); // minimal value in the list
        scanf("%d", &minRange);
        printf("Insert the max range of elements value: "); // maximal value range of values in the list
        scanf("%d", &maxRange);

        if (maxRange < minRange)
            printf("\nMax Range must be greater than Min Range!!!\n\n");

    } while (maxRange < minRange);

    for (int i = *size; i > 0; i--) {
        struct Node *temp = malloc(sizeof(struct Node));

        value = (rand() % (maxRange - minRange)) + (minRange + 1); // value generator

        insert(&(*head), temp, value);
    }
}

void freeList(struct Node *head) {
    struct Node *temp = NULL;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

bool checkByteSize(u_int8_t size){
    return (size >= 0 && size <= 255)? true : false;
}

#endif // LLFUNCTIONS_H!
