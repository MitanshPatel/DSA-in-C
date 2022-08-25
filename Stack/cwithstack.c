//Last in First out

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct STACK{
    int top; // position of the last element of stack
    unsigned capacity; // how big should the stack be
    int *array; //dynamic array in which all elements of stack will be stored
};

typedef struct STACK STACK; //struct STACK is the variable which may be replaced to only STACK.

STACK *createStack(unsigned n) // STACK is written first so that the function createStack can return stack
{
    STACK *stack;  
    stack=(STACK*)malloc(sizeof(STACK));
    stack->top = -1;    // top in stack is being pointed and is given -1 as default value.
    stack->capacity = n;
    stack->array = (int*)malloc(sizeof(int));
    return stack;
}

int isFULL(STACK *stack)
{
    return stack ->top == stack ->capacity -1; //if the position of the top is equal to capacity assigned by user, then stack is full

}

int isEMPTY(STACK *stack)
{
    return stack ->top == -1; //top has default value of -1 specified in struct STACK
}

void PUSH(STACK *stack, int item) // item is number given by user to be pushed in the stack
{
    if (isFULL(stack))
    {
        printf("Cannot add anymore items in the stack\n");
    }

    else{
        stack ->array[++stack ->top]=item; // ++(stack ->top) is incremented first
        printf("%d is pushed in the stack in %d position\n",item,stack->top);
    }

}

void POP(STACK *stack)
{
    if(isEMPTY(stack)){
        printf("No items there to remove\n");
    }

    else{
        stack ->array[stack ->top--];
        printf("%d has been removed from the stack.top position\n",stack->array[stack->top +1]);

    }
}

void TOP(STACK *stack)
{
    printf("%d is the stack.top item in the stack\n",stack->array[stack->top]);
}

int main()
{
    int n;
    printf("Enter the size of the stack\n");
    scanf("%d",&n);
    STACK *stack = createStack(n);

    //taking elements in the stack
    for (int i=0; i<n; i++){
        int item;
        printf("Enter element %d to be pushed in the stack\n", i+1);
        scanf("%d",&item);
        PUSH(stack,item);
    }
    POP(stack);
    POP(stack);
    PUSH(stack,103);

    //printing all elements in the stack
    printf("\nBelow are all the elements of the stack\n");
    for (int i=0; i<n ; i++)
    {
        printf( "%d \n", stack->array[i]);
    }
}

// NOTE : if the user pops an element then the top element doesnt get removed fron the stack it stays there, but the stack is then considered from top-1 element.
// NOTE : if user pops element and then pushes 53, then the element which is popped gets overwritten and edited to 53
