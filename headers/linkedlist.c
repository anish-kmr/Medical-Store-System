#include<stdlib.h>
#include "linkedlist.h"

Node* createNode(void *data) {
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

LinkedList *createLinkedList() {
    LinkedList* newlist;
    newlist->length=0;
    newlist->head=NULL;
    return newlist;
}

void addNode(LinkedList *ll, Node *n) {
    if (ll->head == NULL) {
        ll->head = n;
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

void printList(LinkedList* ll) {
    Node* current_node = ll->head;
    while(current_node != NULL) {
        printf("%d ",current_node->data );
        current_node=current_node->next;
    }
}
