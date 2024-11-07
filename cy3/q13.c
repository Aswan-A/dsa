#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Array to track visited nodes
int n;              // Number of nodes in the graph

// DFS function
void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
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

// Function to reset visited array
void resetVisited() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
}

// Menu-driven program
int main() {
    int start, choice;

    while (1) {
        printf("\nGraph Traversal using DFS\n");
        printf("1. Create Graph\n");
        printf("2. Perform DFS\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createGraph();
                break;
            case 2:
                printf("Enter the starting node for DFS: ");
                scanf("%d", &start);
                if (start >= 0 && start < n) {
                    resetVisited();
                    printf("DFS Traversal starting from node %d: ", start);
                    dfs(start);
                    printf("\n");
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
