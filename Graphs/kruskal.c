#include<stdio.h>

#define MAX 100

struct edge{
    int u;  //source
    int v;  //destinatiom
    int w;  //weight
};

typedef struct edge edge;

struct edge_list{
    edge data[MAX];
    int n;  //number of edge data[] present 
};

typedef struct edge_list edge_list;

//----Global variable----
edge_list elist;  //contains all edges and weights
int Graph[MAX][MAX];  //adjacency matrix of graph
int n;  //n is number of vertices 
edge_list spanlist;  //contains edges with least weight


void sort(){  //to sort edges from ascending to descending order acc to weights and store it in elist
    for (int i = 1; i < elist.n; i++){   //i starts with 1 as two or more nodes are only from elist.2 required to sort and compare
        for (int j = 0; j < elist.n - 1; j++){
            if (elist.data[j].w > elist.data[j + 1].w) {
                edge temp = elist.data[j];
                elist.data[j] = elist.data[j + 1];
                elist.data[j + 1] = temp;
            }
        }
    }
}

int find(int belongs[], int vertexno) {
    return (belongs[vertexno]);
}

void applyUnion(int belongs[], int c1, int c2) {
    for (int i = 0; i < n; i++){  //connecting 1 - 0 belong={0,1,2,3,4,5} initially becomes belong={1,1,2,3,4,5}
        if (belongs[i] == c2){
            belongs[i] = c1;
        }
    }
}

void kruskalAlgo() {
    int belongs[MAX], i, j, cno1, cno2;
    elist.n = 0;

    for (i = 0; i < n; i++){  //n=total vertices in main graph
        for (j = 0; j < i; j++) {  //scans only lower triangle matrix of Graph[i][j]
            if (Graph[i][j] != 0) {
                elist.data[elist.n].u = i;
                elist.data[elist.n].v = j;
                elist.data[elist.n].w = Graph[i][j];
                elist.n++;
            }
        }
    }

    sort();

    for (i = 0; i < n; i++){  //belongs={0,1,2,3,4,5}  (n=total vertices in mmain graph)
        belongs[i] = i;
    }

    spanlist.n = 0;

    for (i = 0; i < elist.n; i++) {
        cno1 = find(belongs, elist.data[i].u);
        cno2 = find(belongs, elist.data[i].v); 

        if (cno1 != cno2) {   //if same, they are already connected in graph
            spanlist.data[spanlist.n] = elist.data[i];
            spanlist.n = spanlist.n + 1;  //first edge of min. spanning tree is selected, so increase n by 1
            applyUnion(belongs, cno1, cno2);
        }
    }
}

void print() {
    int i, cost = 0;

    for (i = 0; i < spanlist.n; i++) {
        printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
        cost = cost + spanlist.data[i].w;
    }

    printf("\nSpanning tree cost: %d", cost);
}

int main() {
    printf("\nEnter number of vertices:");
    scanf("%d",&n);

    printf("\nEnter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&Graph[i][j]);
        }
    }
    // int,i,j,total_cost;
    // n = 6;

    // Graph[0][0] = 0;
    // Graph[0][1] = 4;
    // Graph[0][2] = 4;
    // Graph[0][3] = 0;
    // Graph[0][4] = 0;
    // Graph[0][5] = 0;
    // Graph[0][6] = 0;

    // Graph[1][0] = 4;
    // Graph[1][1] = 0;
    // Graph[1][2] = 2;
    // Graph[1][3] = 0;
    // Graph[1][4] = 0;
    // Graph[1][5] = 0;
    // Graph[1][6] = 0;

    // Graph[2][0] = 4;
    // Graph[2][1] = 2;
    // Graph[2][2] = 0;
    // Graph[2][3] = 3;
    // Graph[2][4] = 4;
    // Graph[2][5] = 2;
    // Graph[2][6] = 0;

    // Graph[3][0] = 0;
    // Graph[3][1] = 0;
    // Graph[3][2] = 3;
    // Graph[3][3] = 0;
    // Graph[3][4] = 3;
    // Graph[3][5] = 0;
    // Graph[3][6] = 0;

    // Graph[4][0] = 0;
    // Graph[4][1] = 0;
    // Graph[4][2] = 4;
    // Graph[4][3] = 3;
    // Graph[4][4] = 0;
    // Graph[4][5] = 0;
    // Graph[4][6] = 0;

    // Graph[5][0] = 0;
    // Graph[5][1] = 0;
    // Graph[5][2] = 2;
    // Graph[5][3] = 0;
    // Graph[5][4] = 3;
    // Graph[5][5] = 0;
    // Graph[5][6] = 0;

    kruskalAlgo();
    print();
}