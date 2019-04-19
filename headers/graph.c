#include"linkedlist.h"
#include"graph.h"
#include<stdlib.h>
#include<string.h>

Contact_Details *createContact(char n[30], long int pno, char e[50], char a[100]) {
    Contact_Details *cd = (Contact_Details *)malloc(sizeof(Contact_Details));
    strcpy(cd->name, n);
    cd->phone = pno;
    strcpy(cd->email, e);
    strcpy(cd->address, a);
    return cd;
}

Receipt *createReceipt(int i, int q, Contact_Details *cd, int f, int t) {
    Receipt *r = (Receipt *)malloc(sizeof(Receipt));
    r->id = i;
    r->quantity = q;
    r->cd = cd;
    r->id_from = f;
    r->id_to = t;
    return r;
}

Vertex *createVertex(LinkedList *rec, LinkedList *cr, Level l, LinkedList *v) {
    Vertex *vert = (Vertex *)malloc(sizeof(Vertex));
    vert->id = //some unique value;
    vert->recs = rec;
    vert->crates = cr;
    vert->lvl = l;
    vert->children = v;
    return;
}

Vertex *dfs(Vertex *root, Vertex *v) {
    if(root->id == v->id)
        return root;
    if(root == NULL)
        return NULL;
    Vertex *vert;
    Node *curr;
    curr = root->children->head;
    while(curr != NULL) {
        vert = dfs(curr, v);
        curr = curr->next;
    }
    return vert;
}

void addVertex(Vertex *root, Vertex *parent, Vertex *v) {
    Vertex *vert = dfs(root, parent);
    addNode(vert->children, v);
}
