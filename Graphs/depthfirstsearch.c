#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

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

//------DFS--------
void DFS(Graph *graph, int vertex){
    node *temp=graph->adjLists[vertex];

    graph->visited[vertex]=1; //visited the vertex
    printf("%d ", vertex);

    while(temp!=NULL){
        int connectedVertex=temp->vertex;

        if(graph->visited[connectedVertex]==0){
            DFS(graph, connectedVertex);
        }
        temp=temp->next;
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

int main() {
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);   
    addEdge(graph, 1, 2);   
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 0);

    printGraph(graph);
    printf("\nDepth first search: ");
    DFS(graph, 0);

    return 0;
}