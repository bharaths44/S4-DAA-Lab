#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix to represent the graph
bool visited[MAX_VERTICES] = {false}; // Array to keep track of visited vertices
int stack[MAX_VERTICES]; // Stack to store the topologically sorted vertices
int top = -1; // Top of the stack

void dfs(int v, int vertices) {

    printf("%d ", v+1);  

    visited[v] = true;
    
    // Perform DFS on all adjacent unvisited vertices
    for (int i = 0; i < vertices; i++) {
        if (graph[v][i] && !visited[i]) {
            dfs(i, vertices);
        }
    }
}

void topologicalSort(int vertices) {
    // Perform DFS on all unvisited vertices
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            printf("Connected component %d: ", i+1);
            dfs(i, vertices);
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    int vertices;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    printf("Enter the adjacency matrix (0 or 1):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    topologicalSort(vertices);

    return 0;
}
