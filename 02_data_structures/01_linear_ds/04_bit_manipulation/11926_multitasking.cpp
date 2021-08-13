#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define LOOP(x, s, n, inc) for (int x=s; x<n; x+=inc)

#define vc vector<char>
#define vi vector<int>
#define vvi vector<vector<int>>

int main() {
    FASTIN

    int n, m, x, y, z;
    bool c=0;
    
    bitset<1000001> b;

    while (cin >> n >> m && (n || m)) {
        c=0;

        while (n--) {
            cin >> x >> y;
            for (int i=x+1; i<=y; i++) {
                if ( b[i] ) {
                    cout << "CONFLICT\n";
                    c = 1;
                    break;
                }
                else b[i] = 1;
            }                
        }

        if ( !c ) {
            while (m--) {
                cin >> x >> y >> z;
                while (y <= 1e6) {
                    for (int i=x+1; i<=y; i++) {
                        if ( b[i] ) {
                            cout << "CONFLICT\n";
                            c = 1;
                            break;
                        }
                        else b[i] = 1;
                    }
                    x += z; y += z;
                }
            }
        }

        if ( !c ) {
            cout << "NO CONFLICT\n";
        }
        
        b.reset();
    }
    
    return 0;
}