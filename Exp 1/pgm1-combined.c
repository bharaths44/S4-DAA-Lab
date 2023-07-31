#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *pos = NULL;

void push(int *stack, int *top, int element) {
	stack[++(*top)] = element;
}

int pop(int *stack, int *top) {
	return stack[(*top)--];
}

int next_largest_stack(int *stack, int size, int target) {
	int i;
	int largest = -1;

	for (i = 0; i < size; i++) {
		if (stack[i] > target) {
			if (largest == -1 || stack[i] < largest) {
				largest = stack[i];
			}
		}
	}

	return largest;
}

int next_largest_linked_list(int target) {
	struct node *current = head;
	int largest = -1;

	while (current != NULL) {
		if (current->data > target) {
			if (largest == -1 || current->data < largest) {
				largest = current->data;
			}
		}

		current = current->next;
	}

	return largest;
}

void delete_element_stack(int *stack, int *top, int position) {
	int i;
	for (i = position - 1; i < *top; i++) {
		stack[i] = stack[i + 1];
	}

	(*top)--;
}

void delete_element_linked_list(int position) {
	int i;
	pos = head;

	if (position == 1) {
		head = head->next;
		free(pos);
		pos = head;
	} else {
		for (i = 1; i < position - 1; i++) {
			pos = pos->next;
		}

		struct node *temp = pos->next;
		pos->next = pos->next->next;
		free(temp);
	}
}

int main() {
	int n, i, p, j;
	int *stack;
	int top = -1;
	double total_t;
	clock_t t;

	printf("Enter number of elements: ");
	scanf("%d", &n);

	stack = (int*)malloc(sizeof(int) * n);

	// Populate stack and linked list with random elements
	for (i = 0; i < n; i++) {
		int random_num = rand() % 100;
		push(stack, &top, random_num);

		if (head == NULL) {
			head = (struct node*)malloc(sizeof(struct node));
			head->data = random_num;
			pos = head;
			tail = head;
		} else {
			tail->next = (struct node*)malloc(sizeof(struct node));
			tail = tail->next;
			tail->data = random_num;
			tail->next = NULL;
		}
	}

	// Deletion in stack
	printf("\nEnter which position element to remove: ");
	scanf("%d", &p);
	t = clock();
	int deleted_element_stack = stack[p - 1];
	delete_element_stack(stack, &top, p);
	t = clock() - t;
	total_t = (((double)t) / CLOCKS_PER_SEC);
	printf("Deleted element in stack: %d\n", deleted_element_stack);
	printf("Time taken to delete (stack): %f\n", total_t);

	// Deletion in linked list
	t = clock();
	int deleted_element_linked_list;
	if (p == 1) {
		deleted_element_linked_list = head->data;
		head = head->next;
		pos = head;
	} else {
		pos = head;
		for (i = 1; i < p - 1; i++) {
			pos = pos->next;
		}

		deleted_element_linked_list = pos->next->data;
		struct node *temp = pos->next;
		pos->next = pos->next->next;
		free(temp);
	}
	t = clock() - t;
	total_t = (((double)t) / CLOCKS_PER_SEC);
	printf("Deleted element in linked list: %d\n", deleted_element_linked_list);
	printf("Time taken to delete (linked list): %f\n", total_t);

	// Next largest using stack
	t = clock();
	int next_largest_stack_value = next_largest_stack(stack, n, deleted_element_stack);
	t = clock() - t;
	total_t = (((double)t) / CLOCKS_PER_SEC);
	printf("\nThe next largest element in stack is: %d\n", next_largest_stack_value);
	printf("Time taken to find next largest (stack): %f\n", total_t);

	// Next largest using linked list
	t = clock();
	int next_largest_linked_list_value = next_largest_linked_list(deleted_element_linked_list);
	t = clock() - t;
	total_t = (((double)t) / CLOCKS_PER_SEC);
	printf("The next largest element in linked list is: %d\n", next_largest_linked_list_value);
	printf("Time taken to find next largest (linked list): %f\n", total_t);

	free(stack);

	return 0;
}
