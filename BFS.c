#include <stdio.h>
#define MAX 100

int adj[MAX][MAX], visited[MAX], queue[MAX], front = -1, rear = -1;

void bfs(int start, int n) {
    int i, current;
    for (i = 0; i < n; i++) visited[i] = 0;
    queue[++rear] = start;
    front = 0;
    visited[start] = 1;

    printf("BFS Traversal: ");
    while (front <= rear) {
        current = queue[front++];
        printf("%d ", current);
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int n, i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    bfs(0, n);
    return 0;
}