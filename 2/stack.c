#include <stdio.h>
#include <stdlib.h>
int MAX;
void push(int stack[],int item);
int pop(int stack[]);
void display(int stack[]);

int top = -1;

void main() {
  int ch,e;
  printf("Max is: ");
  scanf("%d",&MAX);
  int stack[MAX];
  while(1){
    printf("\n1-push\n2-pop\n3-display\n4-Exit\nEnter your choice: ");
    scanf("%d",&ch);
    if(ch==1){
        printf("Enter your element: ");
        scanf("%d",&e);
        push(stack,e);
    }
    else if(ch==2){
        printf("popped elment is:%d\n",pop(stack));
    }
    else if(ch==3){
        display(stack);
    }
    else if(ch==4){
        break;
    }
    else{
        printf("Invalid choice");
    }
  }
}

void push(int stack[],int item) {
    if (top >= MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        stack[++top] = item;
    }
}

int pop(int stack[]) {
    if (top == -1) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

void display(int stack[]) {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}