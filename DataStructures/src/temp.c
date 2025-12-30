#include <time.h>

#include "../include/LinkedList.h"
#include "../include/common.h"

void printListTemp(struct Node **head) {
    struct Node *it = *head;
    int i = 0;

    while (it != NULL) {
        printf("\t|| Pos: %3d || Value: %3d || \n", i, it->data);
        it = it->next;
        i++;
    }
}


int tempTest() {
    srand((unsigned int)time(NULL));
    
    uint8_t size      = 0;
    uint8_t value     = 0;
    uint8_t position  = 0;
    uint8_t userInput = 0;

    struct Node *head = NULL;

    printf("Generate random list or manual list 1/0: "); // Decide if work with a  random value list or not
    userInput = getInputUint8();

    if (userInput == 1) {
        generateRandomList(&head, &size);
    } else {
        printf("Insert the size of the list: \n"); // Set the size of the list
        size = getInputUint8();

        for (int i = size; i > 0; i--) {
            struct Node *temp = malloc(sizeof(struct Node));

            printf("Insert the value of the %d element: \n", i); // Manual value insertion
            value = getInputUint8();

            insert(&head, temp, value);
        }
    }
    
    while (userInput != 5) {
        system(CLEAR);

        printf("\n\n\t================== LIST TESTING ===================\n\n");
        printListTemp(&head);

        printf("\n===== OPTIONS =====\n1)Add Value\n2)Delete Value\n3)Sort List\n4)Regen List\n5)Exit\n");
        userInput = getInputUint8();

        switch (userInput) {
            case 1:
                printf("Set the position: ");
                position = getInputUint8();

                if (position > size || position < 0)
                    break;

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
                printf("List Free!\n");
                break;

            default:
                break;
        }
    }
    return 0;
}
