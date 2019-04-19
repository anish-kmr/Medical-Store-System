#ifndef TREE_H 
#define TREE_H

#include"linkedlist.h"
#include"util.h"

typedef struct {
    int id;
    LinkedList *recs;
    LinkedList *crates;
    Level lvl;
    LinkedList *children;
} Vertex;

Vertex *createVertex(LinkedList *rec, LinkedList *c, Level l, LinkedList *v);
void addVertex(Vertex *root, Vertex *parent, Vertex *v);
void removeNode(Vertex *v);

Receipt *generateReceipt(int rec, int i, int q, Contact_Details *cd, Level from, Level to);
void sendCrate(Receipt *rec);
// verify for receipt of every node
void verify(Receipt *rec);

#endif
