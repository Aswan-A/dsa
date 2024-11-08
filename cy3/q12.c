#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100


typedef struct Graph {
    int adj[MAX_NODES][MAX_NODES];  
    int numNodes;                   
} Graph;


void initGraph(Graph *graph, int nodes) {
    graph->numNodes = nodes;
    

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            graph->adj[i][j] = 0;
        }
    }
}


void addEdge(Graph *graph, int u, int v) {
    graph->adj[u][v] = 1;
    graph->adj[v][u] = 1;  
}


void bfs(Graph *graph, int startNode) {
    bool visited[MAX_NODES] = { false }; 
    int queue[MAX_NODES], front = 0, rear = 0;


    visited[startNode] = true;
    queue[rear++] = startNode;

    printf("BFS starting from node %d: ", startNode);

    while (front != rear) {
        int current = queue[front++];
        
        printf("%d ", current);


        for (int i = 0; i < graph->numNodes; i++) {
            if (graph->adj[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    Graph graph;
    int nodes, edges, u, v, choice, startNode;

    printf("Enter number of nodes: ");
    scanf("%d", &nodes);

    initGraph(&graph, nodes);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u, v): ");
        scanf("%d %d", &u, &v);
        addEdge(&graph, u, v);
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Perform BFS\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter starting node for BFS: ");
                scanf("%d", &startNode);
                bfs(&graph, startNode);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

