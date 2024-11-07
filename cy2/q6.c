#include <stdio.h>
#include <stdlib.h>

// Node structure definition
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = data;
    newNode->next = newNode; // Initialize next to itself (circular)
    return newNode;
}

// Function to insert a node at the beginning of the list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // New node is the only node
    }

    struct Node* temp = head;
    while (temp->next != head) { // Find the last node
        temp = temp->next;
    }
    temp->next = newNode; // Last node points to new node
    newNode->next = head; // New node points to head
    return newNode; // New node is now the head
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode; // New node is the only node
    }

    struct Node* temp = head;
    while (temp->next != head) { // Find the last node
        temp = temp->next;
    }
    temp->next = newNode; // Last node points to new node
    newNode->next = head; // New node points to head
    return head;
}

// Function to insert a node at a specific position
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) {
        printf("Position must be greater than 0\n");
        return head; // Invalid position
    }

    struct Node* newNode = createNode(data);

    if (position == 1) {
        return insertAtBeginning(head, data); // Reuse insertAtBeginning
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp->next != head; i++) {
        temp = temp->next;
    }

    // If we reached the end of the list without finding the position
    if (temp->next == head) {
        printf("Position exceeds list length, inserting at end.\n");
        return insertAtEnd(head, data); // Insert at end if position is out of bounds
    }

    newNode->next = temp->next; // Link new node to the next node
    temp->next = newNode; // Previous node points to new node
    return head;
}

// Function to delete a node at the beginning
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (head->next == head) { // Only one node
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* last = head;
    while (last->next != head) { // Find the last node
        last = last->next;
    }

    head = head->next; // Move head to the next node
    last->next = head; // Last node points to new head
    free(temp); // Free the old head
    return head;
}

// Function to delete a node at the end
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    if (head->next == head) { // Only one node
        free(head);
        return NULL;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->next != head) { // Find the last node
        prev = temp;
        temp = temp->next;
    }

    prev->next = head; // Second last node points to head
    free(temp); // Free the last node
    return head;
}

// Function to delete a node at a specific position
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (position < 1) {
        printf("Position must be greater than 0\n");
        return head; // Invalid position
    }
    if (position == 1) {
        return deleteAtBeginning(head); // Reuse deleteAtBeginning
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    for (int i = 1; i < position && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == head) {
        printf("Position out of bounds\n");
        return head;
    }

    prev->next = temp->next; // Bypass the node to delete
    free(temp); // Free the deleted node
    return head;
}

// Function to print the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head: %d)\n", head->data);
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at the end\n");
    printf("3. Insert at a specific position\n");
    printf("4. Delete from the beginning\n");
    printf("5. Delete from the end\n");
    printf("6. Delete from a specific position\n");
    printf("7. Display the list\n");
    printf("8. Exit\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 7:
                printf("The current list is: ");
                printList(head);
                break;
            case 8:
                // Free all nodes before exit
                if (head != NULL) {
                    struct Node* temp = head;
                    struct Node* next;
                    do {
                        next = temp->next;
                        free(temp);
                        temp = next;
                    } while (temp != head);
                }
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
