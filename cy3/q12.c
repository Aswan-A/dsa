#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Array to track visited nodes
int queue[MAX], front = -1, rear = -1;
int n;              // Number of nodes in the graph

// Function to add an element to the queue
void enqueue(int v) {
    if (rear == MAX - 1) return;  // Queue overflow
    if (front == -1) front = 0;
    queue[++rear] = v;
}

// Function to remove an element from the queue
int dequeue() {
    if (front == -1 || front > rear) return -1;  // Queue underflow
    return queue[front++];
}

// BFS function
void bfs(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from node %d: ", start);

    while (front <= rear) {
        int u = dequeue();
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                enqueue(v);
                visited[v] = 1;
            }
        }
    }
    printf("\n");
}

// Function to create the adjacency matrix
void createGraph() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}

// Menu-driven program
int main() {
    int start, choice;

    while (1) {
        printf("\nGraph Traversal using BFS\n");
        printf("1. Create Graph\n");
        printf("2. Perform BFS\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                break;
            case 2:
                printf("Enter the starting node for BFS: ");
                scanf("%d", &start);
                if (start >= 0 && start < n) {
                    bfs(start);
                } else {
                    printf("Invalid starting node!\n");
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
