#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define LOOP(x, s, n, inc) for (int x=s; x<n; x+=inc)

struct SegmentTree {
    int n;
    vector<int> st;

    int left(int p) { return 2 * p; }
    int right(int p) { return 2 * p + 1; }

    SegmentTree(vector<int> &A) {
        n = A.size();
        st.assign(4 * n, 0);
        build(1, 0, n-1, A);
    }

    void build(int p, int l, int r, vector<int> &A) {
        if (l == r) { st[p] = A[l]; }
        else {
            build(left(p), l, (l+r)/2, A);
            build(right(p), (l+r)/2+1, r, A);
            st[p] = st[left(p)] + st[right(p)];
        }  
    }

    void update(int p, int l, int r, int idx, int val) {
        if (!(l <= idx && idx <= r)) return;
        st[p] += val;
        if (l == r && l == idx) return;
        update(left(p), l, (l+r)/2, idx, val);
        update(right(p), (l+r)/2+1, r, idx, val);
    }

    int rsq(int p, int l, int r, int i, int j) {
        if (r < i || j < l) return 0;
        if (i <= l && r <= j) return st[p];        
        return rsq(left(p), l, (l+r)/2, i, j) + rsq(right(p), (l+r)/2+1, r, i, j);
    }

    void update(int idx, int val) { update(1, 0, n-1, idx, val); }
    int rsq(int i, int j) { return rsq(1, 0, n-1, i, j); }
};

int main() {
    FASTIN

    char c;
    int N, x, y, _case = 1;
    string s;
    stringstream ss;
    vector<int> v;

    cin >> N;
    while (N) {
        v.assign(N, 0);
        for (int i=0; i<N; i++) {
            cin >> v[i];
        }
        
        SegmentTree st(v);

        cout << "Case " << _case << ":\n";

        cin.ignore();
        while (getline(cin, s) && s != "END") {
            ss.str(s);
            ss >> c >> x >> y;
            if (c == 'S') st.update(x-1, y - st.rsq(x-1, x-1));
            else if (c == 'M') cout << st.rsq(x-1, y-1) << "\n";
            ss.clear();
        }
        
        cin >> N;
        if (!N) break;
        
        cout << "\n";
        _case++;
    }

    return 0;
}