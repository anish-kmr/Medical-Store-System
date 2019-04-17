#include<stdlib.h>
#include<stdio.h>
#include"date.h"

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
