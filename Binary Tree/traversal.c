#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

Node *createNode(int n){
    Node *newNode;
    newNode=(Node*)malloc(sizeof(Node));
    newNode->data=n;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void preOrder(Node *root){
    
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root){
    
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void postOrder(Node *root){
    
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

int main(){
    Node *p = createNode(4);
    Node *p1 = createNode(1);
    Node *p2 = createNode(6);
    Node *p3 = createNode(5);
    Node *p4 = createNode(2);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \
    //  5   2  
    printf("\nPreorder: ");
    preOrder(p);

    printf("\nInorder: ");
    inOrder(p);

    printf("\nPostorder: ");
    postOrder(p);
    return 0;
}