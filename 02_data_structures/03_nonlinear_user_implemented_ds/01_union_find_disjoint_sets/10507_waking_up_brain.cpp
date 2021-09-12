#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define LOOP(x, s, n, inc) for (int x=s; x<n; x+=inc)

int main() {
    FASTIN

    char x, y, z;
    int N, M;
    vector<int> active;
    vector<vector<int>> graph;

    while (cin >> N) {
        active.assign(26, 0);
        graph.assign(26, vector<int>());

        cin >> M >> x >> y >> z;
        
        active[x-'A'] = active[y-'A'] = active[z-'A'] = 1;

        while (M--) {
            cin >> x >> y;
            graph[x-'A'].push_back(y-'A');
            graph[y-'A'].push_back(x-'A');
        }

        bool new_active = 1;
        int years = 0, n_active = 3;

        vector<int> t;

        while (new_active && n_active < N) {
            new_active = 0;
            for (int i=0; i<graph.size(); i++) {
                if (active[i]) continue;
                int node, sum = 0;
                for (int j=0; j<graph[i].size(); j++) {
                    node = graph[i][j];
                    sum += active[node];
                    if (sum >= 3) {
                        t.push_back(i);
                        new_active = 1;
                        n_active++;
                        break;
                    }
                } 
            for (auto i : t) active[i] = 1;
            t.clear();
            years++;
            }
        }

        if (n_active < N) cout << "THIS BRAIN NEVER WAKES UP\n";
        else cout << "WAKE UP IN, " << years << ", YEARS\n";

        cin.ignore(); cin.ignore();

    }

    return 0;
}