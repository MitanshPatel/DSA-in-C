#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;  //pointer that points to prev node
    int data;
    struct Node *next; //pointer that points to next node
};

typedef struct Node Node;

void printList(struct Node *n){
    while(n!=NULL){
        printf("%d ", n->data);
        n=n->next;
    }
    printf("\n");
}

Node *addatBeg(struct Node *head, int data){  //node to be added at beginning
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=head;
    head->prev=temp;
    head=temp;  //temp becomes the new head as node is added at beginning
    return head;  
}

Node *addtoEmpty(struct Node *head, int data){  //just makes a single node.
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=head;
    head=temp;
    return head;
}

Node *reverse(Node *head){
    Node *ptr1=head;
    Node *ptr2=ptr1->next;

    ptr1->next=NULL;
    ptr1->prev=ptr2; // to update the first node only

    while(ptr2!=NULL){
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;  // this and above line just changes the pointer of next and prev for reversal
        ptr1=ptr2; // traversal of ptr1
        ptr2=ptr2->prev;  // travesal of ptr2
    }
    head=ptr1;  //ptr points to last node after upgradation, which in fact becomes first node after reversal, so ptr becomes new head
    return head;
}

int main(){
    Node *head=NULL;
    head=addtoEmpty(head,11);
    head=addatBeg(head,22);
    head=addatBeg(head,33);
    head=addatBeg(head,44);
    printList(head);

    head=reverse(head);
    printList(head);

}