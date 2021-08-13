#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define LOOP(x, s, n, inc) for (int x=s; x<n; x+=inc)

#define vc vector<char>
#define vi vector<int>
#define vvi vector<vector<int>>

int main() {
    FASTIN

    string s;

    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();

    while (t--) {
        double p, sm = 0;
        map<string, int> m;

        while (getline(cin, s) && s != "")
            m[s]++, sm++;

        for (auto i = m.begin(); i != m.end(); i++)
            cout    << setprecision(4) << fixed 
                    << i->first << " " << i->second/sm * 100<< "\n";
        
        if (t) cout << "\n";
    }

    
    return 0;
}