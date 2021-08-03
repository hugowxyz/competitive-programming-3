#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

#define N 100

int n;
int visited[N], c[N], reachable[N];
int graph[N][N];
char dominates[N][N];

void dfs(int u) {
    visited[u] = 1;
    for (int v=0; v<n; v++) {
        if (graph[u][v] && !visited[v]) dfs (v);    
    }
}

int main() {
    FASTIN

    int tc;
    cin >> tc;

    for (int cse=1; cse<=tc; cse++) {
        cin >> n;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                cin >> graph[i][j];

        dfs(0);
        copy(visited, visited+n, reachable);
        memset(visited, 0, sizeof(int) * n);

        for (int i=0; i<n; i++) {
            copy(graph[i], graph[i]+n, c);
            memset(graph[i], 0, sizeof(int) * N);
            dfs(0);
            copy(c, c+n, graph[i]);

            for (int j=0; j<n; j++)
                dominates[i][j] = !reachable[j] || (i != j && visited[j]) ? 'N' : 'Y';

            memset(visited, 0, sizeof(int) * N);
        }

        cout << "Case " << cse << ":\n+";
        for (int i=0; i<2*n-1; i++ ) cout << "-";
        cout << "+\n";
        for (int i=0; i<n; i++) {
            cout << "|";
            for (int j=0; j<n; j++) 
                cout << dominates[i][j] << "|";
            cout << "\n+";
            for (int i=0; i<2*n-1; i++) cout << "-";
            cout << "+\n";
        }

        memset(graph, 0, sizeof(int) * N * N);
    }
    
    return 0;
}