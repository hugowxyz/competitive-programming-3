#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

bool f=0;
int R, C, M, N;
vector<vector<int>> graph, visited;

void dfs(int r, int c, int *dr, int *dc) {
    if ( (r == 0 && c == 0 && visited[r][c]) || visited[r][c] ) {
        graph[r][c]++;
        return;
    }

    visited[r][c] = 1;
    graph[r][c]++;

    set<pair<int, int>> s;

    for (int k=0; k<8; k++) {
        int i = r + dr[k],
            j = c + dc[k];

        if ( s.count({i, j}) == 0 ) {
            s.insert({i, j});

            if ( i >= 0 && j >= 0 && i < R && j < C && graph[i][j] != -1 ) {
                dfs(i, j, dr, dc);
            }
        }
    }      
} 

int main() {
    FASTIN
    
    int t, 
        m ,n,
        w, x, y;

    cin >> t;
    for (int tc=0; tc<t; tc++) {
        cin >> R >> C >> M >> N >> w;
        graph.assign(R, vector<int>(C, 0));
        visited.assign(R, vector<int>(C, 0));
        int dr[] = {M, -M, M, -M, N, -N, N, -N},
            dc[] = {N, N, -N, -N, M, M, -M, -M};

        while (w--) {
            cin >> x >> y;
            graph[x][y] = -1;
        }
        
        graph[0][0] = -1;
        dfs(0, 0, dr, dc);

        int odd=0, even=0;
        for (int i=0; i<R; i++) {
            for (int j=0; j<C; j++) {
                if ( (graph[i][j] > 0) || (i == 0 && j == 0) ) {
                    if ( graph[i][j] & 1 ) odd++;
                    else even++;
                }
            }
        }

        cout << "Case " << tc+1 << ": " << even << " " << odd << "\n";
    }

    return 0;
}