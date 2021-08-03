#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

vector<vector<char>> graph;

// . = outside/inside visited
// - = glyph edge visited

int h, w;

int dr[] = {1, -1, 0, 0, 1, -1, 1, -1},
    dc[] = {0, 0, 1, -1, 1, 1, -1, -1};

char glyphs[] = {'W', 'A', 'K', 'J', 'S', 'D'};

bool inside;
int cnt;

void floodfill(int, int);

void dfs(int r, int c) {
    if ( r >= h || c >= w*4 || r < 0 || c < 0 ) return;
    
    if ( graph[r][c] == '0' ) {
        inside=1;
        floodfill(r, c);
        if (inside) cnt++;
        return;
    }  

    if ( graph[r][c] == '.' || graph[r][c] == '-' ) return;

    graph[r][c] = '-';

    for (int i=0; i<8; i++)
        dfs(r + dr[i], c + dc[i]);
}

void floodfill(int r, int c) {
    if ( r >= h || c >= w*4 || r < 0 || c < 0 ) {
        inside = 0;
        return;
    }
    if ( graph[r][c] == '.' || graph[r][c] == '-' || graph[r][c] == '1' ) return;

    graph[r][c] = '.';

    for (int i=0; i<8; i++)
        floodfill(r + dr[i], c + dc[i]);
}

int main() {
    FASTIN

    char c;
    int d, tc=1;
    while ( cin >> h >> w && (h || w) ) {
        graph.assign(h, {});

        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                cin >> c;
                
                if ( isdigit(c) ) 
                    d = c-'0';
                else 
                    d = c-'a' + 10;

                for (int k=3; k>=0; k--) {
                    if ( pow(2, k) <= d ) {
                        graph[i].push_back('1');
                        d -= pow(2, k);
                    } else {
                        graph[i].push_back('0');
                    }
                }
            }
        }

        vector<char> ans;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w*4; j++) {
                if ( graph[i][j] == '1' ) {
                    cnt = 0;
                    dfs(i, j);
                    ans.push_back(glyphs[cnt]);
                }
            }
        }

        sort(ans.begin(), ans.end());

        cout << "Case " << tc++ << ": ";
        for (auto i : ans) cout << i;
        cout << "\n";
    }

    return 0;
}