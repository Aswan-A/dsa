
#include <stdio.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int X);
void dequeue();
void display();

void main() {
    int choice, item;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1) {
            if (rear == N - 1) {
                printf("Queue is Full\n");
            } else {
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
            }
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            display();
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
}

void enqueue(int X) {
    if (rear == N - 1) {
        printf("Queue is Full\n");
    } else {
        if (front == -1 && rear == -1) {
            front = rear = 0;
        } else {
            rear++;
        }
        queue[rear] = X;
        printf("Enqueued item: %d\n", X);
    }
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Dequeued item: %d\n", queue[front]);
        if (front == rear) { 
            front = rear = -1;
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements:\n");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}



