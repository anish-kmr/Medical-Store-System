#include<string.h>
#include<stdio.h>
#include"credentials.h"

#define UNMATCHED 0
#define FIELD_EMPTY -1
#define SUCCESS 1


void getCredentials(Credentials* info){
    int type_choice;
    printf("Type  \n\n");
    
    do{
        printf("1.Manufacturer\n2.Distributor\n3.Shop\n\nEnter your choice : ");
        scanf("%d",&type_choice);
    }while(type_choice!=1 && type_choice!=2 && type_choice!=3);

    switch (type_choice) {
        
        case (1):
            /* MANUFACTURER */
            info->type = MANUFACTURER;        
            break;
        case (2):
            /* DISTRIBUTER */
            info->type = DISTRIBUTOR;
            break;
        
        case (3):
            /* SHOP */
            info->type = SHOP;
            break;
        
        default:
            printf("\nEnter valid option\n");
            break;
    }

    
    printf("NAME  :  ");
    scanf(" %[^\n]%*c", info->contactDetails.name);

    printf("Phone NUmber   :  ");
    scanf(" %ld", &info->contactDetails.phone);


    printf("EMAIL ID   :  ");
    getchar();
    scanf(" %[^\n]%*c", info->contactDetails.email);


    printf("ADDRESS   :  ");
    scanf(" %[^\n]%*c", info->contactDetails.address);

    printf("Password  :  ");
    scanf(" %[^\n]%*c", info->password);

    printf("Confirm Password  :  ");
    scanf(" %[^\n]%*c", info->confirmPassword);
}

int validate(Credentials* info){
    if(info->contactDetails.name[0]=='\0'|| info->password[0]=='\0' || info->contactDetails.email[0]=='\0' || info->confirmPassword[0]=='\0' || info->contactDetails.address[0]=='\0'  ) return FIELD_EMPTY;
    if(strcmp(info->password,info->confirmPassword)) return UNMATCHED;
    
    return SUCCESS;
}

//Test for validate and getCredetials functions


// P R O B L E M ---> Jab phone no. me character daalne ki koshish karte hai to email id ka input skip ho jaata hai


// int main(){
//     printf("hello\n");
//     Credentials info;
//     getCredentials(&info);
//     printf(" \nstatus = %d",validate(&info));
//     return 0;
// }
