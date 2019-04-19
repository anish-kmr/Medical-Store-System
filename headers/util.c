#include"util.h"
#include<stdlib.h>
#include<stdio.h>

Date *createDate(int y, int m, int d) {
	Date *date = (Date *)malloc(sizeof(Date));
	date->year = y;
	date->month = m;
	date->day = d;
	return date;
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

Receipt *createReceipt(int i, int q, Contact_Details *cd, int f, int t) {
    Receipt *r = (Receipt *)malloc(sizeof(Receipt));
    r->id = i;
    r->quantity = q;
    r->cd = cd;
    r->id_from = f;
    r->id_to = t;
    return r;
}