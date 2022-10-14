#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;  //pointer that points to prev node
    int data;
    struct Node *next; //pointer that points to next node
};

typedef struct Node Node;

Node *addToEmpty(int data){  //just makes a single node.
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->prev=temp;
    temp->data=data;
    temp->next=temp;
    return temp;
}

Node *addAtBeg(Node* tail,int data){
    Node *newP=addToEmpty(data);
    if(tail==NULL){  //linked list is empty
        return newP;
    }
    else{
        Node *temp=tail->next; //will point to first node of LL
        newP->prev=tail;
        newP->next=temp;
        temp->prev=newP;
        tail->next=newP;
        return tail;
    }
}

Node *addAtEnd(Node *tail,int data){
    Node *newP=addToEmpty(data);
    if(tail==NULL){
        return newP;
    }
    else{
        Node *temp=tail->next;
        newP->next=temp;
        newP->prev=tail;
        tail->next=newP;
        temp->prev=newP;
        tail=newP;  //newP becomes the new tail
        return tail;
    }
}

Node *addAfterPos(Node *tail,int data, int pos){
    Node *newP=addToEmpty(data);
    if(tail==NULL){
        return newP;
    }
    Node *temp=tail->next;
    while(pos>1){
        temp=temp->next;
        pos--;
    }
    Node *temp2=temp->next;
    newP->prev=temp;
    newP->next=temp2;
    temp2->prev=newP;
    temp->next=newP;
    if(temp==tail){
        tail=tail->next;
    }
    return tail;
}

void printList(Node *tail){
    if(tail==NULL){
        printf("No element in linked list");
    }
    else{
        Node *temp=tail->next;  //points to first node
        do{
            printf("%d ",temp->data);
            temp=temp->next;
        }
        while(temp!=tail->next);
    }
    printf("\n");
}

Node *delFirst(Node *tail){
    if(tail==NULL){
        return tail;
    }
    Node *temp=tail->next;  // node to be deleted
    if(temp==tail){
        free(tail);
        tail=NULL;
        return tail;
    }
    Node *temp2=temp->next;
    tail->next=temp2;
    temp2->prev=tail;
    free(temp);
    return tail;
}

Node *delLast(Node *tail){
    Node *temp2=tail->prev;  // points to second last node
    if(tail==NULL){
        return tail;
    }
    if(temp2==tail){
        free(tail);
        tail==NULL;
        return tail;
    }
    else{
        Node *temp=tail->next; //points to first node
        temp2->next=temp;
        temp->prev=temp2;
        free(tail);
        tail=temp2;
        return tail;
    }
}

Node *delInter(Node *tail, int pos){
    Node *temp=tail->next;  //first node
    while(pos>1){
        temp=temp->next;  //temp will now point to node to be deleted
        pos--;
    }
    Node *temp2=temp->prev;
    Node *temp3=temp->next;
    temp2->next=temp3;
    temp3->prev=temp2;
    free(temp);
    if(temp==tail){
        tail=temp2;
    }
    return tail;

}

int main(){
    Node *tail=addToEmpty(10);
    tail=addAtBeg(tail,20);
    tail=addAtBeg(tail,30);
    tail=addAtEnd(tail,40);
    tail=addAfterPos(tail,50,2);

    tail=delFirst(tail);
    tail=delLast(tail);

    printList(tail);

}