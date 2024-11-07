#include<stdio.h>
#include<stdlib.h>

// Define a node structure
struct node{
    int data;
    struct node *next;
};

// Declare front and rear globally to manage the queue
struct node* front = NULL;
struct node* rear = NULL;

// Function to enqueue (insert at the rear of the queue)
void enqueue(int d){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;

    if(rear == NULL){  // If the queue is empty, both front and rear are the same
        front = rear = newnode;
    } else {
        rear->next = newnode;  // Rear's next points to the new node
        rear = newnode;        // Update rear to the new node
    }
    printf("Enqueued %d into the queue.\n", d);
}

// Function to dequeue (remove from the front of the queue)
void dequeue(){
    if(front == NULL){  // If the queue is empty
        printf("Queue is empty! Nothing to dequeue.\n");
        return;
    }

    struct node *temp = front;
    front = front->next;  // Move front to the next node

    // If front becomes NULL, set rear to NULL as well
    if(front == NULL){
        rear = NULL;
    }

    printf("Dequeued %d from the queue.\n", temp->data);
    free(temp);  // Free the dequeued node
}

// Function to display the queue
void display(){
    struct node *temp = front;
    if(front == NULL){
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); // End of the queue
}

// Main function with a menu to perform operations
int main(){
    int choice, data;

    while(1){
        printf("\n1-Enqueue\n2-Dequeue\n3-Display\n4-Exit\n");
        scanf("%d", &choice);

        switch(choice){
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
