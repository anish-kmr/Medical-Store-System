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

struct node* createNode(int data);
LinkedList *createLinkedList(struct node *head);
void addNode(LinkedList *ll, struct node *n);
void removeLastNode(LinkedList *ll);
//add more functions if necessary
//function definitions in "linkedlist.c"

#endif
