#include <stdio.h>

#define MAX_SIZE 100

int array[MAX_SIZE];
int n = 0;

void remove_element(int i) {
    if (i < 0 || i >= n) {
        printf("Invalid index\n");
        return;
    }
    for (int j = i; j < n - 1; j++) {
        array[j] = array[j+1];
    }
    n--;
}

int next_element(int i) {
    int j = i + 1;
    while (j < n && array[j] <= array[i]) {
        j++;
    }
    if (j >= n) {
        return -1;
    }
    return array[j];
}

int main() {
    // example usage
    n = 5;
    array[0] = 5;
    array[1] = 3;
    array[2] = 8;
    array[3] = 1;
    array[4] = 4;

    remove_element(2); // remove element at index 2 (value 8)
    printf("After removing element at index 2: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int next_largest = next_element(1); // find next largest element after index 1 (value 4)
    printf("Next largest element after index 1: %d\n", next_largest);

    return 0;
}
