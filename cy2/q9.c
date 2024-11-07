#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};
typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void enqFront(Node** head, int data){
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
    } else {
        (*head)->prev = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

void enqRear(Node** head, int data){
    Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
    } else {
        Node* temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        newNode->prev = temp;
        temp->next = newNode;
    }
}

void deqFront(Node** head){
    if(*head == NULL){
        printf("Dequeue is empty");
    } else if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
        printf("Dequeued successfully");
    } else {
        Node* temp = (*head)->next;
        temp->prev = NULL;
        free(*head);
        *head = temp;
        printf("Dequeued successfully");
    }
}

void deqRear(Node** head){
    if(*head == NULL){
        printf("Dequeue is empty");
        return;
    } else if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
        printf("Dequeued successfully");
        return;
    }
    Node* temp = *head;
    Node* prevTemp = *head;
    while(temp->next != NULL){
        prevTemp = temp;
        temp = temp->next;
    }
    prevTemp->next = NULL;
    free(temp);
    printf("Dequeued successfully");
}

void printAll(Node* head) {
    if(head == NULL){
        printf("NULL");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

void main() {
    int ch,data;
    Node* head = NULL;
    while(1){
        printf("\nOptions");
        printf("\n1.Enqueue node at front");
        printf("\n2.Enqueue node at rear");
        printf("\n3.Dequeue node at front");
        printf("\n4.Dequeue node at rear");
        printf("\n5.Display all elements");
        printf("\n6.Exit");
        printf("\nEnter your choice(1-6):");
        scanf("%d",&ch);
        switch(ch){
            case 1:
              printf("\nEnter the value: ");
              scanf("%d",&data);
              enqFront(&head,data);
              break;
            
            case 2:
              printf("\nEnter the value: ");
              scanf("%d",&data);
              enqRear(&head,data);
              break;
              
            case 3:
              deqFront(&head);
              break;
              
            case 4:
              deqRear(&head);
              break;
              
            case 5:
              printAll(head);
	          break;
              
            default:
              return;
        }
    }
}
