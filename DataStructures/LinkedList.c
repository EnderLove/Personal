#include "LLFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <stdbool.h>

int main() {
    srand(time(NULL));
    
    const u_int8_t MAX_LIST_SIZE = 255;
    
    u_int8_t size      = 0;
    u_int8_t value     = 0;
    u_int8_t position  = 0;
    u_int8_t userInput = 0;

    struct Node *head = NULL;

    printf("Generate random LL or manual LL? 1/0: "); // Decide if work with a  random value list or not
    scanf("%hhu", &userInput);

    if (userInput == 1) {
        generateRandomList(&head, &size);
    } else {
        do{
            printf("Insert the size of the list: \n"); // Set the size of the list
            scanf("%hhu", &size);
        } while (checkByteSize(size) != true);

        for (int i = size; i > 0; i--) {
            struct Node *temp = malloc(sizeof(struct Node));

            printf("Insert the value of the %d element: \n", i); // Manual value insertion
            scanf("%hhu", &value);

            insert(&head, temp, value);
        }
    }
    
    while (userInput != 5) {
        system(clear);

        printf("\n\n\t========================== LINKED LIST TESTING ==========================\n\n");
        printList(&head);

        printf("\n===== OPTIONS =====\n1)Add Node\n2)Delete Node\n3)Sort "
               "List\n4)Regen List\n5)Exit\n");
        scanf("%hhu", &userInput);

        switch (userInput) {
            case 1:
                printf("Set the position: ");
                scanf("%hhu", &position);

                if (position > size || position < 0)
                    break;

                printf("Set the value: ");
                scanf("%hhu", &value);

                struct Node *temp = malloc(sizeof(struct Node));

                temp->data = value;

                addNode(&head, position, &temp);
                break;
            case 2:
                printf("Delete Position: ");
                scanf("%hhu", &position);

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
