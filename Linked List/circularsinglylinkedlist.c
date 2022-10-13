//tail pointer is used instead of head pointer because we have to updated link part of last node to add element at beginning

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;  //pointer pointing to the next element
};

typedef struct Node Node; 

Node *addToEmpty(int data){  //single node
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

Node *addAtBeg(Node *tail, int data){
    Node *newP=(Node *)malloc(sizeof(Node));
    newP->data=data;
    newP->next=tail->next; //tail->next points to first node
    tail->next=newP; //updating and adding new first node
    return tail;
}

Node *addAtEnd(Node *tail,int data){
    Node *newP=(Node *)malloc(sizeof(Node));
    newP->data=data;
    newP->next=tail->next;
    tail->next=newP;
    tail=tail->next;
    return tail;
}

Node *addAfterPos(Node *tail,int data,int pos){
    Node *newP=(Node *)malloc(sizeof(Node));
    Node *p=tail->next;
    newP->data=data;
    newP->next=NULL;
    while(pos>1){
        p=p->next;  // will point to node before where new node will be added.
        pos--;
    }
    newP->next=p->next;
    p->next=newP;
    if(p==tail){
        tail=tail->next;
    }
    return tail;
}

Node *delFirst(Node *tail){
    if(tail==NULL){
        return tail;
    }
    if(tail->next==tail){  //only one node
        free(tail);
        tail=NULL;
        return tail;
    }
    Node *temp=tail->next;
    tail->next=temp->next;
    free(temp);
    temp=NULL;
    return tail;
}

Node* delLast(Node *tail){
    if(tail==NULL){
        return tail;
    }
    Node *temp=tail->next;
    if(tail->next==tail){  //only one node
        free(tail);
        tail=NULL;
        return tail;
    }
    while(temp->next!=tail){
        temp=temp->next;  //will point to second last node
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
    return tail;
}

Node *delInter(Node *tail, int pos){
    if(tail==NULL){
        return tail;
    }
    Node *temp=tail->next;
    if(tail->next==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    while(pos>2){
        temp=temp->next;
        pos--;
    }
    Node *temp2=temp->next;  //temp2 is node to be deleted
    temp->next=temp2->next;

    if(temp2==tail){
        tail==temp;
    }
    free(temp2);
    temp2=NULL;
    return tail;
}

int searchElement(Node *tail,int element){
    Node *temp;
    int index=0;

    if(tail==NULL){
        return -2;
    }

    temp=tail->next;
    do{
        if(temp->data==element){
            return index;
        }
        temp=temp->next;
        index++;
    }
    while(temp!=tail->next);
    return -1;
}

void printList(Node *tail){
    Node *p=tail->next; //points to first node
    printf("Circular Linked list is: ");
    do{
        printf("%d ",p->data);
        p=p->next;
    }
    while(p!=tail->next);
}

int main(){
    Node *tail;
    tail=addToEmpty(45);
    tail=addAtBeg(tail,34);
    tail=addAtBeg(tail,77);
    tail=addAtEnd(tail,22);
    tail=addAtEnd(tail,11);
    tail=addAfterPos(tail,66,3);

    tail=delFirst(tail);
    tail=delLast(tail);
    tail=delInter(tail,3);

    int a=searchElement(tail,45);


    printList(tail);
    if(a==-1 || a==-2){
        printf("\nNo element found");
    }
    else printf("\n ELement at position %d",a+1);
    return 0;
}