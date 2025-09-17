#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
    struct NODE *prev;
    int value;
    struct NODE *next;
} NODE;

void freeAll(NODE **head) {
    NODE *ptr = *head;
    while (ptr != NULL) {
        NODE *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    *head = NULL;
}

void insert(NODE **head, int value) {
    NODE *n = (NODE *)malloc(sizeof(NODE));
    if (n == NULL) {
        printf("Failed to allocate memory.\n");
        return;
    }

    n->value = value;
    n->next = NULL;
    n->prev = NULL;

    if (*head == NULL) {
        *head = n;
        return;
    }

    NODE *ptr = *head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->prev = ptr;
}

void delete(NODE **head, int value) {
    if (*head == NULL) {
        printf("List is Empty\n");
        return;
    }

    NODE *ptr = *head;

    // Find the node to delete
    while (ptr != NULL && ptr->value != value) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Value not found\n");
        return;
    }

    printf("Deleted: %d\n", ptr->value);
    if(ptr == *head) {
        *head = ptr->next;
        if(*head != NULL) {
            (*head)->prev = NULL;
        }
    } else {
        if(ptr->prev != NULL) {
            ptr->prev->next = ptr->next;
        }
        if(ptr->next != NULL) {
            ptr->next->prev = ptr->prev;
        }
    }
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
                    printf("<--[%p]--%i--[%p]-->", (void*)ptr->prev, ptr->value, (void*)ptr->next);
                    ptr = ptr->next;
                }
                printf("\n");
                break;
            case 4:
                freeAll(&head);
                printf("Exited");
                return 0;
                break;
            default:
                freeAll(&head);
                printf("Program terminated");
                return 0;
        }
    }
}