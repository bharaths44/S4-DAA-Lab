#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;
struct node* tail = NULL;
int size = 0;

void insert(int value) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}

void remove_element(int i) {
    if (i < 0 || i >= size) {
        printf("Invalid index\n");
        return;
    }
    if (i == 0) {
        struct node* temp = head;
        head = head->next;
        free(temp);
    } else {
        struct node* current = head;
        for (int j = 0; j < i-1; j++) {
            current = current->next;
        }
        struct node* temp = current->next;
        current->next = temp->next;
        free(temp);
        if (i == size - 1) {
            tail = current;
        }
    }
    size--;
}

int next_element(int i) {
    struct node* current = head;
    while (current != NULL && current->data <= current->next->data) {
        current = current->next;
    }
    if (current == NULL) {
        return -1;
    }
    return current->next->data;
}

int main() {
    int n, value;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insert(value);
    }

    printf("Linked list elements: ");
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    int index;
    printf("Enter the index to remove: ");
    scanf("%d", &index);
    remove_element(index);
    printf("Linked list after removing element at index %d: ", index);
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    int next_largest = next_element(1);
    if (next_largest == -1) {
        printf("No next largest element\n");
    } else {
        printf("Next largest element after index 1: %d\n", next_largest);
    }

    return 0;
}
