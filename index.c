#include <stdio.h>
#include <string.h>


#define CUSTOMER 2
#define OWNER 1


typedef struct {
    char username[15];
    char storename[20];
    char address[50];
    int pno;
    char email[20];
    char pwd[20];
    char cpwd[20];
}Credentials;


int validate(Credentials*,int type); //-1 : passwords not match 0: fields empty 1: OK
void takeDetails(Credentials* , int type);
int main(){
    int i,choice;
    FILE *od, *cd;
    Credentials owner,customer;
    printf("\n1.SEARCH MEDICINES\n2.LIST CATEGORIES\n3.LOGIN\n4.SIGNUP\n5. EXIT\n");
    
    do{
        printf("\nENTER YOUR CHOICE : ");
        scanf("%d",&choice);

        switch (choice)
        {
            case 1:
                /* SEARCH MEDICINES */
                break;
            
            case 2:
                /* LIST CATEGORIES */
                break;
            case 3:
                /* LOGIN */


                break;
            case 4:
                /* SIGNUP */
                printf("\n1.OWNER OF A STORE\n2.CUSTOMER\n3.GO BACK\n");
                scanf("%d",&choice);
                takeDetails(&owner,choice); 
                int status=validate(&owner,choice);
                if(status == 0) printf("\nFields should not be empty\n");
                else if(status == -1) printf("\nPASSWORDS NOT MATCH\n");

                else if(status==1){
                    
                    if(choice==OWNER){
                    
                        if(od=fopen("credentials/owner.txt","a")){
                            printf("\nsuccess opening file\n");
                            fprintf(od,"%s , %s , %s , %d , %s\n",owner.email,owner.storename,owner.username,owner.pno,owner.address);
                            printf("\nSUCCESSFULLY SIGNED IN :-)\n");
                            fclose(od);
                        }
                        else printf("\nERROR OPENING FILE\n");
                    } 
                    else if(choice==CUSTOMER){
                        if(cd=fopen("credentials/customer.txt","a")){
                            printf("\nsuccess opening file\n");
                            fprintf(cd,"%s , %s , %d , %s\n",owner.email,owner.username,owner.pno,owner.address);
                            printf("\nSUCCESSFULLY SIGNED IN :-)\n");
                            fclose(cd);
                        }

                    }
                    
                    
                }
                
                break;
            default:
                break;
        }
    }
    while(choice!=5);



}

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

void takeDetails(Credentials* user , int type){
    if(type==OWNER){
        printf("STORE NAME   :  ");
        getchar();
        scanf(" %[^\n]%*c", user->storename);
    }

    printf("USENAME  :  ");
    
    scanf(" %[^\n]%*c", user->username);

    printf("ADDRESS   :  ");
    
    scanf(" %[^\n]%*c", user->address);

    printf("Phone NUmber   :  ");
    
    scanf(" %d", &user->pno);

    printf("EMAIL ID   :  ");
    getchar();
    scanf(" %[^\n]%*c", user->email);

    printf("Password  :  ");
    
    scanf(" %[^\n]%*c", user->pwd);

    printf("Confirm Password  :  ");
    
    scanf(" %[^\n]%*c", user->cpwd);
}
