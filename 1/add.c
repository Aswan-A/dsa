#include<stdio.h>

void input(int *arr1,int *arr2,int n);
void add(int *arr1,int *arr2,int n ,int *arr);
void out(int *arr,int n);

void main(){
int n;
printf("Degree of polynomial : ");
scanf("%d",&n);


int arr1[n+1];
int arr2[n+1];
int arr[n+1];

input(arr1,arr2,n);
add(arr1,arr2,n,arr);
out(arr,n);
printf("\n");
}


void input(int *arr1,int *arr2,int n){
int i;
printf("First polynomial \n");
for (i=0;i<n+1;i++){
printf("Enter coefficient of x^%d: ",i);
scanf("%d",&arr1[i]);
}
printf("\nSecond polynomial\n");
for (i=0;i<n+1;i++){
printf("Enter coefficient of x^%d: ",i);
scanf("%d",&arr2[i]);
}
}

void add(int *arr1,int *arr2,int n,int *arr){
int i;
for (i=0;i<n+1;i++){
arr[i]=arr1[i]+arr2[i];
}
}

void out(int *arr,int n){
int i;
for (i=n;i>=0;i--){
printf("%dx^%d",arr[i],i);
if (i!=0){
printf("+");}
}}
