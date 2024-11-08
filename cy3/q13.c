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


void dfs(Graph *graph, int node, bool visited[MAX_NODES]) {
    visited[node] = true;
    printf("%d ", node);


    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->adj[node][i] == 1 && !visited[i]) {
            dfs(graph, i, visited);
        }
    }
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
        printf("1. Perform DFS\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter starting node for DFS: ");
                scanf("%d", &startNode);
                {
                    bool visited[MAX_NODES] = { false };
                    printf("DFS starting from node %d: ", startNode);
                    dfs(&graph, startNode, visited);
                    printf("\n");
                }
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

