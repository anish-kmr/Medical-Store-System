#ifndef LINKED_H
#define LINKED_H

struct node{
    int data;
    struct node *next;
};

typedef struct list{
    int length;
    struct node *head;
} LinkedList;

typedef struct node node;

struct node* createNode(int data);
LinkedList *createLinkedList();
void addNode(LinkedList *ll, int newdata);
void removeLastNode(LinkedList *ll);
void print(LinkedList* ll)
//add more functions if necessary
//function definitions in "linkedlist.c"

#endif

	
	
