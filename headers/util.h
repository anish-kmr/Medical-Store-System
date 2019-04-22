#ifndef UTIL_H
#define UTIL_H

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
	int year;
	int month;
	int day;
} Date;

typedef struct {
    char name[30];
    float price;
    Date *mfg;
    Date *exp;
} Medicine;

typedef struct {
    Medicine *med;
    int quantity;
} Crate;

typedef struct {
    int id;
    Medicine *med;
    int quantity;
    Contact_Details *cd;
    int id_from, id_to;
} Receipt;

Date *createDate(int d, int m, int y);
Medicine *createMedicine(char n[30], float p, Date *m, Date *e);
void printMedicine(Medicine *med);
void printDate(Date *d);
Contact_Details *createContact(char n[30], long int pno, char e[50], char a[100]);
void printContact(Contact_Details *cd);
Receipt *createReceipt(int id, Medicine *med, int quantity, Contact_Details *cd, int from, int to);
void printReceipt(Receipt *rec);
void placeOrder(Receipt *ord);
void sendShipment(Receipt *rec);
void verify(Vertex *v);

#endif
