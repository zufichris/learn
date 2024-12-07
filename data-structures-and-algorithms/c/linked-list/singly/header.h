#ifndef HEADER_H
#define HEADER_H
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

typedef struct {
int length;
 Node * head;
}List;

List* newList(){
List* list =(List*)malloc(sizeof(List));
if(list==NULL){
printf("Error creating new list\n");
}

list->length=-1;
list->head=NULL;

return list;
}

void push(List*list,int data){
  Node* temp=(Node*)malloc(sizeof(Node));
  if(temp!=NULL){
    temp->next=list->head;
    temp->data=data;
    list->head=temp;
    list->length++;
    printf("Pushed %d\n",data);
  }
}

void pop(List* list, int pos) {
    if (pos > list->length || pos < 0) {
        printf("Invalid Position %d\n", pos);
        return;
    }

    if (pos == 0) {
        // Remove the head
        Node* temp = list->head;
        list->head = temp->next;
        printf("Removed %d at [%d]\n", temp->data, pos);
        free(temp);
    } else {
        // Traverse to the node before the one to be removed
        Node* temp = list->head;
        for (int i = 0; i < pos - 1; i++) {
            temp = temp->next;
        }

        Node* toPop = temp->next;
        temp->next = toPop->next;
        printf("Removed %d at [%d]\n", toPop->data, pos);
        free(toPop);
    }

    list->length--;
}


void print(List*list){
    if(list->length==0){
        printf("\nList is Empty!\n");
        return;
    }
    Node* temp=list->head;
    int i=0;
    while(i<=list->length){
        printf("[%d]->",temp->data);
        temp=temp->next;
        i++;
    }
        printf("\nLenght=%d\n",list->length);
}

#endif