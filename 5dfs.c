#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10  // Maximum number of vertices in the graph

// Function prototype
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[], int vertex, int n);

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES];
    int visited[MAX_VERTICES] = {0};  // Array to keep track of visited nodes
    int n, i, j;

    // Input the number of vertices
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Perform DFS from the first vertex (0-indexed)
    printf("Depth First Search (DFS) traversal:\n");
    DFS(graph, visited, 0, n);  // Start DFS from vertex 0

    return 0;
}

// DFS function
void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[], int vertex, int n) {
    // Mark the current node as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recur for all the vertices adjacent to this vertex
    for(int i = 0; i < n; i++) {
        if(graph[vertex][i] == 1 && visited[i] == 0) {
            DFS(graph, visited, i, n);
        }
    }
}
