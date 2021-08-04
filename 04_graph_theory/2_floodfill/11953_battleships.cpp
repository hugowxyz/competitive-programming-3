#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define LOOP(x, s, n, inc) for (int x=s; x<n; x+=inc)

#define vi vector<int>
#define vvi vector<vector<int>>

vector<vector<char>> graph;

int n, cnt, s, d,
    dr[] = {1, -1, 0, 0},
    dc[] = {0, 0, 1, -1};

bool floodfill(int r, int c) {
    if ( r < 0 || c < 0 || r >= n || c >= n ) return 0;
    if ( graph[r][c] == '.' ) return 0; 

    if ( graph[r][c] == '@' ) d++;

    s++;
    graph[r][c] = '.';

    LOOP(k, 0, 4, 1)
        floodfill(r + dr[k], c + dc[k]);

    return s != d;
}

int main() {
    FASTIN

    int t;
    cin >> t;
    LOOP(tc, 1, t+1, 1) {
        cin >> n;
        graph.assign(n, vector<char>(n, ' '));
        LOOP(i, 0, n, 1) 
            LOOP(j, 0, n, 1) 
                cin >> graph[i][j];

        cnt = 0;
        LOOP(i, 0, n, 1) {
            LOOP(j, 0, n, 1) {
                if ( graph[i][j] == 'x' ) {
                    s = d = 0;
                    if ( floodfill(i, j) ) 
                        cnt++;
                }
            }
        }

        cout << "Case " << tc << ": " << cnt << "\n";
    }

    return 0;
}