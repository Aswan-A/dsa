#include<stdio.h>

void input(int *arr ,int n);
void sort(int *arr,int n);
void output(int *arr ,int n);

void main(){
int i,n;
printf("Enter nbr of elements: ");
scanf("%d",&n);
int arr[n];
input(arr,n);
sort(arr,n);
output(arr,n);
printf("\n");
}



void input(int *arr ,int n){
int i;
for (i=0;i<n;i++){
printf("Enter %d elements: ",i+1);
scanf("%d",arr++);
}
}

void sort(int *arr ,int n ){
int i,j,nb;
for (i=0;i<n;i++){
for (j=0;j<n-1;j++){
if(arr[i]<arr[j]){
nb=arr[i];
arr[i]=arr[j];
arr[j]=nb;}
}}
}

void output(int *arr ,int n){
int i;
for (i=0;i<n;i++){
printf("%d \t",arr[i]);
}
}
