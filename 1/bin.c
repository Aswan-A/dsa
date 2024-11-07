#include <stdio.h>
 

int binarySearch(int arr[], int l, int r, int x)
{
 
    if (r >= l) {
 
   
        int mid = (l + r)  / 2;
 
    
        if (arr[mid] == x)
            return mid;
 
     
        if (arr[mid] > x) {
            return binarySearch(arr, l, mid - 1, x);
        }
 
   
        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
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


void main(){
int n,ele;
printf("Enter nbr of elments: ");
scanf("%d",&n);
int arr[n];
int i;
for(i=0;i<n;i++){
printf("Enter your elements: ");
scanf("%d",&arr[i]);
}
printf("Enter search element ");
scanf("%d",&ele);

sort(arr,n);
 
    int index = binarySearch(arr, 0, n - 1, ele);
 
    if (index == -1) {
        printf("Element is not present in array");
    }
    else {
        printf("Element is present at index %d \n", index);
    }
 
  
}
