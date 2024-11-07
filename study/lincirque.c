#include <stdio.h>
#include <stdlib.h>
//Queue
struct node {
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL;

void enqueue(int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newnode->data = value;
    newnode->next = NULL;

    if (front == NULL) {  
        front = rear = newnode;
        rear->next = front; 
    } else {
        rear->next = newnode;
        rear = newnode;
        rear->next = front;  
    }
}

void dequeue() {
    if (front == NULL) {  
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    
    if (front == rear) {  
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;  
    }

    printf("Dequeued element: %d\n", temp->data);
    free(temp); 
}

void display() {
    if (front == NULL) {  
        printf("Queue is empty\n");
        return;
    }

    struct node *temp = front;
    printf("Queue elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("\n");
}

void cleanup() {
    while (front != NULL) {
        dequeue(); 
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n1-Enqueue 2-Dequeue 3-Display 4-Exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                cleanup();  
                exit(0);
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}
