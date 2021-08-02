#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

bitset<50001> visited;
vector<int> graph, finished;

int cnt;

void dfs(int u) {
    visited[u] = 1;
    cnt++;
    
    if ( !visited[graph[u]] ) 
        dfs(graph[u]);
    
    visited[u] = 0;
    finished[u] = cnt;
}

int main() {
    FASTIN

    int t, n, a, b;
    cin >> t;
    
    for (int tc=0; tc<t; tc++) {
        cin >> n;

        graph.assign(n+1, 0);
        finished.assign(n+1, 0);

        while (n--) {
            cin >> a >> b;
            graph[a] = b;
        }

        int ans, mx=-1;
        for (int i=1; i<graph.size(); i++) {
            if ( finished[i] ) continue;
            cnt = 0;

            dfs(i);
            if ( cnt > mx )
                ans = i, mx = cnt;

        }

        cout << "Case " << tc+1 << ": " << ans << "\n";
    }
    
    return 0;
}
