#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<strings.h>

struct ST{
    int top;
    unsigned capacity;
    char *array;
};

typedef struct ST ST;

ST *createStack(unsigned n){
    ST *stack;
    stack=(ST*)malloc(sizeof(ST));
    stack->top=-1;
    stack->capacity=n;
    stack->array=(char*)malloc(sizeof(char));
    return stack;
}

int isEmpty(ST *stack){
    return stack->top==-1;
}

int isFull(ST *stack){
    return stack->top==stack->capacity-1;
}

void push(ST *stack, char a){
    if(!isFull(stack)){
        stack->array[++stack->top]=a;
    }
}

char pop(ST *stack){
    if(!isEmpty(stack)){
        return stack->array[stack->top--];
    }
}

char top(ST *stack){
    if(!isEmpty(stack)){
        return stack->array[stack->top];
    }
    
}

int precedence(char o){
    switch(o){
        case '^':
            return 3;
        break;

        case '/':
            return 2;
        case '*':
            return 2;
        break;

        case '+':
            return 1;
        case '-':
            return 1;
        break;
    }
    return -1;
}

int isOperand(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch>='0' && ch<='9');
}

char *ItoP(char infix[], int n){
    char *postfix;
    postfix=(char*)malloc(sizeof(char)*n);
    char symbol;
    int j=0;
    ST *stack=createStack(n);

    for(int i=0;i<n;i++){
        symbol=infix[i];
        if(isOperand(symbol)){
            postfix[j++]=symbol;
        }
        else if(symbol=='('){
            push(stack,symbol);
        }
        else if(symbol==')'){
            while((!isEmpty(stack) && top(stack)!='(')){
                postfix[j++]=pop(stack);
            }
            pop(stack);
        }
        else{
            while((!isEmpty(stack)) && precedence(symbol)<=precedence(top(stack))){
                postfix[j++]=pop(stack);
            }
            push(stack,symbol);
        }
    }

    while(!isEmpty(stack)){
        postfix[j++]=pop(stack);
    }

    postfix[j++]='\0';

    return postfix;
}

int main(){
    int n;
    printf("Enter number of characters\n");
    scanf("%d",&n);
    char infix[n];
    scanf("%s",infix);
    char* result;
    result=ItoP(infix,n);
    printf("%s",result);
    return 0;
}