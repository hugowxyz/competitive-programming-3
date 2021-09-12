#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define LOOP(x, s, n, inc) for (int x=s; x<n; x+=inc)

#define vc vector<char>
#define vi vector<int>
#define vvi vector<vector<int>>

int main() {
    FASTIN

    vector<int> awake;
    bitset<26> bawake;
    vector<vector<int>> graph;
    map<int, int> m;

    int N, M;
    char x, y;

    while (cin >> N) {
        m.clear();
        awake.clear();
        bawake.reset();
        graph.assign(26, vector<int>());

        cin >> M;

        for (int i=0; i<3; i++) {
            cin >> x;
            awake.push_back(x-'A');
            bawake[x-'A'] = 1;
        }

        while (M--) {
            cin >> x >> y;
            graph[x-'A'].push_back(y-'A');
            graph[y-'A'].push_back(x-'A');
        }

        int i = 0, ans = 0;
        bool all_awake = awake.size() == N, new_awake = 1;
        for (ans; new_awake && !all_awake; ans++) {
            new_awake = 0;
            for (i; i<awake.size(); i++) {
                for (auto j : graph[awake[i]]) {
                    m[j]++;
                }
            }

            for (auto k : m) {
                if (k.second >= 3 && !bawake[k.first]) {
                    new_awake = 1;
                    awake.push_back(k.first);
                    bawake[k.first] = 1;
                }
            }

            all_awake = awake.size() == N;
        }

        if (awake.size() < N) cout << "THIS BRAIN NEVER WAKES UP";
        else cout << "WAKE UP IN, " << ans << ", YEARS";
        cout << "\n";

    }

    return 0;
}