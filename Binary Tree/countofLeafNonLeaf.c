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

int countofLeafNode(Node *root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    else return countofLeafNode(root->left)+countofLeafNode(root->right);
}

int countofNONLeafNodes(Node *root){
    if((root==NULL) || (root->left==NULL && root->right==NULL)){
        return 0;
    }
    else return 1+countofNONLeafNodes(root->left)+countofNONLeafNodes(root->right);
}

int countofNodes(Node *root){
    int count=1; //Node itself should be counted
    if(root==NULL){
        return 0;
    }
    else{
        count=count+countofNodes(root->left);
        count=count+countofNodes(root->right);
        return count;
    }
}

int maxDepth(Node *root){
    if(root==NULL){
        return -1;
    }
    else{
        //find depth of each subtree
        int lDepth=maxDepth(root->left);
        int rDepth=maxDepth(root->right);

        //use larger one
        if(lDepth>rDepth){
            return (lDepth+1);
        }
        else return (rDepth+1);
    }
}

void inOrder(Node *root){
    
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main(){
    Node *p = createNode(4);
    Node *p1 = createNode(1);
    Node *p2 = createNode(6);
    Node *p3 = createNode(5);
    Node *p4 = createNode(2);
    Node *p5=createNode(7);
    Node *p6=createNode(8);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right=p5;
    p4->left=p6;

    // Finally The tree looks like this:
    //      4
    //     / \
    //    1   6
    //   / \   \
    //  5   2   7 
    //     /
    //    8

    inOrder(p);
    printf("\n");
    int a,b,c,d;
    a=countofNodes(p);
    b=countofLeafNode(p);
    c=countofNONLeafNodes(p);
    d=maxDepth(p);

    printf("Node count: %d  Leaf Count: %d  Non Leaf count: %d  Height: %d", a,b,c,d);
}


