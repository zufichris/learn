// A stack is a linear data structure that stores items in a Last-In/First-Out (LIFO) 
// or First-In/Last-Out (FILO) manner. 
// In stack, a new element is added at one end and an element is removed from that end only. 
// The insert and delete operations are often called push and pop.


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define MAX 10
typedef struct{
    int top;
    int  valueAt[10];
}Stack;

Stack *newStack();
int isEmpty(Stack*);
void pop(Stack*);
void push(Stack*,int);
void print(Stack*);
void testStack();

int main(){
testStack();
return 0;
 }


Stack *newStack(){
Stack *stack=(Stack*)malloc(sizeof(Stack));
if(stack==NULL){
    printf("Error Initializing stack\n");
}else{
stack->top=-1;
printf("Stack Initialized...\n");
}
return stack;
}

int isEmpty(Stack*stack){
    return stack->top==-1;
}

void pop(Stack*stack){
  if(isEmpty(stack)){
    printf("Cannot Pop(): Stack is empty\n");
  }else{
    stack->top--;
    printf("\n Popped(%d)\n",stack->top);
  }
}

void push(Stack*stack,int value){
  if(stack->top<MAX-1){
  stack->top++;
  stack->valueAt[stack->top]=value;
    printf("\n Pushed(%d)\n",value);
  }else{
    printf("Cannot Push(%d):Stack overflow\n",value);
  }  
}

void print(Stack*stack){
if(isEmpty(stack))
{
    printf("Stack is Empty\n");
}
else{
for(int i=0;i<=stack->top;i++)
printf("[%d]->\t",stack->valueAt[i]);
}
}


void testStack() {
    printf("Running Stack Tests...\n");

    // Test stack initialization
    Stack *stack = newStack();
    assert(stack != NULL); // Ensure stack is created
    assert(isEmpty(stack) == 1); // Stack should be empty initially

    // Test push operation
    push(stack, 10);
    assert(isEmpty(stack) == 0); // Stack should not be empty
    assert(stack->valueAt[stack->top] == 10); // Check top value

    push(stack, 20);
    assert(stack->valueAt[stack->top] == 20); // Check new top value
    assert(stack->top == 1); // Check top index

    // Test pop operation
    pop(stack);
    assert(stack->valueAt[stack->top + 1] == 20); // Ensure popped value
    assert(stack->top == 0); // Check top index after pop

    // Test stack overflow
    for (int i = 0; i < MAX; i++) {
        push(stack, i + 1); // Fill the stack
    }
    assert(stack->top == MAX - 1); // Top should be at MAX-1
    push(stack, 99); // Push beyond capacity (overflow)
    assert(stack->top == MAX - 1); // Top should not change

    // Test stack underflow
    for (int i = 0; i < MAX; i++) {
        pop(stack); // Empty the stack
    }
    assert(isEmpty(stack) == 1); // Stack should be empty
    pop(stack); // Try popping from an empty stack
    assert(isEmpty(stack) == 1); // Still empty

    free(stack); // Cleanup
    printf("All Tests Passed!\n");
}
