#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//------QUEUE--------
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

int dequeue(Q *queue){
    if(isEmpty(queue)){
        printf("\nQueue is Empty\n");
        return -1;
    }
    int dequeued=queue->array[queue->front];
    if(queue->front==queue->rear){
        queue->front=-1;
        queue->rear=-1;
        return dequeued;
    }
    queue->front++;
    return dequeued;

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

//-------NODE--------
struct node{
    int vertex;
    struct node* next;
};

typedef struct node node;

node* createNode(int v){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->vertex=v;
    newNode->next=NULL;
    return newNode;
}

//--------GRAPH---------
struct Graph{
    int numVertices;  //number of vertices in graph
    struct node** adjLists;  //collection of nodes connected that starts from all the vertices that are connected to parent vertex and ends with parent vertex itself
    int *visited;
};

typedef struct Graph Graph;

Graph* createGraph(int vertices){
    Graph *graph=(Graph*)malloc(sizeof(Graph));
    graph->numVertices=vertices;
    graph->adjLists=malloc(vertices*sizeof(node)); //collections of nodes and node itself is a collection so ** is used in struct Graph
    graph->visited=malloc(vertices*sizeof(int));

    for(int i; i<vertices; i++){
        graph->adjLists[i]=NULL;
        graph->visited[i]=0; 
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest){  //src is source and dest is destination
    // Add edge from src to dest
    node *newNode=createNode(dest);
    newNode->next=graph->adjLists[src];
    graph->adjLists[src]=newNode;

    //Add edge fronm dest to src
    newNode=createNode(src);
    newNode->next=graph->adjLists[dest];
    graph->adjLists[dest]=newNode;
}

//------BFS--------
void bfs(Graph *graph, int startVertex){
    int nV=graph->numVertices;
    Q *q=createQueue(nV);

    graph->visited[startVertex]=1; //1 means the vertex is visited and printed already
    enqueue(q, startVertex);

    printf("\nBreadth first search: ");
    while(!isEmpty(q)){
        //printQueue(q);  //optional to print, to see what queue contains
        int currentVertex=dequeue(q); //current vertex is next vertex to be visited
        printf("%d ",currentVertex);

        node *temp=graph->adjLists[currentVertex]; //temp contains all the vertices connected to current vertex
        while(temp){
            int adjVertex=temp->vertex;  //data of node

            if(graph->visited[adjVertex]==0){  //if the vertice is still unvisited
                graph->visited[adjVertex]=1; // it is visited now 
                enqueue(q, adjVertex); 
            }
            temp=temp->next;
        }
    } 
}

void printGraph(Graph *graph){
    for(int v=0; v < graph->numVertices; v++){
        node *temp=graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);

        while(temp){
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main(){
    struct Graph* graph = createGraph(5);  // visited={0,0,0,0,0}
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);   //adjList[0]= 2 -> 1 -> 0
    addEdge(graph, 1, 2);   //adjList[1]= 3 -> 4 -> 2 -> 0 -> 1
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 0);

    bfs(graph, 0);
    printf("\n\n");
    //printGraph(graph);
    return 0;
    
}

