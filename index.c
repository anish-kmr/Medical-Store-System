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
    Vertex* root=createVertex(101,MANUFACTURER,createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList());
    Vertex* newVertex;
    Vertex* newVertex1;
    Vertex* newVertex2;
    int shop_id,shop_count=0;
    int dist_id,dist_count=0;
    int man_id=101,man_count=0;
    Level type;
    Credentials info;
    char upwd[50];
    int uid;
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
                
                if(info.type == DISTRIBUTOR){
                    id=(man_id)*100 + (++dist_count);
                    dist_id=id;
                    
                    info.id=id;
                    newVertex = createVertex(id,DISTRIBUTOR,createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList());
                    addVertex(root,root,newVertex);
                    displayId(id);
                    writeCredentials(&info);
                    writeInfo(&info);
                    press_to_continue();
                    DistributorHome(root,dist_id);
                }
                else if(info.type == SHOP){
                    id=(dist_id)*100 + (++shop_count);
                    shop_id=id;

                    info.id=id;
                    newVertex = createVertex(id,SHOP,createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList());
                    addVertex(root,root,newVertex);
                    displayId(id);
                    writeCredentials(&info);
                    writeInfo(&info);
                    press_to_continue();
                    // ShopHome(root,shop_id);
                    
                }
                // else if(info.type == MANUFACTURER){
                //     id=(man_id) + (++man_count);
                //     man_id=id;
                //     root=createVertex(id,MANUFACTURER,createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList());
                    
                // }
                
                // CLEAR;
                
                //yaha pe login ke baad  wala page aaega
                printf("ID : %d \n" ,id);
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
            getLogin(&type,&uid,upwd);
            printf("pwd : %s \n\n",upwd);
            status=login(type,uid,upwd);
            printf("status %d\n",status);
            if(status == SUCCESS){
                //yaha pe bhi login ke baad  wala page aaega
                printf("hello1");
                newVertex1 = createVertex(uid,DISTRIBUTOR,createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList());
                addVertex(root,root,newVertex1);
                // newVertex2 = createVertex(1010101,SHOP,createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList(),createLinkedList());
                // addVertex(root,newVertex1,newVertex2);
                printf("hello");
                newVertex= findVertex(root,10101);
                if(newVertex){
                    printf("\n\n%d",newVertex->id);
                }
                
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

