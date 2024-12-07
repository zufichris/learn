#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    int length;
    Node* head;
    Node* tail;
} CircularList;

// Create a new circular linked list
CircularList* newCircularList() {
    CircularList* list = (CircularList*)malloc(sizeof(CircularList));
    if (list == NULL) {
        printf("Error creating new list\n");
        return NULL;
    }
    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Add an element to the circular linked list
void push(CircularList* list, int data) {
    if (list == NULL) return;

    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error allocating memory for new node\n");
        return;
    }

    newNode->data = data;
    if (list->length == 0) {
        // First node points to itself
        newNode->next = newNode;
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->length++;
    printf("Pushed %d\n", data);
}

// Remove an element from a specific position
void pop(CircularList* list, int pos) {
    if (list == NULL || list->length == 0 || pos < 0 || pos >= list->length) {
        printf("Invalid Position %d\n", pos);
        return;
    }

    Node* temp = list->head;
    if (pos == 0) {
        // Remove the head
        if (list->length == 1) {
            list->head = NULL;
            list->tail = NULL;
        } else {
            list->head = list->head->next;
            list->tail->next = list->head;
        }
        printf("Removed %d at [%d]\n", temp->data, pos);
        free(temp);
    } else {
        // Traverse to the node before the one to remove
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }
        Node* toRemove = temp->next;
        temp->next = toRemove->next;
        if (pos == list->length - 1) {
            // Update the tail if the last element is removed
            list->tail = temp;
        }
        printf("Removed %d at [%d]\n", toRemove->data, pos);
        free(toRemove);
    }

    list->length--;
}

// Print the circular linked list
void print(CircularList* list) {
    if (list == NULL || list->length == 0) {
        printf("\nList is Empty!\n");
        return;
    }

    Node* temp = list->head;
    for (int i = 0; i < list->length; i++) {
        printf("[%d]->", temp->data);
        temp = temp->next;
    }
    printf("[HEAD]\n");
    printf("Length = %d\n", list->length);
}

// Free the entire list
void freeCircularList(CircularList* list) {
    if (list == NULL) return;

    while (list->length > 0) {
        pop(list, 0);
    }
    free(list);
}

#endif
