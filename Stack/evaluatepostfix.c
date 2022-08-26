#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<strings.h>

struct ST{
    int top;
    unsigned capacity;
    int *array;
};

typedef struct ST ST;

ST *createStack(unsigned n){
    ST *stack;
    stack=(ST*)malloc(sizeof(ST));
    stack->top=-1;
    stack->capacity=n;
    stack->array=(int*)malloc(sizeof(int));
    return stack;
}

int isEmpty(ST *stack){
    return stack->top==-1;
}

int isFull(ST *stack){
    return stack->top==stack->capacity-1;
}

void push(ST *stack, int a){
    if(!isFull(stack)){
        stack->array[++stack->top]=a;
    }
}

int pop(ST *stack){
    if(!isEmpty(stack)){
        return stack->array[stack->top--];
    }
}

int top(ST *stack){
    if(!isEmpty(stack)){
        return stack->array[stack->top];
    }
    
}

int PtoE(char postfix[], int n){
    ST *stack=createStack(n);
    int n1,n2;

    for(int i=0;i<n;i++){
        
        if(postfix[i]>='0' && postfix[i]<='9'){
            push(stack,postfix[i]-'0');
        }
        else{
            n1=pop(stack);
            n2=pop(stack);
            switch(postfix[i]){
                case '+':
                    push(stack,n2+n1);
                break;
                case '-':
                    push(stack,n2-n1);
                break;
                case '*':
                    push(stack,n2*n1);
                break;
                case '/':
                    push(stack,n2/n1);
                break;
                case '^':
                    push(stack,pow(n2,n1));
                break;
            }
        }
    }
    return pop(stack);
    
}

int main(){
    int n;
    printf("Enter number of characters\n");
    scanf("%d",&n);
    char postfix[n];
    scanf("%s",postfix);
    int result;
    result=PtoE(postfix,n);
    printf("%d",result);
    return 0;
}