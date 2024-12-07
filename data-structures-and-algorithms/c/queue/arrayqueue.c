// A queue is a linear data structure that stores items in a First-In/First-Out (FIFO) 
// or Last-In/Last-Out (LILO) manner. 
// In queue, a new element is added at the top(head) and an element is removed from the bottom (tail). 
// The insert and delete operations are often called push and pop.


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAX 10

typedef struct {
    int head;
    int tail;
    int valueAt[MAX];
} Queue;

Queue *newQueue();
int isEmpty(Queue *queue);
int isFull(Queue *queue);
void pop(Queue *queue);
void push(Queue *queue, int value);
void print(Queue *queue);
void testQueue();

int main() {
    testQueue();
    return 0;
}

Queue *newQueue() {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Error Initializing Queue\n");
        exit(1);
    }
    queue->head = -1;
    queue->tail = -1;
    printf("Queue Initialized...\n");
    return queue;
}

int isEmpty(Queue *queue) {
    return (queue->head == -1);
}

int isFull(Queue *queue) {
    return (queue->tail == MAX - 1);
}

void pop(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Cannot Pop(): Queue is empty\n");
    } else {
        printf("Popped(%d)\n", queue->valueAt[queue->head]);
        if (queue->head == queue->tail) {
            queue->head = -1; // Reset queue when last element is removed
            queue->tail = -1;
        } else {
            queue->head++;
        }
    }
}

void push(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Cannot Push(%d): Queue overflow\n", value);
    } else {
        if (isEmpty(queue)) {
            queue->head = 0; // Initialize queue for the first element
        }
        queue->tail++;
        queue->valueAt[queue->tail] = value;
        printf("Pushed(%d)\n", value);
    }
}

void print(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is Empty\n");
    } else {
        printf("Queue contents: ");
        for (int i = queue->head; i <= queue->tail; i++) {
            printf("[%d]", queue->valueAt[i]);
            if (i < queue->tail) {
                printf(" -> ");
            }
        }
        printf("\n");
    }
}


void testQueue() {
    printf("\nRunning Queue Tests...\n");

    Queue *queue = newQueue();

    // Test initialization
    assert(queue != NULL);
    assert(isEmpty(queue));

    // Test push
    push(queue, 10);
    assert(!isEmpty(queue));
    assert(queue->valueAt[queue->head] == 10);
    assert(queue->head == 0 && queue->tail == 0);

    // Test multiple pushes
    push(queue, 20);
    push(queue, 30);
    assert(queue->tail == 2);
    assert(queue->valueAt[queue->tail] == 30);

    // Test pop
    pop(queue);
    assert(queue->valueAt[queue->head] == 20);

    // Test pop until empty
    pop(queue);
    pop(queue);
    assert(isEmpty(queue));

    // Test overflow
    for (int i = 0; i < MAX; i++) {
        push(queue, i);
    }
    assert(isFull(queue));
    push(queue, 99); // Overflow case
    assert(queue->tail == MAX - 1); // No new element added

    // Test cleanup
    free(queue);
    printf("All Queue Tests Passed!\n");
}
