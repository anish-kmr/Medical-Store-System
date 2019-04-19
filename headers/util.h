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
    int id;
    int quantity;
    Contact_Details *cd;
    int id_from, id_to;
} Receipt;

typedef struct {
	int year;
	int month;
	int day;
} Date;

Date *createDate(int d, int m, int y);
void printDate(Date *d);
Contact_Details *createContact(char n[30], long int pno, char e[50], char a[100]);
Receipt *createReceipt(int id, int quantity, Contact_Details *cd, int from, int to);

#endif