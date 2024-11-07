#include<stdio.h>
#include<stdlib.h>

// Define a node structure
struct node{
    int data;
    struct node *next;
};

// Declare head globally
struct node* head = NULL;

// Function to push (insert at the front) in the stack
void push(int d){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = head; // New node points to the current head
    head = newnode;       // Head becomes the new node
    printf("Pushed %d onto the stack.\n", d);
}

// Function to pop (delete at the front) in the stack
void pop(){
    if(head == NULL){
        printf("Stack is empty! Nothing to pop.\n");
        return;
    }

    struct node *temp = head;
    head = head->next; // Head now points to the next node
    printf("Popped %d from the stack.\n", temp->data);
    free(temp);        // Free the popped node
}

// Function to display the stack (linked list)
void display(){
    struct node *temp = head;
    if(head == NULL){
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n"); // End of the stack
}

// Main function with a menu to perform operations
int main(){
    int choice, data;

    while(1){
        printf("\n1-Push\n2-Pop\n3-Display\n4-Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                pop();
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
