#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define LOOP(x, s, n, inc) for (int x=s; x<n; x+=inc)

#define vc vector<char>
#define vi vector<int>
#define vvi vector<vector<int>>

int main() {
    FASTIN

    int n, s, mx;
    vector<int> weights, potencies;

    while (cin >> n) {
        weights.assign(1 << n, 0);
        potencies.assign(1 << n, 0);

        for (int i=0; i < 1 << n; i++)
            cin >> weights[i];

        for (int corner=0; corner < 1 << n; corner++) {
            s = 0;
            for (int i=0; i < n; i++)
                s += weights[corner ^ (1 << i)];

            potencies[corner] = s;
        }

        mx = 0;
        for (int corner=0; corner < 1 << n; corner++) {
            for (int i=0; i < n; i++)
                mx = max(mx, potencies[corner] + potencies[corner ^ (1 << i)]);
        }
        
        cout << mx << "\n";
    }

    return 0;
}