#include<stdio.h>
#include<stdlib.h>

#define MAX_NODES 10

int cost[MAX_NODES][MAX_NODES];
int n;

// Function prototypes for Kruskal's algorithm
void kruskal();
int find(int parent[], int i);
void unionn(int parent[], int x, int y);

int main() {
    int i, j;
 
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = 999;
        }
    }

    printf("\nKruskal's Algorithm:\n");
    kruskal();

    printf("PRATIKSHA MEHTA \n6009220172 \nD087\n");
    return 0;
}

void kruskal() {
    int parent[MAX_NODES];
    int i, j, a, b, u, v;
    int ne = 1;
    int mincost = 0;

    // Initialize parent array
    for (i = 1; i <= n; i++)
        parent[i] = 0;

    while (ne < n) {
        int min = 999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(parent, u);
        v = find(parent, v);

        if (u != v) {
            printf("%d edge (%d,%d) =%d\n", ne++, a, b, min);
            mincost += min;
            unionn(parent, u, v);
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Kruskal's Minimum Spanning Tree:\n");
    printf("Total minimum cost: %d\n", mincost);
}

int find(int parent[], int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

void unionn(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}
