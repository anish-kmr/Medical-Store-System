#include "linked_list.h"

node* createNode(int data){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

LinkedList *createLinkedList(){
    LinkedList* newlist ;
    newlist->length=0;
    newlist->head=NULL;
    return newlist;
}
void addNode(LinkedList *ll, int newdata){
    node *n = createNode(newdata);
    node *current_node=ll->head;
    if(ll->head==NULL){
        ll->head=n;

    }
    else{
        while(current_node->next!=NULL){
            current_node=current_node->next;
        }
        current_node->next=n;
    }


    ll->length++;
}

void removeLastNode(LinkedList *ll){
    node *deleted_node,* current_node = ll->head;
    if(ll->length == 0){
        printf("List Already Empty\n");
    }
    else if(ll->length == 1){
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
void print(LinkedList* ll){
    node* current_node = ll->head;
    while(current_node != NULL){
        printf("%d ",current_node->data );
        current_node=current_node->next;
    }
}
