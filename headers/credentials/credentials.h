#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#define CUSTOMER 2
#define OWNER 1

#define SUCCESS 0
#define FAIL 1
#define FEILD_EMPTY -1

typedef struct {
	char username[15];
	char storename[20];
	char address[50];
	int pno;
	char email[20];
	char pwd[20];
	char cpwd[20];
} Credentials;

int validate(Credentials*, int type);

#endif
