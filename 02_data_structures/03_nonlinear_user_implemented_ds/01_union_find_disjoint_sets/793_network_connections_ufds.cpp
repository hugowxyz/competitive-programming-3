#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

struct UnionFind {
    int numSets;
    vector<int> parent, rank, setSize;

    UnionFind(int n) {
        numSets = n;
        setSize.assign(n, 0);
        rank.assign(n, 0);
        for (int i=0; i<n; i++) parent.push_back(i);
    }

    int findSet(int i) {
        if (parent[i] != i) parent[i] = findSet(parent[i]);
        return i;
    }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        numSets--;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) {
            parent[y] = x;
            setSize[x] += setSize[y];
        } else {
            parent[x] = y;
            setSize[y] += setSize[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
    }
};

int main() {
    FASTIN

    char c;
    int t, n, x, y, a, b;

    cin >> t;
    // while (t--) {
    //     a = 0, b = 0;
    //     cin >> n;
    //     // UnionFind ufds(n-1);
    //     while (n--) {
    //         cin >> c >> x >> y;
    //         // if (c == 'c') ufds.unionSet(x-1, y-1);
    //         // else ufds.isSameSet(x-1, y-1) ? a++ : b++;
    //     }
    //     cout << a << "," << b << "\n";
    //     if (!t) cout << "\n";
    // }

    return 0;
}