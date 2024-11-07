#include<stdio.h>

void input(int *arr1,int *arr2,int n);
void mul(int *arr1,int *arr2,int n ,int *arr);
void out(int *arr,int n);

void main(){
int n;
printf("Degree of polynomial : ");
scanf("%d",&n);


int arr1[n+1];
int arr2[n+1];

int arr[2*n+1];

input(arr1,arr2,n);
mul(arr1,arr2,n,arr);
out(arr,n);
printf("\n");
}


void input(int *arr1,int *arr2,int n){
int i;
printf("First polynomial \n");
for (i=0;i<n+1;i++){
printf("Enter coefficient of x^%d: ",n-i);
scanf("%d",&arr1[i]);
}
printf("\nSecond polynomial\n");
for (i=0;i<n+1;i++){
printf("Enter coefficient of x^%d: ",n-i);
scanf("%d",&arr2[i]);
}
}

void mul(int *arr1,int *arr2,int n,int *arr){
int i,j;
for (i=0;i<n+1;i++){
for(j=0;j<n+1;j++){
arr[i+j]+=arr1[i]*arr2[j];
}}
}

void out(int *arr,int n){
int i;
for (i=0;i<2*n+1;i++){
printf("%dx^%d",arr[i],2*n-i);

if (i!=2*n){
printf("+");}
}}
