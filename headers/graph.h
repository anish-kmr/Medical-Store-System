#ifndef GRAPH_H
#define GRAPH_H

struct node {
	int data;
	struct node *next;
};

typedef struct {
	// how much medicines recieved
	// create_id
	// how much sent
	// contact details
	struct node *child;
} Graph;

//function to verify fishy things in graph

#endif
