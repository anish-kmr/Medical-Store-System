#include "credentials.h"

#ifndef FILE_HANDLE_H
#define FILE_HANDLE_H

void writeCredentials(Credentials* info);
void writeInfo(Credentials* info);
void writeVertex(Vertex* this);
void writeList(FILE* fp,LinkedList* this);
void writeReceipt(FILE* fp,Receipt* rec);
void writeDate(FILE* fp,Date* d);
void writeMedicine(FILE* fp,Medicine* med);
void writeContact(FILE* fp,Contact_Details* cd);

#endif