#include <stdio.h>
int queue[100], front = -1, rear = -1;
void enqueue(int v) {
    if (front == -1) front = 0;
    queue[++rear] = v;
}
int dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front == -1 || front > rear;
}
int main() {
    int n, i, j, start;
    int adj[100][100], visited[100] = {0};
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    printf("Enter starting vertex (0 to %d): ", n-1);
    scanf("%d", &start);
    printf("BFS Traversal: ");
    enqueue(start);
    visited[start] = 1;
    while (!isEmpty()) {
        int v = dequeue();
        printf("%d ", v);
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    return 0;
}
