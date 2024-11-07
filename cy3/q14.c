#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10  // Size of the hash table

// Node structure for chaining
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hash Table structure for chaining
typedef struct HashTableChaining {
    Node* table[TABLE_SIZE];
} HashTableChaining;

// Hash function to get the index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Initialize hash table for chaining
void initHashTable(HashTableChaining* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
}

// Insert element in chaining-based hash table
void insert(HashTableChaining* hashTable, int key) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = hashTable->table[index];
    hashTable->table[index] = newNode;
    printf("Inserted %d into hash table at index %d.\n", key, index);
}

// Search element in chaining-based hash table
int search(HashTableChaining* hashTable, int key) {
    int index = hashFunction(key);
    Node* temp = hashTable->table[index];
    while (temp != NULL) {
        if (temp->data == key)
            return 1; // Found
        temp = temp->next;
    }
    return 0; // Not found
}

// Display chaining-based hash table
void display(HashTableChaining* hashTable) {
    printf("Hash Table (Chaining Method):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d:", i);
        Node* temp = hashTable->table[i];
        while (temp != NULL) {
            printf(" %d ->", temp->data);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

// Menu function to interact with chaining-based hash table
void menu() {
    HashTableChaining hashTable;
    initHashTable(&hashTable);
    int choice, key;

    while (1) {
        printf("\n--- Hash Table Menu (Chaining) ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(&hashTable, key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(&hashTable, key))
                    printf("Key %d found in the hash table.\n", key);
                else
                    printf("Key %d not found in the hash table.\n", key);
                break;

            case 3:
                display(&hashTable);
                break;

            case 4:
                printf("Exiting...\n");
                return;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Main function
int main() {
    menu();
    return 0;
}
