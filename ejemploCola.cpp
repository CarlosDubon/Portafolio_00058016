
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct Node{
    int data;
    Node* next;
} Node ;


Node* createNode(int d){
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = d;
    n->next = NULL;
    return n;
}

void push(Node** head, Node* node){
    if(*head == NULL){
        *head = node;
    }else{
        Node* aux;
        aux = *head;
        *head = node;
        node->next = aux;
        
    }
}

void popRec(Node* c,Node* b){
    if(c==NULL)
        return;
    if(c->next==NULL){
        b->next=NULL;
    }
    popRec(c->next,c);
}

void pop(Node** head){
    popRec(*head,*head);
}



void print(Node* head){
    if(head == NULL)
        return;
    cout << head->data << endl;
    print(head->next);
    
}

int main(){
    Node* head;
    head = NULL;

    push(&head,createNode(0));
    push(&head,createNode(1));
    push(&head,createNode(2));
    
    pop(&head);
    
    print(head);
    

    return 0;
}





/*
FILO
->NULL
->0->NULL
->1->0->NULL
->2->1->0->NULL
->2->1->NULL
*/




