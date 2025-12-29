#include <time.h>

#include "../include/LinkedList.h"
#include "../include/common.h"

int tempTest() {
    srand(time(NULL));
    
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

        printf("\n\n\t========================== LINKED LIST TESTING ==========================\n\n");
        printList(&head);

        printf("\n===== OPTIONS =====\n1)Add Node\n2)Delete Node\n3)Sort "
               "List\n4)Regen List\n5)Exit\n");
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

                deleteNode(&head, position, size);
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
