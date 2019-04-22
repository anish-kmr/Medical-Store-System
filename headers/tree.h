#ifndef TREE_H 
#define TREE_H

#include"linkedlist.h"
#include"util.h"

typedef struct {
    int id;
    Level lvl;
    LinkedList *ords;
    LinkedList *recs;
    LinkedList *store;
    LinkedList *children;
} Vertex;

Vertex *createVertex(int id, Level lvl, LinkedList *ords, LinkedList *recs, LinkedList *store, LinkedList *children);
void addVertex(Vertex *root, Vertex *parent, Vertex *v);
void removeNode(Vertex *v);
void printVertex(Vertex *v);
void listOrders(Vertex *v);
void listShipments(Vertex *v);

#endif
