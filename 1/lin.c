#include<stdio.h>

void input(int *arr ,int n);
void search(int *arr,int n,int s);

void main(){
int i,n,s;
printf("Enter nbr of elements: ");
scanf("%d",&n);
int arr[n];
input(arr,n);
printf("Enter search element: ");
scanf("%d",&s);
search(arr,n,s);
}

void input(int *arr ,int n){
int i;
for (i=0;i<n;i++){
printf("Enter %d elements: ",i+1);
scanf("%d",arr++);
}
}

void search (int *arr,int n,int s){
int i,f=0;
for(i=0;i<n;i++){
if(arr[i]==s){
printf("element found at %d \n",i+1);
f=1;}
}
if (f==0){
printf("Element not found \n");}
}


