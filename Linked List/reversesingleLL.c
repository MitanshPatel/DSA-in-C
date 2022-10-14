#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;  //pointer pointing to the next element
};

typedef struct Node Node;

void printList(struct Node *n){
    while(n!=NULL){
        printf("%d\n",n->data);
        n=n->next;
    }
    printf("\n");
}

Node *addStart(struct Node *head, int num){    //add node at the front
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=num; 
    newNode->next=head; 
    head=newNode; 
    return head;
}

Node *reverse(Node *head){
    //position of head node will be changed multiple times to reverse the linked list
    Node *temp=NULL;  //points to prev node of head
    Node *temp2=NULL; //points to next node of head

    while(head!=NULL){
        temp2=head->next;  //assigning temp2 as next node of head
        head->next=temp;  // temp is prev node of head. so this line reverses the list
        temp=head;  //temp goes one node ahead towards head
        head=temp2;  //head goes one node ahead towards temp2. And temp2 goes one node ahead in first line of while loop
    }
    head=temp;  //head becomes NULL at end. but temp still remains as prev node. so temp becomes new head or first element of LL
    return head;
}

int main(){
    Node *head=NULL;
    head=addStart(head,11);
    head=addStart(head,22);
    head=addStart(head,33);
    head=addStart(head,44);
    printList(head);

    head=reverse(head);
    printList(head);
}