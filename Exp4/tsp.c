#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 10

int graph[MAX_CITIES][MAX_CITIES]; // 2D array to represent the distance between cities
int numCities; // Number of cities

int minDistance = INT_MAX; // Variable to store the minimum distance found
int optimalPath[MAX_CITIES]; // Array to store the optimal path

// Function to calculate the total distance of a given permutation of cities
int calculateDistance(int path[]) {
    int distance = 0;
    for (int i = 0; i < numCities - 1; i++) {
        distance += graph[path[i]][path[i + 1]];
    }
    distance += graph[path[numCities - 1]][path[0]]; // Return to the starting city
    return distance;
}

// Function to find the optimal path using brute-force approach
void tspBruteForce(int path[], int position) {
    if (position == numCities) {
        int distance = calculateDistance(path);
        if (distance < minDistance) {
            minDistance = distance;
            for (int i = 0; i < numCities; i++) 
                optimalPath[i] = path[i];
        }
        return;
    }

    for (int i = position; i < numCities; i++) {
        // Swap elements to generate different permutations
        int temp = path[position];
        path[position] = path[i];
        path[i] = temp;

        tspBruteForce(path, position + 1);

        // Restore the original order to explore other permutations
        temp = path[position];
        path[position] = path[i];
        path[i] = temp;
    }
}

int main() {
    printf("Enter the number of cities (maximum 10): ");
    scanf("%d", &numCities);

    // Input the distance matrix
    printf("Enter the distance matrix (one row at a time):\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int path[MAX_CITIES];
    for (int i = 0; i < numCities; i++) {
        path[i] = i; // Initialize the path with the order of cities
    }

    tspBruteForce(path, 0);

    // Display the optimal path and minimum distance
    printf("Optimal Path: ");
    for (int i = 0; i < numCities; i++) {
        printf("%d ", optimalPath[i]);
    }
    printf("\nMinimum Distance: %d\n", minDistance);

    return 0;
}
