#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node node;
void create(int n,node *head)
{ node *temp;
    temp=head;
    for(int i=1;i<n;i++)
    {
        int a;
        printf("ELEMENT");
        scanf("%d",&a);
        node * newnode=(node *)malloc(sizeof(node));
        newnode->data=a;
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;        
    }
}
void display(node *head)
{
    node *temp;
    temp=head;
    while (temp!=NULL)
    {
        printf("Data: %d\n",temp->data);
        temp=temp->next;
    }
}
void add(int val,node **head,int pos)
{  
    node *temp=*head;
    node *newNode=(node *)malloc(sizeof(node));
    newNode->data=val;
    newNode->next=NULL;
    if (pos==0)
    {
        newNode->next=*head;
        *head=temp;
    }
    else if(pos==4)
    {
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
            temp=temp->next;
        }
        if(temp->next!=NULL)
        {
            node *temp2;
            temp2=temp->next;
            temp->next=newNode;
            newNode->next=temp2;
        }
        else
        {
            temp->next=newNode;
        }
    }
}


void main()
{
    int a;
    node *head=(node*)malloc(sizeof(node));
    printf("ELEMENT 1");
    scanf("%d",&a);
    head->data=a;;
    head->next=NULL;
    create(3,head);
    //printf("%d",head);
    display(head);
    add(10,&head,2);
    //printf("%d",head);
    display(head);
   
}

