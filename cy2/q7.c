#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int roll;
    char name[50];  // Increased size for names
    int total;
    struct Node* next;
};

struct Node* createNode(int roll, char a[], int t) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->roll = roll;
    strncpy(newNode->name, a, sizeof(newNode->name) - 1);
    newNode->name[sizeof(newNode->name) - 1] = '\0';  // Ensure null-termination
    newNode->total = t;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int roll, char a[], int t) {
    struct Node* newNode = createNode(roll, a, t);
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

struct Node* deleteAtPosition(struct Node* head, int roll) {
    int position = 1;  // Initialize position counter
    struct Node* temp = head;

    // Check if the list is empty
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }

    // Find the position of the node with the specified roll number
    while (temp != NULL) {
        if (roll == temp->roll) {
            break;
        }
        position++;
        temp = temp->next;
    }

    // If roll number not found
    if (temp == NULL) {
        printf("Not found\n");
        return head;
    }

    // Handle deletion at the head
    if (position == 1) {
        struct Node* toDelete = head;
        head = head->next;
        free(toDelete);
        return head;
    }

    // Traverse to the node just before the one to delete
    temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

  

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

void search(struct Node* head, int n) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (n == temp->roll) {
            printf("%d \t %s\t %d \n", temp->roll, temp->name, temp->total);
            return;
        }
        temp = temp->next;
    }
    printf("\nNot found\n");
}

void printList(struct Node* head) {
	if (head==NULL){
	printf("\nEmpty\n");}
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d \t %s\t %d \n", temp->roll, temp->name, temp->total);
        temp = temp->next;
    }
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Create\n");
    printf("2. Insert at the end\n");
    printf("3. Delete from a specific roll\n");
    printf("4. Display the list\n");
    printf("5. Search\n");
    printf("6. Exit\n");
}

int main() {
    struct Node* head = NULL;
    int choice, roll, total;
    char name[50];  // Increased size for names

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int n;
                printf("Number of students: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("\nEnter the roll to insert: ");
                    scanf("%d", &roll);
                    printf("Enter the name to insert: ");
                    scanf("%s", name);
                    printf("Enter the total to insert: ");
                    scanf("%d", &total);
                    head = insertAtEnd(head, roll, name, total);
                }
                break;
            }
            case 2:
                printf("Enter the roll to insert: ");
                scanf("%d", &roll);
                printf("Enter the name to insert: ");
                scanf("%s", name);
                printf("Enter the total to insert: ");
                scanf("%d", &total);
                head = insertAtEnd(head, roll, name, total);
                break;

         

            case 3:
                printf("Enter the roll to delete: ");
                scanf("%d", &roll);
                head = deleteAtPosition(head, roll);
                break;

            case 4:
                printf("The current list is: \n");
                printList(head);
                break;

            case 5: {
                int s;
                printf("Enter roll number to search: ");
                scanf("%d", &s);
                search(head, s);
                break;
            }
            case 6:
                while (head != NULL) {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
