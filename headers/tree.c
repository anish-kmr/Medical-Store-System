#include"linkedlist.h"
#include"tree.h"
#include<stdlib.h>
#include<string.h>


Vertex *createVertex(LinkedList *rec, LinkedList *cr, Level l, LinkedList *v) {
    Vertex *vert = (Vertex *)malloc(sizeof(Vertex));
    // vert->id = //some unique value;
    vert->recs = rec;
    vert->crates = cr;
    vert->lvl = l;
    vert->children = v;
    return;
}

void addVertex(Vertex *root, Vertex *parent, Vertex *child) {
    if(root == NULL) return;
    if(root->id == parent->id) {
        addNode(root->children, createNode(child));
        return;
    }
    Node *curr = root->children->head;
    while(curr != NULL) {
        addVertex(curr->data, parent, child);
        curr = curr->next;
    }
}