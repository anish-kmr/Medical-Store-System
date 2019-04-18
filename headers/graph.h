#ifndef GRAPH_H
#define GRAPH_H
#include"linkedlist.h"

typedef enum {
    MANUFACTURER,
    STATE,
    DISTRIBUTOR,
    SHOP
} Level; 

typedef struct { 
    char name[30]; 
    long int phone;
    char email[50];
    char address[100];
} Contact_Details;

typedef struct {
    int id;
    int quantity;
    Contact_Details *cd;
    int id_from, id_to;
} Receipt;

typedef struct {
    int id;
    LinkedList *recs;
    LinkedList *crates;
    Level lvl;
    LinkedList *children;
} Vertex;

Contact_Details *createContact(char n[30], long int pno, char e[50], char a[100]);
Receipt *createReceipt(int received, int id, int quantity, Contact_Details *cd, Level from, Level to);
Vertex *createVertex(LinkedList *rec, LinkedList *c, Level l, LinkedList *v);

Vertex *dfs(Vertex *root, Vertex *v);
void addVertex(Vertex *root, Vertex *parent, Vertex *v);
void removeNode(Vertex *v);

Receipt *generateReceipt(int rec, int i, int q, Contact_Details *cd, Level from, Level to);
void sendCrate(Receipt *rec);
// verify for receipt of every node
void verify(Receipt *rec);

#endif
