
#include <stdio.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int X);
void dequeue();
void display();
int isFull();
int isEmpty();

void main() {
    int choice, item;

    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            if (isFull()) {
                printf("Queue is Full\n");
            } else {
                printf("Enter item to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
            }
        } else if (choice == 2) {
            if (isEmpty()) {
                printf("Queue is Empty\n");
            } else {
                dequeue();
            }
        } else if (choice == 3) {
            if (isEmpty()) {
                printf("Queue is Empty\n");
            } else {
                display();
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
}

int isFull() {
    return (front == (rear + 1) % N);
}

int isEmpty() {
    return (front == -1);
}

void enqueue(int X) {
    if (isFull()) {
        printf("Queue is Full\n");
    } else {
        if (front == -1) {
            front = 0; 
        }
        rear = (rear + 1) % N;
        queue[rear] = X;
        printf("Enqueued item: %d\n", X);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
    } else {
        printf("Dequeued item: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % N;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue elements:\n");
        int i = front;
        while (1) {
            printf("%d ", queue[i]);
            if (i == rear) {
                break;
            }
            i = (i + 1) % N;
        }
        printf("\n");
    }
}



