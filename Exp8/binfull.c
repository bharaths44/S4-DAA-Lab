#include <stdio.h>
#include <math.h>

int binPackingNextFit(int weights[], int capacity, int n) {
    int bins = 0;
    int remainingCapacity = capacity;
    for (int i = 0; i < n; i++) 
    {
        if (weights[i] > remainingCapacity) 
        {
            remainingCapacity = capacity - weights[i];
            bins++;
        } 
        else 
        {
            remainingCapacity -= weights[i];
        }
    }
    return bins + 1; // Add one more bin for any remaining items
}

int binPackingFirstFit(int weights[], int capacity, int n) {
    int bins = 0;
    int remainingCapacity[100] = {0};
    for (int i = 0; i < n; i++) 
    {
        int j=0;
        for (j = 0; j < bins; j++) 
        {
            if (weights[i] <= remainingCapacity[j]) 
            {
                remainingCapacity[j] -= weights[i];
                break;
            }
        }
        if (j == bins) 
        {
            remainingCapacity[bins] = capacity - weights[i];
            bins++;
        }
    }
    return bins;
}

int binPackingBestFit(int weights[], int capacity, int n) {
    int bins = 0;
    int remainingCapacity[100] = {0};
    for (int i = 0; i < n; i++) 
    {
        int minimum = capacity + 1;
        int index = 0;
        for (int j = 0; j < bins; j++) 
        {
            if (weights[i] <= remainingCapacity[j] && remainingCapacity[j] - weights[i] < minimum) 
            {
                index = j;
                minimum = remainingCapacity[j] - weights[i];
            }
        }
        if (minimum == capacity + 1) 
        {
            remainingCapacity[bins] = capacity - weights[i];
            bins++;
        } 
        else 
        {
            remainingCapacity[index] -= weights[i];
        }
    }
    return bins;
}  


int main() {
    int n, capacity;
    printf("BIN PACKING PROBLEM USING NEXT, FIRST AND BEST FIT\n\n");
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int weights[100];
    float totalWeight = 0;
    for (int i = 0; i < n; i++) {
        printf("Enter the item %d: ", i + 1);
        scanf("%d", &weights[i]);
        totalWeight += weights[i];
    }
    printf("\nEnter the maximum capacity of bin: ");
    scanf("%d", &capacity);
    int lowerBound = ceil(totalWeight / (float)capacity);
    printf("\nLower Bound(Min number of bins required): %d\n", lowerBound);
    printf("The total number of bins required using:\n");
    printf("Next Fit: %d\n", binPackingNextFit(weights, capacity, n));
    printf("First Fit: %d\n", binPackingFirstFit(weights, capacity, n));
    printf("Best Fit: %d\n", binPackingBestFit(weights, capacity, n));
    return 0;
}
 
//TEST CASES
// {5, 7, 5, 2, 4, 2, 5, 1, 6}; 6 5 5
// {2, 5, 4, 7, 1, 3, 8}; 5 4 4
// {4, 1, 8, 1, 4, 2}; 3 2 3
// {2, 3, 4, 5, 1, 6, 7, 8, 9}; 6 6 6
