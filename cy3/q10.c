#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100 // Maximum number of users that can be in the network

// Node structure to represent each friend in the adjacency list
typedef struct Node {
    int userId;
    struct Node* next;
} Node;

// Graph structure to represent the social network
typedef struct Graph {
    int numUsers;
    Node* adjList[MAX_USERS]; // Array of pointers for each user's friends list
} Graph;

// Function to create a new user in the network (node in the graph)
Graph* createGraph(int numUsers) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numUsers = numUsers;
    for (int i = 0; i < numUsers; i++) {
        graph->adjList[i] = NULL; // Initialize each adjacency list to NULL
    }
    return graph;
}

// Function to create a new friend node
Node* createNode(int userId) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->userId = userId;
    newNode->next = NULL;
    return newNode;
}

// Function to add a friendship (edge) between two users
void addFriendship(Graph* graph, int user1, int user2) {
    if (user1 >= graph->numUsers || user2 >= graph->numUsers) {
        printf("Error: User ID out of bounds.\n");
        return;
    }

    // Add an edge from user1 to user2
    Node* newNode = createNode(user2);
    newNode->next = graph->adjList[user1];
    graph->adjList[user1] = newNode;

    // Since this is an undirected graph, add an edge from user2 to user1
    newNode = createNode(user1);
    newNode->next = graph->adjList[user2];
    graph->adjList[user2] = newNode;
}

// Function to display the social network as an adjacency list
void displayGraph(Graph* graph) {
    for (int i = 0; i < graph->numUsers; i++) {
        Node* temp = graph->adjList[i];
        printf("User %d: ", i);
        while (temp) {
            printf("-> %d ", temp->userId);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free memory used by the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numUsers; i++) {
        Node* temp = graph->adjList[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph);
}

// Menu function to interact with the graph
void menu(Graph* graph) {
    int choice, user1, user2;
    while (1) {
        printf("\n--- Social Network Menu ---\n");
        printf("1. Add Friendship\n");
        printf("2. Display Network\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter User ID 1: ");
                scanf("%d", &user1);
                printf("Enter User ID 2: ");
                scanf("%d", &user2);
                addFriendship(graph, user1, user2);
                printf("Friendship added between User %d and User %d\n", user1, user2);
                break;

            case 2:
                printf("\n--- Social Network ---\n");
                displayGraph(graph);
                break;

            case 3:
                printf("Exiting...\n");
                freeGraph(graph);
                return;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

// Main function
int main() {
    int numUsers;
    printf("Enter the number of users in the network: ");
    scanf("%d", &numUsers);

    // Validate number of users
    if (numUsers > MAX_USERS || numUsers < 1) {
        printf("Error: Number of users should be between 1 and %d.\n", MAX_USERS);
        return 1;
    }

    // Create the graph
    Graph* socialNetwork = createGraph(numUsers);

    // Show menu to interact with the social network
    menu(socialNetwork);

    return 0;
}
