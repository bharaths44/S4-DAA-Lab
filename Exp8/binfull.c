#include <stdio.h>

// Function to implement First Fit algorithm for bin packing
int firstFit(int weights[], int n, int capacity) {
    int bins = 0; 
    int bin_capacity = capacity;
    
    for (int i = 0; i < n; i++) {
        if (weights[i] <= bin_capacity) {
            bin_capacity -= weights[i];
        } else {
            bins++;
            bin_capacity = capacity - weights[i];
        }
    }
    return bins;
}

// Function to implement Next Fit algorithm for bin packing
int nextFit(int weights[], int n, int capacity) {
    int bins = 1; // Start with one bin
    int bin_capacity = capacity;
    
    for (int i = 0; i < n; i++) {
        if (weights[i] <= bin_capacity) {
            bin_capacity -= weights[i];
        } else {
            bins++;
            bin_capacity = capacity - weights[i];
        }
    }
    return bins;
}

// Function to implement Best Fit algorithm for bin packing
int bestFit(int weights[], int n, int capacity) {
    int bins = 0;
    int bin_remaining_capacity[n];
    
    for (int i = 0; i < n; i++) {
        int j;
        int min_remaining_capacity = capacity + 1;
        int best_bin = -1;
        
        for (j = 0; j < bins; j++) {
            if (bin_remaining_capacity[j] >= weights[i] && bin_remaining_capacity[j] - weights[i] < min_remaining_capacity) {
                best_bin = j;
                min_remaining_capacity = bin_remaining_capacity[j] - weights[i];
            }
        }
        
        if (best_bin == -1) {
            bin_remaining_capacity[bins] = capacity - weights[i];
            bins++;
        } else {
            bin_remaining_capacity[best_bin] -= weights[i];
        }
    }
    return bins;
}

int main() {
    int weights[] = {5, 7, 5, 2, 4, 2, 5, 1, 6};
    int n = sizeof(weights) / sizeof(weights[0]);
    int bin_capacity = 10;

    int bins_first_fit = firstFit(weights, n, bin_capacity);
    int bins_next_fit = nextFit(weights, n, bin_capacity);
    int bins_best_fit = bestFit(weights, n, bin_capacity);

    printf("Number of bins required (Next Fit): %d\n", bins_next_fit);
    printf("Number of bins required (First Fit): %d\n", bins_first_fit);
    printf("Number of bins required (Best Fit): %d\n", bins_best_fit);

    return 0;
}

 
//TEST CASES
// {5, 7, 5, 2, 4, 2, 5, 1, 6}; 6 5 5
// {2, 5, 4, 7, 1, 3, 8}; 5 4 4
// {4, 1, 8, 1, 4, 2}; 3 2 3
// {2, 3, 4, 5, 1, 6, 7, 8, 9}; 6 6 6
