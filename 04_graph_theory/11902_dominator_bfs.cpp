#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

#define N 100

int main() {
    FASTIN
    
    int t, n, 
        visited[N], reachable[N],
        graph[N][N];
    queue<int> q;
    
    cin >> t;
    for (int tc=0; tc<t; tc++) {
        cin >> n;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                cin >> graph[i][j];

        q.push(0); visited[0] = 1;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            reachable[u] = 1;
            for (int v=0; v<n; v++)
                if (!visited[v] && graph[u][v]) 
                    q.push(v), visited[v] = visited[u] + 1;
        }

        // Not finishing implementation because it's probably
        // going to be the same as DFS
    }

    return 0;
}