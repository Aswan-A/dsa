#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    char song[20];
    struct Node* next;
};
typedef struct Node Node;

Node* createNode(char data[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->song, data);
    newNode->next = NULL;
    return newNode;
}

void enq(Node** front, Node** rear, char data[]){
    Node* newNode = createNode(data);
    if(*front == NULL || *rear == NULL){
        *front = newNode;
        *rear = newNode;
    } else {
        (*rear)->next = newNode;
        *rear = newNode;
        (*rear)->next = *front;
    }
}

void deq(Node** front, Node** rear){
    if(*front == NULL){
        printf("Queue is empty");
    } else if (*front == *rear){
        printf("\nRemoved successfully");
        printf("\nSong Removed: %s",(*front)->song);
        free(*front);
        *front = NULL;
        *rear = NULL;
    } else {
        printf("\nRemoved successfully");
        printf("\nSong Removed: %s",(*front)->song);
        Node* temp = (*front)->next;
        free(*front);
        *front = temp;
        (*rear)->next = *front;
    }
}

void playNext(Node** cur, Node* front){
    if(*cur == NULL){
        *cur = front;
    } else {
        *cur = (*cur)->next;
    }
    printf("\nNow playing: %s",(*cur)->song);
}

void printAll(Node* front, Node* rear) {
    if(front == NULL){
        printf("Queue is empty");
        return;
    }
    Node* temp = front;
    while (temp != rear) {
        printf("\n->%s ", temp->song);
        temp = temp->next;
    }
    printf("\n->%s", temp->song);
}

void main() {
    int ch;
    char data[20];
    Node* front = NULL;
    Node* rear = NULL;
    Node* cur = NULL;
    while(1){
        printf("\n\nOptions");
        printf("\n1.Add song");
        printf("\n2.Remove song");
        printf("\n3.Play next song");
        printf("\n4.Display playlist");
        printf("\n5.Exit");
        printf("\nEnter your choice(1-5):");
        scanf("%d",&ch);
        switch(ch){
            case 1:
              printf("\nEnter song name: "); 
              scanf("%s",data);
              enq(&front,&rear,data);
              break;
            
            case 2:
              deq(&front, &rear);
              break;
              
            case 3:
              playNext(&cur,front);
	          break;
	          
	        case 4:
              printAll(front, rear);
	          break;
	        
            default:
              return;
        }
    }
}

