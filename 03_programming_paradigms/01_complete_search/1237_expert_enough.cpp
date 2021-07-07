#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

#define P pair< pair<int, int>, string >

bool comp(P &a, P &b) {
    if ( a.first.first != b.first.first ) return a.first.first < b.first.first;
    return a.first.second < b.first.second;
}

int main() {
    FASTIN

    string m, a;
    vector<P> v;
    pair<int, int> pp;
    int t, d, l, h, q, p, c;
    
    cin >> t;
    while (t--) {
        cin >> d;
        while (d--) {
            cin >> m >> l >> h;
            v.push_back({ {l, h}, m });
        }

        sort(v.begin(), v.end(), comp);

        cin >> q;
        while (q--) {
            cin >> p; c = 0; 
            for ( P &i : v ) {
                if ( p >= i.first.first && p <= i.first.second) {
                    a = i.second; c++;
                    if ( c > 1 ) break;
                }
            }
            if ( c > 1 || c == 0 ) cout << "UNDETERMINED\n";
            else cout << a << "\n"; 
        }

        if ( t != 0 ) cout << "\n";
        v.clear();
    }

    return 0;
}