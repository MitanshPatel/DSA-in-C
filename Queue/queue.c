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

// Q *createQueue (int n)
// {
//     Q *queue;
//     queue=(Q*)malloc(sizeof(Q));
//     queue -> front=-1;
//     queue -> size=n;
//     queue -> rear=-1;
//     queue ->array=(int*)malloc(n*sizeof(int));
//     return queue;
// };

int isFull(Q *queue){
    return (queue->rear==queue->size-1);
}

int isEmpty(Q *queue){
    return (queue->front==-1 || queue->rear==-1);
}

void enqueue(Q *queue, int num){
    if(isFull(queue)){
        printf("\nQueue is Full\n");
        return;
    }
    else if(queue->rear==-1){
        queue->front=0;
    }
    queue->rear++;
    queue->array[queue->rear]=num;
    return;
}

void dequeue(Q *queue){
    if(isEmpty(queue)){
        printf("\nQueue is Empty\n");
        return;
    }
    else if(queue->front==queue->rear){
        queue->front=-1;
        queue->rear=-1;
        return;
    }
    queue->front++;

}

void extractfront(Q *queue){
    if(isEmpty(queue)){
        printf("\nQueue is empty\n");
    }
    else{
        printf("\n%d is the first element", queue->array[queue->front]);
    }
}

void extractrear(Q *queue){
    if(isEmpty(queue)){
        printf("\nQueue is Empty\n");
    }
    else{
        printf("\n%d is the last element", queue->array[queue->rear]);
    }
}

void displayQueue(Q *queue){
    if(isEmpty(queue)){
        printf("\nQueue is empty\n");
        return;
    }
    printf("\nBelow elements in queue\n");
    for(int i=queue->front;i<queue->size;i++){
        printf("%d ",queue->array[i]);
    }
}

int main(){
    struct Q queue;
    queue.size = 4;
    queue.front = queue.rear = -1;
    queue.array = (int*) malloc(queue.size*sizeof(int));
    //Q *queue=createQueue(4);
    enqueue(&queue,45);
    enqueue(&queue,72);
    enqueue(&queue,87);
    enqueue(&queue,23);
    displayQueue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    displayQueue(&queue);
}
