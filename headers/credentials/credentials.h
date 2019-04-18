#include "../graph.h"
#ifndef CREDENTIAL_H
#define CREDENTIAL_H

#define SUCCESS 1
#define FAIL 0
#define FEILD_EMPTY -1

typedef struct {
	Level type;
	Contact_Details contactDetails;
	char password[20];
	char confirmPassword[20];

} Credentials;

void getCredentials(Credentials*);
int validate(Credentials*);

#endif
