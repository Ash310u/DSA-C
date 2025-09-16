#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    int value;
    struct NODE *next;
} NODE;

void insert(NODE **head, int value) {
    NODE *n = malloc(sizeof(NODE));
    if(n == NULL) {
        printf("Failed to allocate memory.\n");
        return;
    }

    n->value = value;
    n->next = NULL;

    if(*head == NULL) {
        *head = n;
        return;
    }

    NODE *ptr = *head;
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = n;
}


// // Mistakes in the original delete function:
// // 1. Incorrect handling of deleting the head node.
// // 2. Incorrect initialization of 'prev' (should be NULL, not *head).
// // 3. The loop and logic do not properly traverse and delete nodes.
// // 4. Incorrect use of 'ptr-value' in printf (should be 'ptr->value').
// // 5. Freeing 'temp' after assigning 'prev->next = temp' is wrong; it deletes the next node unintentionally.
// // 6. The function does not update 'ptr' in the loop, leading to an infinite loop.
// // 7. No return after deletion, so it may try to access freed memory.
// // 8. No handling for the case when the value is not found.

// Here's a corrected version:

void delete(NODE **head, int value) {
    if (*head == NULL) {
        printf("List is Empty\n");
        return;
    }

    NODE *ptr = *head;
    NODE *prev = NULL;

    // Check if the head node holds the value to delete
    if (ptr->value == value) {
        printf("Deleted: %d\n", ptr->value);
        *head = ptr->next;
        free(ptr);
        return;
    }

    // Traverse the list to find the node to delete
    while (ptr != NULL && ptr->value != value) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Value not found\n");
        return;
    }

    printf("Deleted: %d\n", ptr->value);
    prev->next = ptr->next;
    free(ptr);
}

int main() {
    NODE *head = NULL;
    int choise, x;
    while(1) {
        printf("Enter your choise: 1. Insert, 2. Delete, 3. Display, 4. Exit\n");
        scanf("%d", &choise);
        switch (choise) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &x);
                insert(&head, x);
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &x);
                delete(&head, x);
                printf("\n");
                break;
            case 3:
                NODE *ptr = head;
                while (ptr != NULL) {
                    printf("%i-->", ptr->value);
                    ptr = ptr->next;
                }
                printf("\n");
                break;
            case 4:
                printf("Exited");
                return 0;
                break;
            default:
                printf("Program terminated");
                return 0;
        }
    }
}