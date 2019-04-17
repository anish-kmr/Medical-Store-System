#ifndef MEDICINE
#define MEDICINE

#include"date.h"

typedef enum {
	false,
	true
} bool;

typedef struct {
	char name[30];
	float price;
	Date *mfg;
	Date *exp;
	int code;
} Medicine;

Medicine *createMedicine(char n[], float p, Date *m, Date *e);
void printMedicine(Medicine *m);
bool isExpired(Medicine *m);

#endif
