#include "tree.h"
#include "util.h"
#include <stdio.h>
#include <string.h>

#define SUCCESS 1;
#define PASSWORD_WRONG -1;
#define NOT_FOUND 0;


int login(Level type,char* id,char*pwd){
    FILE *db;
    
    char *token,line[100],dbid[50],dbpwd[50];
    
    if(type == MANUFACTURER) db = fopen("../files/credentials/Manufacturer.txt","r"); 
    else if(type == DISTRIBUTOR) db = fopen("../files/credentials/Distributor.txt","r"); 
    else if(type == SHOP) db = fopen("../files/credentials/Shop.txt","r"); 

    while( !feof(db)){
        fscanf(db,"%[^~]",dbid );
        fgetc(db);              //To skip ~ 
        fscanf(db,"%[^\n]",dbpwd);
        fgetc(db);              //To skip \n
        
        if(! strcmp(dbid,id)){
            if(!strcmp(dbpwd,pwd)){
                return SUCCESS;
            }
            else{
                return PASSWORD_WRONG;
            }
        }
    }
    return NOT_FOUND;    

}

// int main(){
//     // char id[] = "ad";
//     // char pwd[] = "password";
//     // int st=login(MANUFACTURER,id,pwd);
//     // printf("%d",st);
//     printf("\t ________________________\n");
//     printf("\t|         HELLO          |\n");
//     printf("\t|________________________|\n");
//     return 0;

// }
