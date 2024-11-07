#include <stdio.h>

void input(int *arr ,int n);

int binarySearch(int arr[], int low, int high, int x)
{
int comparison=0;
    while (low <= high) {
  	comparison++;
    
        int mid = (low + high) / 2;


        if (arr[mid] == x){
        printf("\ncomparison: %d\n",comparison);
        return mid;
            }

        if (arr[mid] < x)
            low = mid + 1;

      
        else
            high = mid - 1;
    }
     printf("\ncomparison: %d\n",comparison);
    return -1;
}


void main()
{   int n; 
    printf("Enter nbr of elements: ");
    scanf("%d",&n);
    int arr[n];
    input(arr,n);
    int x;
    printf("Search element: ");
    scanf("%d",&x);
    int result = binarySearch(arr, 0, n - 1, x);
   if (result == -1) 
            {printf("Element is not present in array\n");}

   else {
    printf("Element is present at index %d\n",result+1);}

}

void input(int *arr ,int n){
int i;
for (i=0;i<n;i++){
printf("Enter %d elements: ",i+1);
scanf("%d",arr++);
}
}

