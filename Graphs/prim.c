#include <stdio.h>
#define MAX 9999
int a, b, u, v, i, j; //all used for traversal
int n,ne = 1;  //n=num of vertices  ne=num of edges
int visited[100] = {0};
int min=MAX;
int mincost = 0;  //final min distance
int cost[100][100]; //input adjacency matrix
void main(){
    printf("\nEnter the number of nodes:");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");

    for (i = 0; i < n; i++){  //take input
        for (j = 0; j < n; j++){
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0){  //if two nodes are not connected, make it infinity
                cost[i][j] = MAX;
            }
        }
    }

    visited[0] = 1;  //making 0 as visited
    printf("\n");

    while (ne < n){  //num of edges should be one less than num of vertices in min spanning tree, initially ne=1
        min=MAX;
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                if (cost[i][j] < min){
                    if (visited[i] != 0){
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0){  //if one of the nodes is not connected, then an edge can be drawn between them. if both 1 then edge cannot be drawn
            ne++; //node added
            printf("\n Edge %d:(%d %d) cost:%d", ne, a, b, min);
            mincost += min;
            visited[b] = 1;
        }

        cost[a][b] = cost[b][a] = MAX;  //once the weight is used in prim, it is changed to MAX in adjacency list
    }
    printf("\n Minimun cost=%d", mincost);
}