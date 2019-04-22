#include"linkedlist.h"
#include"tree.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

Vertex *createVertex(int id, Level l, LinkedList *ord, LinkedList *rec, LinkedList *st, LinkedList *children) {
    Vertex *vert = (Vertex *)malloc(sizeof(Vertex));
<<<<<<< HEAD
    vert->id = id;
=======
    // vert->id = //some unique value;
    vert->recs = rec;
    vert->crates = cr;
>>>>>>> c1acb0751dc872f1e44a1f067b60a6645a0c9514
    vert->lvl = l;
    vert->ords = ord;
    vert->recs = rec;
    vert->store = st;
    vert->children = v;
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

void printVertex(Vertex *v) {
    printf("List of the receipts here:\n");
    printf("------------------------------------------------------\n");
    Node *curr = v->recs->head;
    while(curr != NULL) {
        printReceipt(curr->data);
        curr = curr->next;
    }
    printf("------------------------------------------------------\n");
}

void listOrders(Vetex *v) {
    printf("Pending Orders:\n");
    printf("------------------------------------------------------\n");
    Node *curr = v->ords->head;
    while(curr != NULL) {
        printReceipt(curr->data);
        curr = curr->next;
    }
    printf("------------------------------------------------------\n");
}

void listShipments(Vertex *v) {
    printf("Past successful shipments:\n");
    printf("------------------------------------------------------\n");
    Node *curr = v->recs->head;
    while(curr != NULL) {
        printReceipt(curr->data);
        curr = curr->next;
    }
    printf("------------------------------------------------------\n");
}
