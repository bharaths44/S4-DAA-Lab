#include <stdio.h>

void DFS(int n, int adjacencyMatrix[][n], int visited[], int vertex) {
    visited[vertex] = 1;  
    
    printf("%d ", vertex+1);  
    
    for (int i = 0; i < n; i++) {
        if (adjacencyMatrix[vertex][i] && !visited[i]) {
            DFS(n, adjacencyMatrix, visited, i);  
        }
    }
}

void findConnectedComponents(int n, int adjacencyMatrix[][n]) {
    int visited[n];  
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0; 
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Connected component %d: ", i+1);
           
            DFS(n, adjacencyMatrix, visited, i);  
            printf("\n");
        }
    }
}

int main() {
    int n; 
    
    printf("Enter the size of the adjacency matrix: ");
    scanf("%d", &n);
    
    int adjacencyMatrix[n][n]; 
    printf("Enter the elements of the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }
    findConnectedComponents(n, adjacencyMatrix);
    
    return 0;
}
