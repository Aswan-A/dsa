#include<stdio.h>
#define MAX 5
int front=-1;
int rear=-1;

void enqueue(int arr[]){
    if((rear+1)%MAX==front){
        printf("Queue overflow");
    }
    else{
if(front==-1){
    front=0;
}
rear=(rear+1)%MAX;
scanf("%d",&arr[rear]);
    }

}

void display(int arr[]){
    int i=front;
    if (front==-1 ){
        printf("\nempty");
        
        
    }
    else{
  while(i!=rear){
    printf("%d",arr[i]);
    i=(i+1)%MAX;
  }
  printf("%d",arr[rear]);}
}

void dequeue(int arr[]){
if(front==-1){
    printf("\nQueue underflow");
    
}
else if (front==rear){
    printf("%d",arr[front]);
    front=rear=-1;
}
else{
    
    printf("\n%d",arr[front]);
    front=(front+1)%MAX;
}

}


void main(){
    int n;
int arr[MAX];
while(1){
    printf("\n1-enqueue 2-dequeue 3-display 4-exit\n");
    scanf("%d",&n);
    if (n==4){
        break;
    }
    else if(n==1){
        enqueue(arr);
    }
    else if(n==2){
        dequeue(arr);
    }   
    else if (n==3){
        display(arr);
    }
}

    
}