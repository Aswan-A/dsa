#include<stdio.h>
#define MAX 5
int top=-1;

void push(int arr[]){
    if(top>=MAX-1){
        printf("Stack overflow");
    }
    else{

scanf("%d",&arr[++top]);
    }

}

void display(int arr[]){
    int i;
    if (top==-1){
        printf("\nempty");
        return ;
    }
    for(i=0;i<top+1;i++){
        printf("\n%d",arr[i]);
    }
}

void pop(int arr[]){
if(top==-1){
    printf("\nStack underflow");
}
else{
    printf("\n%d",arr[top--]);
}

}


void main(){
    int n;
int arr[MAX];
while(1){
    printf("\n1-push 2-pop 3-display 4-exit\n");
    scanf("%d",&n);
    if (n==4){
        break;
    }
    else if(n==1){
        push(arr);
    }
    else if(n==2){
        pop(arr);
    }   
    else if (n==3){
        display(arr);
    }
}

    
}