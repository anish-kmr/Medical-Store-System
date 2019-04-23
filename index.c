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

#define CLEAR system("clear");

Vertex *root = createVertex(101, MANUFACTURER, createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList());
Medicine combiflame = createMedicine("Combiflame", 20, createDate(4, 5, 17), createDate(5, 6, 19));
Medicine paracetamol = createMedicine("Medicine", 15, createDate(3, 7, 18), createDate(4, 8, 19));
Medicine brufen = createMedicine("Brufen", 17, createDate(8, 3, 18), createDate(9, 4, 19));
addVertex(root, root, createVertex(10101, DISTRIBUTOR, createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList()));
addVertex(root, root, createVertex(10102, DISTRIBUTOR, createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList()));
addVertex(root, findVertex(root, 10101), createVertex(1010101, SHOP, createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList()));
addVertex(root, findVertex(root, 10101), createVertex(1010102, SHOP, createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList()));
addVertex(root, findVertex(root, 10101), createVertex(1010103, SHOP, createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList()));
addVertex(root, findVertex(root, 10102), createVertex(1010201, SHOP, createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList()));
addVertex(root, findVertex(root, 10102), createVertex(1010202, SHOP, createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList(), createLinkedList()));
addVertex(root, findVertex(root, 10102), createVertex(1010203, SHOP, createLinkedList(), createLinkedList(), createLinekdList(), createLinkedList(), createLinkedList()));

Receipt *r1 = createReceipt(1, combiflame, createDate(14, 12, 18), 1000, createContact("Shreyansh", 9838177556, "chouhan.shreyansh630@gmail.com", "adress"), 101, 10101);
Receipt *r2 = createReceipt(2, paracetamol, createDate(13, 11, 18), 1500, createContact("Anish", 8723482947, "email", "adress"));

sendShipment(root, r1, createCrate(r1->name, r1->quantity));
sendShipment(root, r2, createCrate(r2->name, r2->quantity));

int main(){
    int choice,status,id;
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

