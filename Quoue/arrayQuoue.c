#include <stdio.h>
#define MAX_SIZE 5

int isFull(int front, int rear) {
    // Queue is full if next position of rear is front (circular)
    return ((rear + 1) % MAX_SIZE) == front;
}

int isEmpty(int front, int rear) {
    // Queue is empty if front == -1
    return front == -1;
}

int enqueue(int q[], int value, int *front, int *rear) {
    if (isFull(*front, *rear)) {
        printf("Queue is full\n");
        return 0;
    }
    if (isEmpty(*front, *rear)) {
        *front = *rear = 0;
    } else {
        *rear = (*rear + 1) % MAX_SIZE;
    }
    q[*rear] = value;
    return 1;
}

int dequeue(int q[], int *value, int *front, int *rear) {
    if (isEmpty(*front, *rear)) {
        printf("Queue is empty\n");
        return 0;
    }
    *value = q[*front];
    if (*front == *rear) {
        // Queue has only one element, reset to empty
        *front = *rear = -1;
    } else {
        *front = (*front + 1) % MAX_SIZE;
    }
    return 1;
}

void printQueue(int q[], int front, int rear) {
    if (isEmpty(front, rear)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", q[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    int queue[MAX_SIZE];
    int rear = -1, front = -1;
    int choice, n, res;
    
    while (1) {
        printf("Enter the choice: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print Queue\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &n);
                enqueue(queue, n, &front, &rear);
                break;
            case 2:
                res = dequeue(queue, &n, &front, &rear);
                if (res)
                    printf("Dequeued: %d\n", n);
                break;
            case 3:
                printQueue(queue, front, rear);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}