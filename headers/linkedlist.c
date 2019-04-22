#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"
struct test
{
    int id;
    int pd;
};
Node* createNode(void *data) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

LinkedList *createLinkedList() {
    LinkedList* newlist = (LinkedList*)malloc(sizeof(LinkedList));
    newlist->length=0;
    newlist->head=NULL;
    return newlist;
}

void addNode(LinkedList *ll, Node *n) {
    if (ll->head == NULL) {
        ll->head = n;
        return;
    }

    Node *current = ll->head;
    while(current->next != NULL) {
        current = current->next;
    }
    current->next = n;
}

void removeLastNode(LinkedList *ll) {
    Node *deleted_node, *current_node = ll->head;
    if(ll->length == 0){
        printf("List Already Empty\n");
    }
    else  if(ll->length == 1){
        deleted_node=current_node;
        ll->head = NULL;
    }
    else{
        while(current_node->next->next != NULL){
            current_node=current_node->next;
        }
        deleted_node=current_node->next;
        current_node->next=NULL;

    }
    free(deleted_node);
    ll->length--;

}

void printList(LinkedList* ll) {
    Node* current_node = ll->head;
    while(current_node != NULL) {
        printf("%d ",((struct test*)(current_node->data))->id );
        current_node=current_node->next;
    }

}

//TEST FOR LINKED LIST
//CHAL RHA HAI
// int main()
// {
//     LinkedList *list_struct=createLinkedList();
//     LinkedList *list_int=createLinkedList();


//     struct test t1;
//     t1.pd = 10;
//     t1.id = 20;
//     struct test t2;
//     t2.id=1000;
//     t2.pd = 223131;
//     addNode(list_struct,createNode(&t1));
//     addNode(list_struct,createNode(&t2));
//     printf("list of struct : \n");
//     printList(list_struct);


//     int a=99,b=100;
//     int*x,*y;
//     x=&a;
//     y=&b;
//     addNode(list_int,createNode(x));
//     addNode(list_int,createNode(y));

//     printf("\nlist of int:\n");
//     printList(list_int);
//     getch();
//     return 0;
// }
