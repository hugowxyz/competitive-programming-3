#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    FASTIN

    char t, dirs[] = {'N', 'S', 'L', 'O'};
    int n, m, s, idx;
    vector<string> graph;
    pair<int, int> pos, orientation;

    int ia[] = {-1, 1, 0, 0},
        ja[] = {0, 0, 1, -1};

    while (cin >> n >> m >> s && n) {
        graph.assign(n, string(m, '.'));

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> t;
                graph[i][j] = t;
                for (int k=0; k<4; k++) {
                    if (t == dirs[k]) {
                        pos = {i, j};
                        orientation = {ia[k], ja[k]};
                        break;
                    } 
                }   
            }
        }

        int answer = 0;
        while (s--) {
            cin >> t;
            if (t == 'F') {
                int i = pos.first + orientation.first,
                    j = pos.second + orientation.second;

                if ( i >= n || j >= m || i < 0 || j < 0 )
                    continue;

                if (graph[i][j] != '#') pos = {i, j};
                if (graph[i][j] == '*')
                    graph[i][j] = '.', answer++;
                
            } else {
                double theta = M_PI/2;

                if (t == 'D') theta = -theta; 

                orientation = {
                - orientation.second * sin(theta),
                    orientation.first * sin(theta)
                };
            }
        }

        cout << answer << "\n";

    }
    
    return 0;
}
