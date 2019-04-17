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
    int received, sent;
    int id;
    int quantity;
    Contact_Details *cd;
    Level from, to;
} Receipt;

typedef struct {
    Receipt *rec;
    LinkedList *crates;
    Level lvl;
    LinkedList *children;
} Graph;

Receipt *generateReceipt(int received, int sent, Contact_Details *cd, Level from, Level to);
void sendCrate(Receipt *rec);

#endif
