#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node *top=NULL;

void push(){
    int a;
    struct node *newnode;
    printf("Enter your element: ");
    scanf("%d",&a);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=a; 
    newnode->next=top;
    top=newnode;
}

void pop(){
    struct node *temp;
   
 
    if(top->next==NULL){
        printf("%d",top->data);
        free(top);
        top=NULL;
    }
   
    else {

        temp=top;
        printf("%d",top->data);
        top=top->next;
        free(temp);
    }


}
void display(){
    struct node *temp;
    temp=top;
    if(top==NULL){
        printf("\nEmpty");
    }
    while(temp!=NULL){
        printf("\n%d",temp->data);
        temp=temp->next;
    }  printf("\n");  }

void main(){
    

    int n;
    while(1){
    printf("\n1-Push 2-Pop 3-Display 4-exit: ");
    scanf("%d",&n);
    if(n==4){
        break;
    }
    else if(n==1){
      push();}
       
  

     else if(n==2){
        if(top==NULL){
            printf("Underflow");
        }
        else{
        pop();}
        }
    
     else if(n==3){
        display();
    }
}}