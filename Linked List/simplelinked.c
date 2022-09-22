/*      We have the linked list.
 
           head         second
             |            |
             |            |
        +---+---+     +---+---+       +----+------+
        | 7  | o----->|  3  | o-----> |  9 | NULL |
        +---+---+     +---+---+       +----+------+
              |
              pointer that 
              points to second
*/


#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *right;  //pointer pointing to the right element
};

typedef struct Node Node;

void printList(struct Node *n){
    while(n!=NULL){
        printf("%d\n",n->data);
        n=n->right;
    }
}

Node *addStart(struct Node *head, int num){    //add node at the front
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=num; //giving number to the data section
    newNode->right=head; //putting the value of old head to the right of new node
    head=newNode; //shifting the head from previous to new head
    return head;
}

void addPos(struct Node* head,int num,int pos){ //add node exactly after the position
    Node *ptr=head;
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=num;
    newNode->right=NULL;
    while(pos>1){
        ptr=ptr->right;
        pos--;
    }
    newNode->right=ptr->right;
    ptr->right=newNode;
}

void addEnd(struct Node *head,int num){  //add node from last
    Node *ptr=head;
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=num;
    newNode->right=NULL;
    while(ptr->right!=NULL){
        ptr=ptr->right;
    }
    ptr->right=newNode;
    
}

void delEnd(struct Node *head){  //remove from last
    if(head==NULL){
        printf("List empty");
    }
    else if(head->right==NULL){  //only one node
        free(head);
        head=NULL;
    }
    else{
        Node *temp=head; 
        Node *temp2=head;
        while(temp->right!=NULL){
            temp2=temp;
            temp=temp->right; //aim is to point temp at the last node and temp2 at the second last node.
        }
        temp2->right=NULL;
        free(temp);
        temp=NULL;
    }
}

void delPos(struct Node **head, int pos){
    Node *prev=*head;  //node previous to the node that is to be removed
    Node *current=*head;  //node to be removed

    if(*head==NULL){
        printf("List empty");
    }
    else if(pos==1){
        *head=current->right;
        free(current);
        current=NULL;
    }
    else{
        while(pos!=1){
            prev=current;
            current=current->right;
            pos--;
        }
        prev->right=current->right;
        free(current);
        current=NULL;
    }
}

struct Node *delStart(struct Node *head){
    if(head==NULL){
        printf("List empty");
    }
    else{
        Node *temp=head;
        head=head->right;
        free(temp);
        temp=NULL;
    }
    return head;
}

void searchdata(struct Node *head, int num){
    Node *temp;
    temp=head;
    while(temp!=NULL){
        if(temp->data==num){
            printf("%d is present in linked list\n", temp->data);
            return;
        }
        else temp=temp->right;
    }
    printf("%d element not found in linked list\n", num);
}

int main(){
    struct Node *head=NULL;
    struct Node *second=NULL;
    struct Node *third=NULL;

    head=(Node*)malloc(sizeof(Node));
    second=(Node*)malloc(sizeof(Node));
    third=(Node*)malloc(sizeof(Node));

    head->data=11;
    head->right=second;
    
    second->data=22;
    second->right=third;

    third->data=33;
    third->right=NULL;

    addEnd(head,77);
    head=addStart(head,44);
    addEnd(head,55);
    addPos(head,66,2);
    addEnd(head,88);

    delEnd(head);
    delPos(&head,4);
    head=delStart(head);
    head=delStart(head);

    printList(head);

    searchdata(head,33);
    searchdata(head,15);
}
