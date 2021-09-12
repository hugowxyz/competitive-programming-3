#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

struct UnionFind {
    map<string, string> parent;
    map<string, int> rank, setSize;

    void addSet(string i) {
        if (findSet(i) != "") return;
        parent[i] = i; 
        rank[i] = 0;
        setSize[i] = 1;
    }

    string findSet(string i) {
        if (parent[i] == i) return i; 
        return parent[i] = findSet(parent[i]);
    }

    bool isSameSet(string i, string j) { return findSet(i) == findSet(j); }

    void unionSet(string i, string j) {
        if (isSameSet(i, j)) return;
        
        string x = findSet(i), y = findSet(j);
        
        if (rank[x] > rank[y]) {
            parent[y] = x;
            setSize[x] += setSize[y];
        } else {
            parent[x] = y;
            setSize[y] += setSize[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
    }

    int networkSize(string i) { return setSize[findSet(i)]; }
};

int main() {
    FASTIN

    int t, n;
    string i, j;

    cin >> t;
    
    while (t--) {
        cin >> n;
        UnionFind ufds;
        while (n--) {
            cin >> i >> j;
            ufds.addSet(i);
            ufds.addSet(j);
            ufds.unionSet(i, j);
            cout << ufds.networkSize(i) << "\n";
        }
    }


    
    return 0;
}