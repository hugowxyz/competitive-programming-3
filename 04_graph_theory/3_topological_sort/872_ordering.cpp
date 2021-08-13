#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define LOOP(x, s, n, inc) for (int x=s; x<n; x+=inc)

#define vc vector<char>
#define vi vector<int>
#define vvi vector<vector<int>>

vi visited, ts;
vvi g;

void dfs(int u) {
    visited[u] = 1;
    
    for (char v : g[u])
        dfs(v);
    
    ts.push_back(u);
}

int main() {
    FASTIN

    g.assign(26, {});

    int t;
    char c[3];
    string s;
    stringstream ss;

    cin >> t;
    cin.ignore();
    cin.ignore();
    
    while (t--) {
        getline(cin, s);
        ss.str(s);

        int n;
        for (n=0; ss >> c[0]; n++)

        visited.assign(n, 0);
        
        ss.clear();

        getline(cin, s);
        ss.str(s);

        while ( ss >> c ) 
            g[c[0]-'A'].push_back(c[2]-'A');
        
        for (int i=0; i<n; i++) {
            if ( !visited[i] ) dfs(i);
        }

        reverse(ts.begin(), ts.end());

        for (int i : ts) {
            cout << (char)(i+'A') << " ";
        }
        
        cin.ignore();
        ts.clear();
    }
    
    return 0;
}