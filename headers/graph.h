#ifndef GRAPH_H
#define GRAPH_H

struct node {
	int data;
	struct node *next;
};

typedef struct {
	int date;
	
	struct node *child;
} Graph;

#endif
