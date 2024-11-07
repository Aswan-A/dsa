#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node *front=NULL,*rear=NULL;

void enqueue(){
    int a;
    struct node *newnode;
    
    printf("Enter your element: ");
    scanf("%d",&a);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=a;
    newnode->next=NULL;
    if (front==NULL){
  front=rear=newnode;}
  else{
  rear->next=newnode;
  rear=newnode;
  }
 

}
void dequeue(){
    struct node *temp;
    temp=front;
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    printf("%d",temp->data);
    free(temp);


}
void display(){
    struct node *temp;
    temp=front;
    if(front==NULL){
        printf("\nEmpty");
    }
    else{
    while(temp!=NULL){
        printf("\n%d",temp->data);
        temp=temp->next;
    }  printf("\n");  }}

void main(){
    

    int n,pos;
    while(1){
    printf("\n1-Enqueue 2-Dequeue 3-Display 4-exit: ");
    scanf("%d",&n);
    if(n==4){
        break;
    }
    else if(n==1){
       
        enqueue();     
    }

     else if(n==2){
        if(front==NULL){
            printf("Underflow");
        }
        else{
        dequeue();
       }
    }
     else if(n==3){
        display();
    }
}}