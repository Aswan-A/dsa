#include <stdio.h>
#include <stdlib.h>

// Define the structure for the linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Function to count the number of nodes in the linked list
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to reverse the list in groups of size k
struct Node* reverseInGroups(struct Node* head, int k) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    // Count the number of nodes in the list
    int totalNodes = countNodes(head);
    if (k > totalNodes) {
        printf("The list has fewer nodes than %d. No reversal performed.\n", k);
        return head; // Return the list as is without reversing
    }

    struct Node* current = head;
    struct Node* prev = NULL;
    struct Node* next = NULL;
    int count = 0;

    // Reverse the first k nodes of the list
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // Now head points to the kth node, connect the rest of the list
    if (next != NULL) {
        head->next = next;
    }

    return prev; // prev is the new head of the reversed group
}

// Function to print the list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display the menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Insert a node at the end\n");
    printf("2. Reverse linked list in groups\n");
    printf("3. Display the list\n");
    printf("4. Exit\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, k;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;

            case 2:
                if (head == NULL) {
                    printf("List is empty. Cannot reverse.\n");
                } else {
                    printf("Enter the group size to reverse: ");
                    scanf("%d", &k);
                    head = reverseInGroups(head, k);
                    printf("Linked list reversed in groups of %d.\n", k);
                }
                break;

            case 3:
                printf("The current list is: \n");
                printList(head);
                break;

            case 4:
                printf("Exiting...\n");
                // Free the list before exiting
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
