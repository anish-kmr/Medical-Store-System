#include<string.h>
#include"credentials.h"

int validate(Credentials* info,int type){
    int status=1;
    FILE *db;
    if(info->username[0]=='\0'|| info->pwd[0]=='\0' || info->email[0]=='\0' || info->cpwd[0]=='\0' || info->address[0]=='\0'  ) return 0;
    if(strcmp(info->pwd,info->cpwd)) return -1;
    if(type == OWNER){
        if( info->storename[0]=='\0' ) return 0;
    }
    return status;
}
