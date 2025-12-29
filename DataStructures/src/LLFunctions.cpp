#include "../include/LLFunctions.h"

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

void deleteNode(struct Node **head, int position, uint8_t size) {
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
}
