#include<stdio.h>
#include<stdlib.h>

// Define a node structure
struct node {
    int data;
    struct node* next;
};

// Declare front and rear globally to manage the circular queue
struct node* front = NULL;
struct node* rear = NULL;

// Function to enqueue (insert) an element in the circular queue
void enqueue(int d) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = d;

    if (front == NULL) {  // If the queue is empty
        front = rear = newnode;
        newnode->next = front;  // Make it circular
    } else {
        rear->next = newnode;   // Rear's next points to the new node
        rear = newnode;         // Update rear to the new node
        rear->next = front;     // Rear's next points to front to make it circular
    }

    printf("Enqueued %d into the queue.\n", d);
}

// Function to dequeue (remove) an element from the circular queue
void dequeue() {
    if (front == NULL) {  // If the queue is empty
        printf("Queue is empty! Nothing to dequeue.\n");
        return;
    }

    if (front == rear) {  // If there is only one element in the queue
        printf("Dequeued %d from the queue.\n", front->data);
        free(front);
        front = rear = NULL;  // Queue becomes empty
    } else {
        struct node* temp = front;
        printf("Dequeued %d from the queue.\n", front->data);
        front = front->next;   // Move front to the next node
        rear->next = front;    // Update rear's next to point to the new front
        free(temp);            // Free the dequeued node
    }
}

// Function to display the elements in the circular queue
void display() {
    if (front == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    struct node* temp = front;
    printf("Queue: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);  // Stop when we reach the front again
    printf("(back to front)\n");
}

// Main function with a menu to perform queue operations
int main() {
    int choice, data;

    while (1) {
        printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
