#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define LOOP(x, s, n, inc) for (int x=s; x<n; x+=inc)

vector<vector<char>> graph;

int M, N, cnt,
    dr[] = {1, -1, 0, 0},
    dc[] = {0, 0, 1, -1};

char land;

void floodfill(int r, int c) {
    if ( r < 0 || r >= M ) return;

    if ( c < 0 ) c = N-1; 
    if ( c >= N ) c = 0;

    if ( graph[r][c] != land ) return;

    cnt++;
    graph[r][c] = land-1;

    for (int k=0; k<4; k++)
        floodfill(r + dr[k], c + dc[k]);
}

int main() {
    FASTIN

    int x, y, mx;

    while (cin >> M >> N) {
        graph.assign(M, vector<char>(N, ' '));
        LOOP(i, 0, M, 1) {
            LOOP(j, 0, N, 1) {
                cin >> graph[i][j];
            }
        }

        cin >> x >> y;
        land = graph[x][y];
        floodfill(x, y);

        mx=0;
        LOOP(i, 0, M, 1) {
            LOOP(j, 0, N, 1) {
                if ( graph[i][j] != land ) continue;
                cnt = 0;
                floodfill(i, j);
                mx = max(mx, cnt);
            }
        }

        cout << mx << "\n";
        cin.ignore();
    }
    
    return 0;
}