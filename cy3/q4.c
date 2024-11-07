#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum number of elements in the heap

int heap[MAX];
int heapSize = 0;

// Function prototypes
void insert(int element);
void deleteAtIndex(int index);
void minHeapify(int i);
int findKthSmallest(int k);
void displayHeap();

// Utility functions
int parent(int i) { return (i - 1) / 2; }
int leftChild(int i) { return 2 * i + 1; }
int rightChild(int i) { return 2 * i + 2; }

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Insert an element into the min-heap
void insert(int element) {
    if (heapSize == MAX) {
        printf("Heap overflow! Cannot insert element.\n");
        return;
    }
    heapSize++;
    int i = heapSize - 1;
    heap[i] = element;

    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }
}

// Delete element at a specific index from the min-heap
void deleteAtIndex(int index) {
    if (index < 0 || index >= heapSize) {
        printf("Invalid index!\n");
        return;
    }

    heap[index] = heap[heapSize - 1];
    heapSize--;
    minHeapify(index);
}

// Min-heapify function to maintain the min-heap property
void minHeapify(int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < heapSize && heap[left] < heap[smallest]) {
        smallest = left;
    }
    if (right < heapSize && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}

// Find the k-th smallest element in the min-heap
int findKthSmallest(int k) {
    if (k <= 0 || k > heapSize) {
        printf("Invalid value of k!\n");
        return -1;
    }

    int tempHeap[MAX];
    for (int i = 0; i < heapSize; i++) {
        tempHeap[i] = heap[i];
    }

    // Sort the copied array to find the k-th smallest element
    for (int i = 0; i < heapSize - 1; i++) {
        for (int j = i + 1; j < heapSize; j++) {
            if (tempHeap[i] > tempHeap[j]) {
                swap(&tempHeap[i], &tempHeap[j]);
            }
        }
    }

    return tempHeap[k - 1];  // k-th smallest element in sorted order
}

// Display the elements of the heap
void displayHeap() {
    if (heapSize == 0) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

// Main function to drive the menu
int main() {
    int choice, element, index, k;

    while (1) {
        printf("\nPriority Queue using Min-Heap\n");
        printf("1. Insert element\n");
        printf("2. Delete element at index\n");
        printf("3. Find k-th smallest element\n");
        printf("4. Display heap\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(element);
                break;

            case 2:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                deleteAtIndex(index);
                break;

            case 3:
                printf("Enter k to find k-th smallest element: ");
                scanf("%d", &k);
                int kthSmallest = findKthSmallest(k);
                if (kthSmallest != -1) {
                    printf("The %d-th smallest element is %d\n", k, kthSmallest);
                }
                break;

            case 4:
                displayHeap();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
