#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

vector<vector<int>> graph;
vector<int> visited;

void dfs(int u) {
    visited[u] = 1;
    for (auto v : graph[u]) {
        if (!visited[v]) dfs(v);
    }
}

int main() {
    FASTIN

    char c;
    string s;
    int t, nodes, components;

    cin >> t; 

    while (t--) {
        cin >> c; cin.ignore();
        nodes = c - 'A' + 1;
        graph.assign(nodes, {});
        visited.assign(nodes, 0);

        while (getline(cin, s) && s != "") {
            graph[s[0]-'A'].push_back(s[1]-'A');
            graph[s[1]-'A'].push_back(s[0]-'A');
        }

        components = 0;
        for (int i=0; i<nodes; i++) {
            if (!visited[i]) 
                dfs(i), components++; 
        }

        cout << components << "\n";
        if (t) cout << "\n";
    }


    return 0;
}