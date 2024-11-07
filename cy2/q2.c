#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;
    printf("%d pushed to stack\n", data);
    return newNode;
}

struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return NULL;
    }
    int poppedData = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    printf("%d popped from stack\n", poppedData);
    return top;
}

void displayStack(struct Node* top) {
    printf("Stack: ");
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}

struct Node* enqueue(struct Node* rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (rear != NULL) {
        rear->next = newNode;
    }
    printf("%d enqueued to queue\n", data);
    return newNode;
}

struct Node* dequeue(struct Node* front, struct Node* rear) {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return NULL;
    }
    int dequeuedData = front->data;
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    printf("%d dequeued from queue\n", dequeuedData);
    return front;
}

void displayQueue(struct Node* front) {
    printf("Queue: ");
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}

struct Node* enqueueCircular(struct Node* front, struct Node* rear, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = front;
    if (rear != NULL) {
        rear->next = newNode;
    } else {
        front = newNode;
    }
    printf("%d enqueued to circular queue\n", data);
    return newNode;
}

struct Node* dequeueCircular(struct Node* front, struct Node* rear) {
    if (front == NULL) {
        printf("Circular Queue Underflow\n");
        return NULL;
    }
    int dequeuedData = front->data;
    struct Node* temp = front;
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;
    }
    free(temp);
    printf("%d dequeued from circular queue\n", dequeuedData);
    return front;
}

void displayCircularQueue(struct Node* front, struct Node* rear) {
    struct Node* temp = front;
    printf("Circular Queue: ");
    if (front != NULL) {
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != front);
    }
    printf("NULL\n");
}

int main() {
    struct Node* stack = NULL;
    struct Node* queueFront = NULL;
    struct Node* queueRear = NULL;
    struct Node* circularFront = NULL;
    struct Node* circularRear = NULL;

    int choice, data;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push to Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue to Queue\n");
        printf("5. Dequeue from Queue\n");
        printf("6. Display Queue\n");
        printf("7. Enqueue to Circular Queue\n");
        printf("8. Dequeue from Circular Queue\n");
        printf("9. Display Circular Queue\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                stack = push(stack, data);
                break;
            case 2:
                stack = pop(stack);
                break;
            case 3:
                displayStack(stack);
                break;
            case 4:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                queueRear = enqueue(queueRear, data);
                if (queueFront == NULL) {
                    queueFront = queueRear;
                }
                break;
            case 5:
                queueFront = dequeue(queueFront, queueRear);
                break;
            case 6:
                displayQueue(queueFront);
                break;
            case 7:
                printf("Enter data to enqueue in circular queue: ");
                scanf("%d", &data);
                circularRear = enqueueCircular(circularFront, circularRear, data);
                if (circularFront == NULL) {
                    circularFront = circularRear;
                }
                break;
            case 8:
                circularFront = dequeueCircular(circularFront, circularRear);
                break;
            case 9:
                displayCircularQueue(circularFront, circularRear);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
