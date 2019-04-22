#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "headers/credentials.h"
#include "headers/display.h"
#include "headers/file_handle.h"
#include "headers/linkedlist.h"
#include "headers/tree.h"
#include "headers/util.h"
#include "headers/login.h"
// #include "headers/medicine.h"


#define CLEAR system("clear");

int main(){
    int choice,status,id;
    Vertex* root=createVertex(100,MANUFACTURER,createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList());

    int shop_id,shop_count=0;
    int dist_id,dist_count=0;
    int man_id=100,man_count=0;
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
                
                
                if(info.type == DISTRIBUTOR){
                    id=(man_id)*100 + (++dist_count);
                    dist_id=id;
                    addVertex(root,root,createVertex(id,DISTRIBUTOR,createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList()));
                    
                }
                else if(info.type == SHOP){
                    id=(dist_id)*100 + (++shop_count);
                    shop_id=id;
                    addVertex(root,root,createVertex(id,SHOP,createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList()));

                }
                // else if(info.type == MANUFACTURER){
                //     id=(man_id) + (++man_count);
                //     man_id=id;
                //     root=createVertex(id,MANUFACTURER,createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList());
                    
                // }
                
                // CLEAR;
                
                //yaha pe login ke baad  wala page aaega
                printf("ID : %d \n" ,id);
                DistributorHome(root,&id);
                break;
            }
            else{
                errorMessageS(status);
                press_to_continue();
            }
        }
        
        
        
    }
    // printf("id :%d\n\n",((Vertex*)(root->children->head->data))->id);
    if(choice == 2){
        //Login
        while(true){
            CLEAR;
            getLogin(&type,uname,upwd);
            printf("type : %d \n\n",type);
            status=login(type,uname,upwd);
            // printf("status %d\n",status);
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

