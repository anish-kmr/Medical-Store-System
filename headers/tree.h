#ifndef TREE_H 
#define TREE_H

#include"linkedlist.h"

typedef enum {
    MANUFACTURER,
    STATE,
    DISTRIBUTOR,
    SHOP
} Level;

typedef struct {
    int id;
    Level lvl;
    LinkedList *ords;
    LinkedList *pending;
    LinkedList *recs;
    LinkedList *store;
    LinkedList *children;
} Vertex;

Vertex *createVertex(int id, Level lvl, LinkedList *ords, LinkedList *pending, LinkedList *recs, LinkedList *store, LinkedList *children);
void addVertex(Vertex *root, Vertex *parent, Vertex *v);
void removeNode(Vertex *v);
void printVertex(Vertex *v);

#endif
