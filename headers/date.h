#ifndef DATE
#define DATE

typedef struct {
	int year;
	int month;
	int day;
} Date;

Date *createDate(int d, int m, int y);
void printDate(Date *d);

#endif
