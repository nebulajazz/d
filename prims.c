#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 10
#define INF 999

int cost[MAX_NODES][MAX_NODES];
int n;

void prim(int graph[MAX_NODES][MAX_NODES]) {
    int parent[MAX_NODES];
    int key[MAX_NODES];
    bool mstSet[MAX_NODES];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;     
    parent[0] = -1; 

    //for all vertices, finding minimum and storing in ans

    for (int count = 0; count < n - 1; count++) {

        //finding minimum cost 

        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!mstSet[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        mstSet[u] = true;

        //drawing graph

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edge   Weight\n");
    for (int i = 1; i < n; i++) {
        printf("%d - %d    %d \n", parent[i]+1, i+1, graph[i][parent[i]]);
    }
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\nPrim's Algorithm:\n");
    prim(cost);

    return 0;
}
