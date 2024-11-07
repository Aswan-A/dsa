#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10  // Size of the hash table

// Hash Table structure for linear probing
typedef struct HashTableLinearProbing {
    int table[TABLE_SIZE];
    int occupied[TABLE_SIZE];
} HashTableLinearProbing;

// Hash function to get the index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Initialize hash table for linear probing
void initHashTable(HashTableLinearProbing* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = -1;  // Indicates empty slot
        hashTable->occupied[i] = 0; // Mark as unoccupied
    }
}

// Insert element in linear probing-based hash table
void insert(HashTableLinearProbing* hashTable, int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable->occupied[index] && hashTable->table[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Hash table is full. Cannot insert %d.\n", key);
            return;
        }
    }
    hashTable->table[index] = key;
    hashTable->occupied[index] = 1;
    printf("Inserted %d into hash table at index %d.\n", key, index);
}

// Search element in linear probing-based hash table
int search(HashTableLinearProbing* hashTable, int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable->occupied[index]) {
        if (hashTable->table[index] == key)
            return 1; // Found
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) // Full cycle, element not found
            break;
    }
    return 0; // Not found
}

// Display linear probing-based hash table
void display(HashTableLinearProbing* hashTable) {
    printf("Hash Table (Linear Probing Method):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable->occupied[i]) {
            printf("Index %d: %d\n", i, hashTable->table[i]);
        } else {
            printf("Index %d: EMPTY\n", i);
        }
    }
}

// Menu function to interact with linear probing-based hash table
void menu() {
    HashTableLinearProbing hashTable;
    initHashTable(&hashTable);
    int choice, key;

    while (1) {
        printf("\n--- Hash Table Menu (Linear Probing) ---\n");
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
