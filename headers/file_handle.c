#include "file_handle.h"
#include <stdio.h>
void writeCredentials(Credentials* info){
    FILE *db;
    
    if(info->type == MANUFACTURER) db=fopen("../../files/credentials/Manufacturer.txt","a");
    else if(info->type == DISTRIBUTOR) db=fopen("../../files/credentials/Distributor.txt","a");
    else if(info->type == SHOP) db=fopen("../../files/credentials/Shop.txt","a");

    fprintf(db,"%s~%s\n",info->contactDetails.name,info->password);
    
}

void writeInfo(Credentials* info){
    FILE *db;
    
    if(info->type == MANUFACTURER) db=fopen("../../files/info/Manufacturer.txt","a");
    else if(info->type == DISTRIBUTOR) db=fopen("../../files/info/Distributor.txt","a");
    else if(info->type == SHOP) db=fopen("../../files/info/Shop.txt","a");

    fprintf(db,"%s~%ld~%s~%s\n",info->contactDetails.name,info->contactDetails.phone,info->contactDetails.email,info->contactDetails.address);
    
}