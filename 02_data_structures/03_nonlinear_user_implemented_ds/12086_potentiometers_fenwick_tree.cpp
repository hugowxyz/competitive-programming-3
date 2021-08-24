#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define LOOP(x, s, n, inc) for (int x=s; x<n; x+=inc)

struct FenwickTree {
    vector<int> ft;

    FenwickTree(int n) { ft.assign(n+1, 0); }

    int rsq(int b) {
        int sum = 0;
        for (; b; b-=(b&-b)) sum += ft[b];
        return sum;
    }

    int rsq(int a, int b) { return rsq(b) - rsq(a-1); }
    
    void adjust(int k, int v) {
        for (; k < ft.size(); k+=(k&-k)) ft[k] += v;
    }
};

int main() {
    FASTIN

    char c;
    int N, x, y, _case = 1;
    string s;
    stringstream ss;

    cin >> N;
    while (N) {
        FenwickTree ft(N);

        for (int i=1; i<N+1; i++) {
            cin >> x;
            ft.adjust(i, x);
        }

        cout << "Case " << _case << ":\n";

        cin.ignore();
        while (getline(cin, s) && s != "END") {
            ss.str(s);
            ss >> c >> x >> y;
            if (c == 'S') ft.adjust(x, y - ft.rsq(x, x));
            else if (c == 'M') cout << ft.rsq(x, y) << "\n";
            ss.clear();
        }

        cin >> N;
        if (!N) break;
        
        cout << "\n";
        _case++;
    }

    return 0;
}