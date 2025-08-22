#include <stdio.h>
#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX_SIZE - 1;
}

int isEmpty(Queue *q) {
    return q->front > q->rear;
}

int enqueue(Queue *q, int value) {
    if (isFull(q)) {
        // Queue is full
        return 0;
    }
    q->rear++;
    q->data[q->rear] = value;
    return 1;
}

int dequeue(Queue *q, int *value) {
    if (isEmpty(q)) {
        // Queue is empty
        return 0;
    }
    *value = q->data[q->front];
    q->front++;
    return 1;
}

void printQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->data[i]);
    }
    printf("\n");
}
