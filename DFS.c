#include <stdio.h>
int n;
int adj[100][100];
int visited[100] = {0};
void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i])
            dfs(i);
    }
}
int main() {
    int i, j;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    dfs(0);
    int connected = 1;
    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }
    if (connected)
        printf("Graph is CONNECTED.\n");
    else
        printf("Graph is NOT connected.\n");
    return 0;
}
