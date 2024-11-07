#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node *head=NULL;

void enter(int pos){
    int count=-1,a,i;
    struct node *newnode,*temp;
    temp=head;
    while(temp!=NULL){
        count+=1;
        temp=temp->next;
    }
    if(pos>count+1){
        printf("OutofBound\n");
        return;
    }
    printf("Enter your element: ");
    scanf("%d",&a);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=a;
    temp=head;
    if(head==NULL){
    head=newnode;
    }
    else if(pos==0){
        newnode->next=head;
        head=newnode;
    }
    else if(pos>count){
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    else{
        for(i=0;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }

}
void delete(int pos){
    struct node *temp,*temp1,*temp2;
    temp=temp1=temp2=head;
    int count=-1,i;
    while(temp!=NULL){
        count++;
        temp2=temp1;
        temp1=temp;
        temp=temp->next;
    }
    if(pos==0){
        temp=head;
        head=head->next;
        temp->next=NULL;
        free(temp);
    }
    else if(pos>count){
        printf("OutofBound");
    }
    else if(pos==count){
        temp2->next=NULL;
    free(temp1);
    }
    else if(pos<count){
        temp=temp1=NULL;
        for(i=0;i<pos;i++){
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=temp->next;
        temp->next=NULL;
        free(temp);
    }

}
void display(){
    struct node *temp;
    temp=head;
    if(head==NULL){
        printf("\nEmpty");
    }
    while(temp!=NULL){
        printf("\n%d",temp->data);
        temp=temp->next;
    }  printf("\n");  }

void main(){
    

    int n,pos;
    while(1){
    printf("\n1-Enter 2-Delete 3-Display 4-exit: ");
    scanf("%d",&n);
    if(n==4){
        break;
    }
    else if(n==1){
        printf("Enter pos: ");
        scanf("%d",&pos);
        if(pos>-1){
        enter(pos);}
        else{
            printf("Wrong position\n");
        }
    }

     else if(n==2){
        if(head==NULL){
            printf("Empty");
        }
        else{
        printf("Enter pos: ");
        scanf("%d",&pos);
        if(pos>-1){
        delete(pos);}
        else{
            printf("Wrong position\n");
        }}
    }
     else if(n==3){
        display();
    }
}}
