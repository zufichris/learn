#include "header.h"
#include <assert.h>

void testList() {
    // Create a new list
    CircularList* list = newCircularList();
    assert(list != NULL);
    assert(list->length == 0);
    assert(list->head == NULL);
    assert(list->tail == NULL);

    // Test pushing elements
    push(list, 10);
    assert(list->length == 1);
    assert(list->head->data == 10);
    assert(list->tail->data == 10);
    assert(list->head->next == list->head); // Circular link

    push(list, 20);
    assert(list->length == 2);
    assert(list->head->data == 10);
    assert(list->tail->data == 20);
    assert(list->tail->next == list->head); // Circular link maintained

    push(list, 30);
    assert(list->length == 3);
    assert(list->head->data == 10);
    assert(list->head->next->data == 20);
    assert(list->tail->data == 30);
    assert(list->tail->next == list->head); // Circular link maintained

    // Test popping elements
    pop(list, 0); // Remove head
    assert(list->length == 2);
    assert(list->head->data == 20);
    assert(list->tail->next == list->head); // Circular link maintained

    pop(list, 1); // Remove tail
    assert(list->length == 1);
    assert(list->head->data == 20);
    assert(list->tail->data == 20);
    assert(list->head->next == list->head); // Only one element left

    pop(list, 0); // Remove last element
    assert(list->length == 0);
    assert(list->head == NULL);
    assert(list->tail == NULL);

    // Test edge cases
    pop(list, 0); // Invalid pop
    assert(list->length == 0);
    assert(list->head == NULL);
    assert(list->tail == NULL);

    // Free the list
    freeCircularList(list);

    printf("All circular linked list tests passed!\n");
}
int main(){
    testList();void testList() {
    printf("Starting linked list tests...\n");

    // Create a new list
    List* list = newList();
    assert(list != NULL);
    assert(list->length == -1); // Starts at -1 due to implementation
    assert(list->head == NULL);

    // Test pushing elements
    push(list, 10);
    assert(list->length == 0);
    assert(list->head->data == 10);

    push(list, 20);
    assert(list->length == 1);
    assert(list->head->data == 20);

    push(list, 30);
    assert(list->length == 2);
    assert(list->head->data == 30);

    // Print the list
    printf("Current list after pushes: ");
    print(list); // Expected: [30]->[20]->[10]->Length=3

    // Test popping elements
    pop(list, 1); // Remove element at position 1 (20)
    assert(list->length == 1);
    assert(list->head->data == 30);

    pop(list, 0); // Remove the head (30)
    assert(list->length == 0);
    assert(list->head->data == 10);

    pop(list, 0); // Remove the last element (10)
    assert(list->length == -1);
    assert(list->head == NULL);

    // Attempt to pop from an empty list
    pop(list, 0); // Invalid operation
    pop(list, 1); // Invalid operation

    // Test reusing the list
    push(list, 40);
    push(list, 50);
    push(list, 60);
    assert(list->length == 2);
    assert(list->head->data == 60);

    // Print the list again
    printf("Reused list: ");
    print(list); // Expected: [60]->[50]->[40]->Length=3

    // Clean up the list
    while (list->length >= 0) {
        pop(list, 0);
    }
    assert(list->length == -1);
    assert(list->head == NULL);

    printf("All linked list tests passed!\n");
}
    return 0;
}



