#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;  //pointer that points to prev node
    int data;
    struct Node *next; //pointer that points to next node
};

typedef struct Node Node;

Node *addtoEmpty(struct Node *head, int data){  //just makes a single node.
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}

void printList(struct Node *n){
    while(n!=NULL){
        printf("%d ", n->data);
        n=n->next;
    }
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

Node *addatEnd(struct Node *head, int data){
    Node *temp, *tr; //tr for traversal in nodes
    temp=(Node*)malloc(sizeof(Node));
    tr=head;
    temp->prev=NULL; 
    temp->data=data;
    temp->next=NULL;
    while(tr->next!=NULL){
        tr=tr->next;
    }
    tr->next=temp;
    temp->prev=tr;
    return head;
}

Node *addaftPos(struct Node *head, int data, int pos){ //to add a node after a given position
    Node *new=NULL;
    new=addtoEmpty(new,data);
    Node *temp=head;  //node before posn where new node is to be inserted
    Node *temp2=NULL;  //node after posn where new node is to be inserted
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    if(temp->next==NULL){ //last node
        temp->next=new;
        new->prev=temp;
    }
    else{
        temp2=temp->next;
        temp->next=new;
        temp2->prev=new;
        new->prev=temp;
        new->next=temp2;
        return head;
    }
}

Node *addatPos(struct Node *head, int data, int pos){ //to add a node at a given position
    Node *new=NULL;
    new=addtoEmpty(new,data);
    Node *temp=head;  //node before posn where new node is to be inserted
    Node *temp2=NULL;  //node after posn where new node is to be inserted
    while(pos>2){
        temp=temp->next;
        pos--;
    }
    if(pos==1){ //last node
        head=addatBeg(head,data);
    }
    else{
        temp2=temp->next;
        temp->next=new;
        temp2->prev=new;
        new->prev=temp;
        new->next=temp2;
        return head;
    }
}

Node *delFirst(struct Node *head){
    Node *temp;
    temp=head;
    head=head->next;
    free(temp);  // can do (1)head=head->next (2)free(head->prev)
    temp=NULL;
    head->prev=NULL;
    return head;
}

Node *delLast(struct Node *head){
    Node *temp, *temp2; //temp will point at last node and temp2 at 2nd last node
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp2=temp->prev;
    free(temp);
    temp=NULL;
    temp2->next=NULL;
    return head;
}

Node *delatPos(struct Node* head, int pos){
    Node *temp,*temp2,*temp3; //temp points at node to be deleted and temp2 point at previous node of node to be deleted and temp3 is next node
    temp2=temp3=NULL;
    temp=head;
    if(pos==1){
        head=delFirst(head);
        return head;
    }
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    temp2=temp->prev;
    temp3=temp->next;
    temp2->next=temp3;
    temp3->prev=temp2;
    free(temp);
    temp=NULL;
    return head;
}


int main(){
    struct Node *head=NULL;
    head=addtoEmpty(head,45);
    head=addatBeg(head,34);
    head=addatEnd(head,25);
    head=addaftPos(head,12,2);
    head=addatPos(head,67,2);
    head=addatEnd(head,99);

    head=delFirst(head);
    head=delLast(head);
    head=delatPos(head,2);

    printList(head);
    return 0;
}