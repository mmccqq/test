#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node_t;

node_t* create_list(int* arr, int size) {
    if (size == 0) return NULL;

    node_t* head = (node_t*)malloc(sizeof(node_t));
    head->data = arr[0];
    head->next = NULL;

    node_t* iterator = head;
    for (int i = 1; i < size; i++) {
        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        new_node->data = arr[i];
        new_node->next = NULL;
        iterator->next = new_node;
        iterator = new_node;
    }

    return head;
}

void free_list(node_t* iterator) {
    while (iterator != NULL) {
				node_t* temp = iterator;
				iterator = iterator->next;
				free(temp);
		}
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    node_t* head = create_list(arr, 5);
    node_t* iterator = head;
    free_list(head);
    return 0;
}