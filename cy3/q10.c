#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 100 


typedef struct Node {
    int userId;
    struct Node* next;
} Node;


typedef struct Graph {
    int numUsers;
    Node* adjList[MAX_USERS]; 
} Graph;


Graph* createGraph(int numUsers) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numUsers = numUsers;
    for (int i = 0; i < numUsers; i++) {
        graph->adjList[i] = NULL; 
    }
    return graph;
}


Node* createNode(int userId) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->userId = userId;
    newNode->next = NULL;
    return newNode;
}


void addFriendship(Graph* graph, int user1, int user2) {
    if (user1 >= graph->numUsers || user2 >= graph->numUsers) {
        printf("Error: User ID out of bounds.\n");
        return;
    }

    
    Node* newNode = createNode(user2);
    newNode->next = graph->adjList[user1];
    graph->adjList[user1] = newNode;

    
    newNode = createNode(user1);
    newNode->next = graph->adjList[user2];
    graph->adjList[user2] = newNode;
}


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


void menu(Graph* graph) {
    int choice, user1, user2;
    while (1) {                                                 
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


int main() {
    int numUsers;
    printf("Enter the number of users in the network: ");
    scanf("%d", &numUsers);

   
    if (numUsers > MAX_USERS || numUsers < 1) {
        printf("Error: Number of users should be between 1 and %d.\n", MAX_USERS);
        return 1;
    }

   
    Graph* socialNetwork = createGraph(numUsers);

    
    menu(socialNetwork);

    return 0;
}
