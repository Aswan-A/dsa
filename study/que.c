#include<stdio.h>
#define MAX 5
int front=-1;
int rear=-1;

void enqueue(int arr[]){
    if(rear>=MAX-1){
        printf("Queue overflow");
    }
    else{
if(front==-1){
    front=0;
}
scanf("%d",&arr[++rear]);
    }

}

void display(int arr[]){
    int i;
    if (front==-1 ){
        printf("\nempty");
        
        
    }
    else{
    for(i=front;i<rear+1;i++){
        printf("\n%d",arr[i]);
    }}
}

void dequeue(int arr[]){
if(front==-1){
    printf("\nQueue underflow");
    
}
else{
    printf("\n%d",arr[front++]);
    if(front>rear){
        front=rear=-1;
    }
  
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