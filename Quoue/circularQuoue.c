#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return ((front == 0 && rear == MAX - 1) || ((rear + 1) % MAX == front));
}

// Function to check if the queue is empty
int isEmpty() {
    return (front == -1);
}

// Function to insert an element in the circular queue
void insert(int value) {
    if (isFull()) {
        printf("Queue is Full\n");
        return;
    }
    if (front == -1) { // First element
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = value;
    printf("Inserted %d\n", value);
}

// Function to delete an element from the circular queue
void delete() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    if (front == rear) {
        // Queue has only one element, reset to empty
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Function to display the elements of the circular queue
void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Example main function to test the circular queue
int main() {
    int choice, value;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
