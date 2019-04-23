#include "file_handle.h"
#include <stdio.h>
// #include <stdlib.h>
void writeCredentials(Credentials* info){
    FILE *db;
    
    if(info->type == MANUFACTURER) db=fopen("../files/credentials/Manufacturer.txt","a");
    else if(info->type == DISTRIBUTOR) db=fopen("../files/credentials/Distributor.txt","a");
    else if(info->type == SHOP) db=fopen("../files/credentials/Shop.txt","a");

    fprintf(db,"%d~%s\n",info->id,info->password);
}

void writeInfo(Credentials* info){
    FILE *db;
    
    if(info->type == MANUFACTURER) db=fopen("../files/info/Manufacturer.txt","a");
    else if(info->type == DISTRIBUTOR) db=fopen("../files/info/Distributor.txt","a");
    else if(info->type == SHOP) db=fopen("../files/info/Shop.txt","a");

    fprintf(db,"%d~%s~%ld~%s~%s\n",info->id,info->contactDetails.name,info->contactDetails.phone,info->contactDetails.email,info->contactDetails.address);
    // printf("wrote it");
}

void writeOrders(LinkedList *orders) {}

void writeReceipts(LinkedList *receipts) {}

void writeStore(LinkedList *store) {}

void writePending(LinkedList *pending) {}

void writeVertex(Vertex* this){
    FILE *db;
    db=fopen("../files/tree/tree.txt","ab");
    fprintf(db,"%d\n%d\n",this->id,this->lvl);
    writeList(db,this->ords);
    writeList(db,this->pending);
    writeList(db,this->recs);
    
}

void writeList(FILE* fp,LinkedList* this){
    if(this->length == 0) {
        fprintf(fp,"No orders to verify.\n");
        return;
    }
    Node *curr = this->head;
    while(curr != NULL) {
        writeReceipt(fp,curr->data);
        curr = curr->next;
    }
}

void writeReceipt(FILE* fp,Receipt* rec){
    fprintf(fp,"Receipt:\n=====================================================\n");
    fprintf(fp,"Id:\t %d\n", rec->id);
    fprintf(fp,"Date:\t");
    writeDate(fp,rec->date);
    fprintf(fp,"Medicine Details:\n--------------------------------------------\n");
    writeMedicine(fp,rec->med);
    fprintf(fp,"Quantity:\t %d\n", rec->quantity);
    fprintf(fp,"Buyer Details:\n-----------------------------------------------\n");
    writeContact(fp,rec->cd);
    fprintf(fp,"From ID: %d \t To ID: %d\n", rec->id_from, rec->id_to);
}

void writeDate(FILE* fp,Date* d){
    fprintf(fp,"%2d/%2d/%4d\n", d->day, d->month, d->year);
}

void writeMedicine(FILE* fp,Medicine* med){
    fprintf(fp,"Name:\t%s\n", med->name);
    fprintf(fp,"Prince:\t %f\n", med->price);
    fprintf(fp,"Manufactured: ");
    writeDate(fp,med->mfg);
    fprintf(fp,"Expiry: ");
    writeDate(fp,med->exp);
}

void writeContact(FILE* fp,Contact_Details* cd){
    fprintf(fp,"Name:\t%s\n", cd->name);
    fprintf(fp,"Phone:\t%ld\n", cd->phone);
    fprintf(fp,"Email:\t%s\n", cd->email);
    fprintf(fp,"Address:\t%s\n", cd->address);
}

void details_from_id(Contact_Details* cd,Level type,int id){
    FILE *db;
    int dbid;
    if(type == MANUFACTURER) db=fopen("../files/info/Manufacturer.txt","r");
    else if(type == DISTRIBUTOR) db=fopen("../files/info/Distributor.txt","r");
    else if(type == SHOP) db=fopen("../files/info/Shop.txt","r");

    while( !feof(db)){
        fscanf(db,"%d",&dbid );
        fgetc(db);
        
        // printf("id : %d ~ " ,dbid);
        // printf("password : %s \n", dbpwd);
        if(dbid == id){
            // printf("id is %d",id);
            fscanf(db,"%[^~]",cd->name);
            fgetc(db);
            fscanf(db,"%ld",&cd->phone);
            fgetc(db);
            fscanf(db,"%[^~]",cd->email);
            fgetc(db);
            fscanf(db,"%[^\n]",cd->address);
            fgetc(db);
            
            // printf("name: %s  phone :%ld email:%s  address : %s\n",cd->name,cd->phone,cd->email,cd->address);
        }
    }  
}