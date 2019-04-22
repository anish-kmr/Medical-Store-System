#include"linkedlist.h"
#include"tree.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

Vertex *createVertex(int id, Level l, LinkedList *ord, LinkedList *pend, LinkedList *rec, LinkedList *st, LinkedList *children) {
    Vertex *vert = (Vertex *)malloc(sizeof(Vertex));
    vert->id = id;
    vert->lvl = l;
    vert->ords = ord;
    vert->pending = pend;
    vert->recs = rec;
    vert->store = st;
    vert->children = children;
    return vert;
}

void addVertex(Vertex *root, Vertex *parent, Vertex *child) {
    if(root == NULL) return;
    if(root->id == parent->id) {
        if(root->children == NULL) {
            root->children = createLinkedList();
        }
        addNode(root->children, createNode(child));
        return;
    }
    Node *curr = root->children->head;
    while(curr != NULL) {
        addVertex(curr->data, parent, child);
        curr = curr->next;
    }
}
