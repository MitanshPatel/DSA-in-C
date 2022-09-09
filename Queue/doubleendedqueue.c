#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Q{
    int front;
    int rear;
    int size;
    int *array;
};

typedef struct Q Q;

Q *createQueue (int n)
{
    Q *queue;
    queue=(Q*)malloc(sizeof(Q));
    queue -> front=-1;
    queue -> size=n;
    queue -> rear=-1;
    queue ->array=(int*)malloc(n*sizeof(int));
    return queue;
};

int isEmpty(Q *queue){
    return (queue->front==-1 || queue->rear==-1);
}

int isFull(Q *queue){
    return ((queue->front==0 && queue->rear==queue->size-1) || (queue->front==queue->rear+1));
}

void enqueueF(Q *queue, int num){
    if(isFull(queue)){
        printf("\nQueue is Full");
        return;
    }

    if(queue->front==-1 || queue->rear==-1){
        queue->front=queue->rear=0;
    }

    else if(queue->front==0){
        queue->front=queue->size-1;
    }

    else queue->front-=1;
    queue->array[queue->front]=num;
    printf("\n%d is added to queue from front",queue->array[queue->front]);
}

void enqueueR(Q *queue, int num){
    if(isFull(queue)){
        printf("\nQueue is Full");
        return;
    }

    if(queue->front==-1 && queue->rear==-1){
        queue->front=queue->rear=0;
    }

    else if(queue->rear==queue->size-1){
        queue->rear=0;
    }

    else queue->rear++;
    queue->array[queue->rear]=num;
    printf("\n%d is added to queue from rear",queue->array[queue->rear]);

}

void dequeueF(Q *queue){
    if(isEmpty(queue)){
        printf("\nQueue is Empty");
        return;
    }

    printf("\n%d is dequeued from front",queue->array[queue->front]);


    if(queue->rear==queue->front){
        queue->rear=queue->front=-1;
    }

    else if(queue->front==queue->size-1){
        queue->front=0;
    }

    else queue->front+=1;
}

void dequeueR(Q *queue){
    if(isEmpty(queue)){
        printf("\nQueue is Empty");
        return;
    }

    printf("\n%d is dequeued from rear",queue->array[queue->rear]);

    if(queue->rear==queue->front){
        queue->rear=queue->front=-1;
    }

    else if(queue->rear==0){
        queue->rear=queue->size-1;
    }

    else queue->rear-=1;
}

void getfront(Q *queue){
    if(isEmpty(queue)){
        printf("\nQueue is Empty");
        return;
    }

    else printf("\n%d is front element of queue",queue->array[queue->front]);
}

void getrear(Q *queue){
    if(isEmpty(queue)){
        printf("\nQueue is Empty");
        return;
    }

    else printf("\n%d is the rear element of the queue ",queue->array[queue->rear]);
}

void displayQueue(Q *queue){
    if(isEmpty(queue)){
        printf("\nQueue is Empty");
        return;
    }
    printf("\n\nBelow are elements of queue \n");

    if(queue->rear>=queue->front){
        if(queue->rear!=-1 && queue->front!=-1){
            for(int i=queue->front;i<=queue->rear;i++){
                printf("%d ",queue->array[i]);
            }
        }
    }
    else{
        for(int i=0; i<=queue->rear; i++){
                printf("%d ",queue->array[i]);
            }
            for(int i=queue->front; i<queue->size; i++){
                printf("%d ",queue->array[i]);
            }
    }
}


int main(){
    Q *queue=createQueue(4);
    enqueueF(queue,45);
    enqueueR(queue,72);
    enqueueR(queue,87);
    enqueueF(queue,12);
    displayQueue(queue);
    enqueueR(queue,33);
    dequeueF(queue);
    dequeueF(queue);
    dequeueF(queue);
    displayQueue(queue);
}