#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10  // Maximum number of vertices in the graph

// Function prototypes
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[], int startVertex, int n);

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

    // Perform BFS from the first vertex (0-indexed)
    printf("Breadth First Search (BFS) traversal:\n");
    BFS(graph, visited, 0, n);  // Start BFS from vertex 0

    return 0;
}

// BFS function
void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int visited[], int startVertex, int n) {
    int queue[MAX_VERTICES], front = -1, rear = -1;
    int currentVertex;

    // Mark the starting vertex as visited and enqueue it
    visited[startVertex] = 1;
    queue[++rear] = startVertex;

    // Continue BFS until the queue is empty
    while(front != rear) {
        currentVertex = queue[++front];
        printf("%d ", currentVertex);

        // Visit all unvisited neighbors of the current vertex
        for(int i = 0; i < n; i++) {
            if(graph[currentVertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;  // Mark the neighbor as visited
                queue[++rear] = i;  // Enqueue the neighbor
            }
        }
    }
}
