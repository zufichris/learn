#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

typedef struct {
    int length;
    Node* head;
    Node* tail;
} List;

List* newList() {
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        printf("Error creating new list\n");
        return NULL;
    }

    list->length = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void push(List* list, int data) {
    if (list == NULL) return;

    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Error allocating memory for new node\n");
        return;
    }

    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;

    if (list->length == 0) { // First node
        list->head = temp;
        list->tail = temp;
    } else { // Add to the front
        temp->next = list->head;
        list->head->prev = temp;
        list->head = temp;
    }

    list->length++;
    printf("Pushed %d\n", data);
}

void pop(List* list, int pos) {
    if (list == NULL || list->length == 0 || pos < 0 || pos >= list->length) {
        printf("Invalid Position %d\n", pos);
        return;
    }

    Node* temp;
    if (pos == 0) { // Remove head
        temp = list->head;
        list->head = temp->next;
        if (list->head) {
            list->head->prev = NULL;
        } else { // List is now empty
            list->tail = NULL;
        }
    } else if (pos == list->length - 1) { // Remove tail
        temp = list->tail;
        list->tail = temp->prev;
        if (list->tail) {
            list->tail->next = NULL;
        } else { // List is now empty
            list->head = NULL;
        }
    } else { // Remove from the middle
        temp = list->head;
        for (int i = 0; i < pos; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }

    printf("Removed %d at [%d]\n", temp->data, pos);
    free(temp);
    list->length--;
}

void print(List* list) {
    if (list == NULL || list->length == 0) {
        printf("\nList is Empty!\n");
        return;
    }

    Node* temp = list->head;
    while (temp) {
        printf("[%d] <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\nLength = %d\n", list->length);
}

#endif
