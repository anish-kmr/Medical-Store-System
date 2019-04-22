#include <stdio.h>
#include <stdlib.h>
#include "headers/credentials.h"
#include "headers/display.h"
#include "headers/file_handle.h"
#include "headers/linkedlist.h"
#include "headers/tree.h"
#include "headers/util.h"
#include "headers/login.h"
#include "headers/medicine.h"


#define CLEAR system("clear");

int main(){
    int choice,status;
    Level type;
    Credentials info;
    char uname[50],upwd[50];
    CLEAR;
    header();
    welcome();
    mainMenu();
    choice = inputBox();

    if(choice == 1){
        //Signup
        while(true){
            CLEAR;
            getSignup(&info);
            status = validate(&info);
            if(status == SUCCESS){
                writeCredentials(&info);
                writeInfo(&info);
                CLEAR;
                //yaha pe login ke baad  wala page aaega
                break;
            }
            else{
                errorMessageS(status);
                press_to_continue();
            }
        }
        
        
        
    }
    if(choice == 2){
        //Login
        while(true){
            CLEAR;
            getLogin(&type,uname,upwd);
            status=login(type,uname,upwd);
            if(status == SUCCESS){
                //yaha pe bhi login ke baad  wala page aaega


                break;
            }
            else{
                errorMessageL(status);
                press_to_continue();
            }

        }
       
       
        

    }
    return 0;
}

