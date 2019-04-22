#include"tree.h"
#include"util.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<string.h>

Date *createDate(int y, int m, int d) {
	Date *date = (Date *)malloc(sizeof(Date));
	date->year = y;
	date->month = m;
	date->day = d;
	return date;
}

Medicine *createMedicine(char n[30], float p, Date *m, Date *e) {
    Medicine *med = (Medicine *)malloc(sizeof(Medicine));
    strcpy(med->name, n);
    med->price = p;
    med->mfg = m;
    med->exp = e;
}

void printMedicine(Medicine *med) {
    printf("Name:\t%s\n", med->name);
    printf("Prince:\t %f\n", med->price);
    printf("Manufactured: ");
    printDate(med->mfg);
    printf("Expiry: ");
    printDate(med->exp);
}

void printDate(Date *d) {
	printf("%2d/%2d/%4d\n", d->day, d->month, d->year);
}

Contact_Details *createContact(char n[30], long int pno, char e[50], char a[100]) {
    Contact_Details *cd = (Contact_Details *)malloc(sizeof(Contact_Details));
    strcpy(cd->name, n);
    cd->phone = pno;
    strcpy(cd->email, e);
    strcpy(cd->address, a);
    return cd;
}

void printContact(Contact_Details *cd) {
    printf("Name:\t%s\n", cd->name);
    printf("Phone:\t%ld\n", cd->phone);
    printf("Email:\t%s\n", cd->email);
    printf("Address:\t%s\n", cd->address);
}

Receipt *createReceipt(int i, Medicine *m, int q, Contact_Details *cd, int f, int t) {
    Receipt *r = (Receipt *)malloc(sizeof(Receipt));
    r->id = i;
    r->med = m;
    r->quantity = q;
    r->cd = cd;
    r->id_from = f;
    r->id_to = t;
    return r;
}

void printReceipt(Receipt *rec) {
    printf("Receipt:\n=====================================================\n");
    printf("Id:\t %d\n", rec->id);
    printf("Medicine Details:\n--------------------------------------------\n");
    printMedicine(rec->med);
    printf("Quantity:\t %d\n", rec->quantity);
    printf("Buyer Details:\n-----------------------------------------------\n");
    printContact(rec->cd);
    printf("From ID: %d \t To ID: %d\n", rec->id_from, rec->id_to);
}

void placeOrder(Vertex *root, Receipt *ord) {
    if(root == NULL) return;
    if(root->id == ord->id_to) {
        addNode(root->ords, createNode(ord));
        return;
    }
    Node *child = root->children->head;
    while(child != NULL) {
        placeOrder(child->data, ord);
        child = child->next;
    }
}

void addCrate(Vertex *v, Crate *c) {
    Node *crate = v->store->head;
    while(crate != NULL) {
        if(strcmp(((Crate *)(crate->data))->med->name, c->name) == 0) {
            ((Crate *)(crate->data))->quantity += c->quantity;
            break;
        }
    }
    if(crate == NULL) 
        addNode(v->store, createNode(c));
}

void sendShipment(Vertex *root, Receipt *rec, Crate *c) {
    if(root == NULL) return;
    if(root->id == rec->id_to) {
        addNode(root->recs, createNode(rec));
        addCrate(root, c);
        // print details to a file
        return;
    }
    Node *child = root->children->head;
    while(child != NULL) {
        sendShipment(child->data, rec);
        child = child->next;
    }
}
