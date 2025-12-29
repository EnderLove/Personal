#include "LLFunctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void funcTemp() { int number = 0; }

int main() {
    srand(time(NULL));

    int size = 0;
    int value = 0;
    int position = 0;
    int userInput = 0;

    struct Node *head = NULL;

    printf("Generate random LL or manual LL? 1/0: "); // Decide if work wit- a
    // random value list or not
    scanf("%d", &userInput);

    if (userInput == 1) {
        generateRandomList(&head, &size);
    } else {
        printf("Insert the size of the list: \n"); // Set the size of the list
        scanf("%d", &size);

        for (int i = size; i > 0; i--) {
            struct Node *temp = malloc(sizeof(struct Node));

            printf("Insert the value of the %d element: \n",
                   i); // Manual value insertion
            scanf("%d", &value);

            insert(&head, temp, value);
        }
    }
    
    while (userInput != 5) {
        system(clear);

        printf("\n\n\t=========== TESTING ===========\n\n");
        printList(&head);

        printf("\n===== OPTIONS =====\n1)Add Value\n2)Delete Value\n3)Sort List\n4)Regen List\n5)Exit\n");
        scanf("%d", &userInput);

        switch (userInput) {
            case 1:
                printf("Set the position: ");
                scanf("%d", &position);

                if (position > size || position < 0)
                    break;

                printf("Set the value: ");
                scanf("%d", &value);

                struct Node *temp = malloc(sizeof(struct Node));

                temp->data = value;

                addNode(&head, position, &temp);
                break;
            case 2:
                printf("Delete Position: ");
                scanf("%d", &position);

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
