#include<stdio.h>
#include<stdlib.h>

// Define a node structure
struct node{
    int data;
    struct node *next;
};

// Declare head globally
struct node* head = NULL;

// Function to insert a node at the front
void insertAtFront(int d){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = head;
    head = newnode;
}

// Function to insert a node at the end
void insertAtEnd(int d){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;
    newnode->next = NULL;
    
    if(head == NULL){
        head = newnode;
    } else {
        struct node *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// Function to insert a node at a specific position
void insertAtPosition(int d, int pos){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = d;

    if(pos == 0){
        insertAtFront(d);
        return;
    }

    struct node *temp = head;
    for(int i = 0; i < pos - 1; i++){
        if(temp == NULL){
            printf("Position out of range.\n");
            return;
        }
        temp = temp->next;
    }
    
    newnode->next = temp->next;
    temp->next = newnode;
}

// Function to delete the front node
void deleteAtFront(){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    printf("Front node deleted.\n");
}

// Function to delete the last node
void deleteAtEnd(){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    
    if(head->next == NULL){  // Only one node
        free(head);
        head = NULL;
        printf("Last node deleted.\n");
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Last node deleted.\n");
}

// Function to delete a node at a specific position
void deleteAtPosition(int pos){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }

    if(pos == 0){
        deleteAtFront();
        return;
    }

    struct node *temp = head;
    struct node *prev = NULL;

    for(int i = 0; i < pos; i++){
        prev = temp;
        temp = temp->next;
        if(temp == NULL){
            printf("Position out of range.\n");
            return;
        }
    }

    prev->next = temp->next;
    free(temp);
    printf("Node at position %d deleted.\n", pos);
}

// Function to display the nodes in the list
void display(){
    struct node *temp = head;
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function with a menu to perform operations
int main(){
    int choice, data, pos;

    while(1){
        printf("\n1-Insert at Front\n2-Insert at End\n3-Insert at Position\n4-Delete at Front\n5-Delete at End\n6-Delete at Position\n7-Display\n8-Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter the value: ");
                scanf("%d", &data);
                insertAtFront(data);
                break;
            case 2:
                printf("Enter the value: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter the value: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insertAtPosition(data, pos);
                break;
            case 4:
                deleteAtFront();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
