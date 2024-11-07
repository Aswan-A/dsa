#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *tree;
int capacity = 0;
int size = 0;

void createTree(int cap) {
    capacity = cap;
    tree = (int *)malloc(capacity * sizeof(int));
}

void insert(int value) {
    if (size >= capacity) {
        printf("Tree is full.\n");
        return;
    }
    tree[size++] = value;
}

void levelOrderTraversal() {
    if (size == 0) {
        printf("Tree is empty.\n");
        return;
    }
    for (int i = 0; i < size; i++)
        printf("%d ", tree[i]);
    printf("\n");
}

int height() {
    if (size == 0) return 0;
    return (int)log2(size + 1);
}

void menu() {
    int choice, value, cap;
    while (1) {
        printf("\n1. Create Tree\n2. Insert\n3. Level Order Traversal\n4. Height\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the capacity of the tree: ");
                scanf("%d", &cap);
                createTree(cap);
                printf("Tree created with capacity %d.\n", cap);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 3:
                printf("Level Order Traversal: ");
                levelOrderTraversal();
                break;
            case 4:
                printf("Height of the tree: %d\n", height());
                break;
            case 5:
                free(tree);
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}

