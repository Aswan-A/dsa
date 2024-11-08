#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100  


typedef struct Graph {
    int numNodes;
    int adjMatrix[MAX_NODES][MAX_NODES];
} Graph;


Graph* createGraph(int numNodes) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numNodes = numNodes;
    for (int i = 0; i < numNodes; i++) {
        for (int j = 0; j < numNodes; j++) {
            graph->adjMatrix[i][j] = 0; 
        }
    }
    return graph;
}


void addEdge(Graph* graph, int src, int dest) {
    if (src >= graph->numNodes || dest >= graph->numNodes) {
        printf("Error: Node out of bounds.\n");
        return;
    }
    graph->adjMatrix[src][dest] = 1; 
    
     graph->adjMatrix[dest][src] = 1;
}


int countSimplePathsDFS(Graph* graph, int src, int dest, int visited[]) {
    
    if (src == dest) {
        return 1;
    }

    visited[src] = 1; 
    int pathCount = 0;

    
    for (int i = 0; i < graph->numNodes; i++) {
        if (graph->adjMatrix[src][i] == 1 && visited[i] == 0) {
            pathCount += countSimplePathsDFS(graph, i, dest, visited);
        }
    }

    visited[src] = 0; 
    return pathCount;
}


int countSimplePaths(Graph* graph, int src, int dest) {
    int visited[MAX_NODES] = { 0 };
    return countSimplePathsDFS(graph, src, dest, visited);
}


void displayAdjMatrix(Graph* graph) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < graph->numNodes; i++) {
        for (int j = 0; j < graph->numNodes; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}


void menu(Graph* graph) {
    int choice, src, dest;

    while (1) {
        printf("\n--- Graph Menu ---\n");
        printf("1. Add Edge\n");
        printf("2. Count Simple Paths\n");
        printf("3. Display Adjacency Matrix\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter source node: ");
                scanf("%d", &src);
                printf("Enter destination node: ");
                scanf("%d", &dest);
                addEdge(graph, src, dest);
                printf("Edge added between %d and %d\n", src, dest);
                break;

            case 2:
                printf("Enter source node: ");
                scanf("%d", &src);
                printf("Enter destination node: ");
                scanf("%d", &dest);
                if (src >= graph->numNodes || dest >= graph->numNodes) {
                    printf("Error: Node out of bounds.\n");
                } else {
                    int pathCount = countSimplePaths(graph, src, dest);
                    printf("Number of simple paths from %d to %d: %d\n", src, dest, pathCount);
                }
                break;

            case 3:
                displayAdjMatrix(graph);
                break;

            case 4:
                printf("Exiting...\n");
                free(graph);
                return;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}


int main() {
    int numNodes;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &numNodes);

    
    if (numNodes > MAX_NODES || numNodes < 1) {
        printf("Error: Number of nodes should be between 1 and %d.\n", MAX_NODES);
        return 1;
    }

    
    Graph* graph = createGraph(numNodes);

    
    menu(graph);

    return 0;
}
