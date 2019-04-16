#include"medicine.h"
#include"date.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

Medicine *createMedicine(char n[], float p, Date *m, Date *e) {
	Medicine *med = (Medicine *)malloc(sizeof(Medicine));
	strcpy(med->name, n);
	med->price = p;
	med->mfg = m;
	med->exp = e;
	return med;
}

bool isExpired(Medicine *m) {
	//thoda baad me
}

void printMedicine(Medicine *m) {
	printf("Name:\t%s", m->name);
	printf("Price:\t%f", m->price);
	printf("Mfg:\t\t");
	printDate(m->mfg);
	printDate(m->exp);
}
