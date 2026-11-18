#include <stdio.h>
#define MAX 100

int adj[MAX][MAX], visited[MAX], n;

void dfs(int current) {
    int i;
    visited[current] = 1;
    printf("%d ", current);
    for (i = 0; i < n; i++) {
        if (adj[current][i] == 1 && !visited[i])
            dfs(i);
    }
}

int main() {
    int i, j, start;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    for (i = 0; i < n; i++) visited[i] = 0;
    printf("Enter starting vertex: ");
    scanf("%d", &start);
    printf("DFS Traversal: ");
    dfs(start);
    printf("\n");
    return 0;
}