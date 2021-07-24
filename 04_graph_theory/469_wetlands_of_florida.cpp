#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

int R=0, C=0;
vector<string> g, gc;

int dr[] = {1, 0, -1, 0, 1, -1, 1, -1},
    dc[] = {0, 1, 0, -1, 1, 1, -1, -1};

int floodfill(int r, int c) {
    if (r < 0 || c < 0 || r >= R || c >= C) return 0;
    if (g[r][c] != 'W') return 0;
    int ans = 1;
    g[r][c] = '.';
    for (int i=0; i<8; i++) ans += floodfill(r + dr[i], c + dc[i]);
    return ans;
}

int main() {
    FASTIN
    
    int t, r, c;
    string s;
    stringstream ss;

    cin >> t; 
    cin.ignore(); getline(cin, s);
    while (t--) {
        while (getline(cin, s) && (s[0] == 'W' || s[0] == 'L')) 
            g.push_back(s), R++;
        C = g[0].length();
        gc = g;
        do {
            ss.clear(); ss.str(s);
            ss >> r >> c;
            cout << floodfill(r-1, c-1) << "\n";
            g = gc;
        } while(getline(cin, s) && s != "");
        
        if (t) cout << "\n";

        g.clear(); R=0; C=0;
    }

    return 0;
}
