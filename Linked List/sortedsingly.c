#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next; 
};

typedef struct Node Node;

void printList(struct Node *n){
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
}

Node *addtoEmpty(struct Node *head, int data){  //just makes a single node.
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}

Node* insertAndSort(Node *head, int data){
    Node *temp;
    Node *newP=(Node*)malloc(sizeof(Node)); //node to be inserted
    newP->data=data;
    newP->next=NULL;

    int key=data;
    if(head==NULL || key < head->data){  //if node to be added is at the start, as key is less than data of head OR no node in LL
        newP->next=head;
        head=newP;
    }

    else{
        temp=head;  //will be used for traversing
        while(temp->next!=NULL && temp->next->data <key){  
            temp=temp->next;  // temp will point to node before the new node will be inserted
        }
        newP->next=temp->next;
        temp->next=newP;
        
        return head;
    }
}

int main(){
    Node *head=NULL;
    head=addtoEmpty(head,44);
    head=insertAndSort(head,33);
    head=insertAndSort(head,88);
    head=insertAndSort(head,55);

    printList(head);
}