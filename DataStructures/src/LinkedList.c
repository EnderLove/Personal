#include <stdint.h>
#include <time.h>

#include "../include/LinkedList.h"
#include "../include/common.h"

void insert(struct Node **head, int value) {
    struct Node *temp = malloc(sizeof(struct Node)); 
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
        printf("\tPos: %3d || Value: %3d || Address: %p || Next: %p\n", i, it->data, it, it->next);
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
        for (int i = 0; i < position - 1 && it != NULL; i++) it = it->next;
        (*newNode)->next = it->next;
        it->next = *newNode;
    } else {
        (*newNode)->next = *head;
        *head = *newNode;
    }
}

void deleteNode(struct Node **head, uint8_t position) {
    if (*head == NULL) return; // If the list is empty and the position is less than 0 then return;

    struct Node *temp = *head;

    if (position == 0){     // If possition == 0 then head goes to next and temp is free()
        *head = temp->next;
        free(temp);
        return;
    }

    for (uint8_t i = 0; temp != NULL && i < position - 1; i++){
        temp = temp->next; // While not in the end of the list and in a valid position then temp reach the position
    }

    if (temp == NULL || temp->next == NULL) return;

    struct Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void generateRandomList(struct Node **head, uint8_t *size){
    uint8_t minRange = 0;
    uint8_t maxRange = 0;
    uint8_t value    = 0;

    printf("Insert the size of the list 0 - 255: \n");
    *size = getInputUint8();

    do {
        printf("Insert the minimal range of elements value < 0: "); // Minimal value in the list
        minRange = getInputUint8();
        printf("Insert the max range of elements value > 255: "); // Maximal value range of values in the list 
        maxRange = getInputUint8();

        if (maxRange < minRange)
            printf("\nMax Range must be greater than Min Range!!!\n\n");

    } while (maxRange < minRange);

    for (int i = *size; i > 0; i--){
        value = (rand() % (maxRange - minRange)) + (minRange + 1);
        insert(&(*head), value);
    }
}

struct Node *getLinkedList(uint8_t size){
    struct Node *head = NULL;
    uint8_t value = 0;
    
    while (size-- > 0){
        value = (rand() % 10);
        insert(&head, value);
    }
    return head;
}

void freeList(struct Node *head){
    struct Node *temp = NULL;

    while (head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
}

int linkedListTest() {
    srand((unsigned int)time(NULL));
    
    uint8_t size      = 0;
    uint8_t value     = 0;
    uint8_t position  = 0;
    uint8_t userInput = 0;

    struct Node *head = NULL;

    printf("Generate random LL or manual LL? 1/0: "); // Decide if work with a  random value list or not
    userInput = getInputUint8();

    if (userInput == 1) {
        generateRandomList(&head, &size);
    } else {
        printf("Insert the size of the list 0 - 255: \n"); // Set the size of the list
        size = getInputUint8();

        for (int i = size; i > 0; i--) {

            printf("Insert the value of the %d element 0 - 255: \n", i); // Manual value insertion
            value = getInputUint8();

            insert(&head, value);
        }
    }
    
    while (userInput != 5) {
        system(CLEAR);

        printf("\n\n\t========================== LINKED LIST TESTING ==========================\n\n");
        printList(&head);

        printf("\n===== OPTIONS =====\n1)Add Node\n2)Delete Node\n3)Sort List\n4)Regen List\n5)Exit\n");
        userInput = getInputUint8();

        switch (userInput) {
            case 1:
                printf("Set the position: ");
                position = getInputUint8();

                if (position > size - 1) break; 

                printf("Set the value: ");
                value = getInputUint8();

                struct Node *temp = malloc(sizeof(struct Node));

                temp->data = value;

                addNode(&head, position, &temp);
                break;

            case 2:
                printf("Delete Position: ");
                position = getInputUint8();
                deleteNode(&head, position);
                break;

            case 3:
                sortList(head);
                break;

            case 4:
                freeList(head);
                head = NULL;
                generateRandomList(&head, &size);
                break;

            case 5:
                freeList(head);
                printf("Linked List Free!\n");
                break;

            default:
                break;
        }
    }
    return 0;
}
