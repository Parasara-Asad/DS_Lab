#include <stdio.h>

void dfs(int node, int n, int adj[n][n], int visited[n]) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, n, adj, visited);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int w[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &w[i]);
        }
        
        int adj[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adj[i][j] = 0;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((j + 1) - (i + 1) != w[j] - w[i]) {
                    adj[i][j] = 1;
                    adj[j][i] = 1;
                }
            }
        }
        
        int visited[n];
        for (int i = 0; i < n; i++) {
            visited[i] = 0;
        }
        
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, n, adj, visited);
                components++;
            }
        }
        
        printf("%d\n", components);
    }
    return 0;
}
