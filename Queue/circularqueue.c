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

void enqueue(Q *queue, int num){
    if((queue->front==0 && queue->rear==queue->size-1) || (queue->rear==queue->front-1)){
        printf("\nQueue is full");
        return;
    }
    else if(queue->front==-1 || queue->rear==-1){
        queue->front=queue->rear=0;
    }
    else if(queue->rear==queue->size-1 && queue->front!=0){
        queue->rear=0; 
    }
    else{
        queue->rear++;  
    }
    queue->array[queue->rear]=num;
    printf("\n%d is added in the queue",queue->array[queue->rear]);
}

void dequeue(Q *queue){
    if(queue->front==-1){
        printf("\nQueue is Empty");
    }
    if(queue->front!=-1){
        printf("\n%d has been removed from queue",queue->array[queue->front]);
    }
    if(queue->front==queue->rear){
        queue->front=-1;
        queue->rear=-1;
    }
    else if(queue->front==queue->size-1){
        queue->front=0;
    }
    else queue->front++;
}

void extractfront(Q *queue){
    if(queue->front==-1){
        printf("\nQueue is empty");
    }
    else{
        printf("\n%d is the first element", queue->array[queue->front]);
    }
}

void extractrear(Q *queue){
    if(queue->front==-1){
        printf("\nQueue is Empty");
    }
    else{
        printf("\n%d is the last element", queue->array[queue->rear]);
    }
}

void displayQueue(Q *queue){
    if(queue->front==-1 && queue->rear==-1){
        printf("Queue is Empty\n");
    }
    printf("\n\nBelow are elements of queue\n");
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
    enqueue(queue,45);
    enqueue(queue,72);
    enqueue(queue,87);
    enqueue(queue,23);
    displayQueue(queue);
    dequeue(queue);
    enqueue(queue,555);
    displayQueue(queue);
    enqueue(queue,7777);
    displayQueue(queue);

}
