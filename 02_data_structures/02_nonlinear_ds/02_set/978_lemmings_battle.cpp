#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define LOOP(x, s, n, inc) for (int x=s; x<n; x+=inc)

#define vc vector<char>
#define vi vector<int>
#define vvi vector<vector<int>>

int main() {
    FASTIN

    vector<int> vg, vb;
    multiset<int> msg, msb;

    int t, s, sg, sb, pw;
    cin >> t;
    while (t--) {
        msg.clear();
        msb.clear();
        cin >> s >> sg >> sb;
        while (sg--) {
            cin >> pw;
            msg.insert(pw);
        }
        while (sb--) {
            cin >> pw;
            msb.insert(pw);
        } 

        while (!msg.empty() && !msb.empty()) {
            int mn = min(min((int)msg.size(), s), min((int)msb.size(), s));
            
            vg.clear();
            vb.clear();

            for (int i=0; i<mn; i++) {
                auto sgp = --msg.end(), sbp = --msb.end();
                if (*sgp > *sbp) vg.push_back(*sgp-*sbp);  
                else if (*sgp < *sbp) vb.push_back(*sbp-*sgp);  
                msg.erase(sgp); 
                msb.erase(sbp);
            }

            for (auto i : vg) msg.insert(i);
            for (auto i : vb) msb.insert(i);
        }

        if (msg.empty() && msb.empty()) {
            cout << "green and blue died\n";
        } else if (msb.empty()) {
            cout << "green wins\n";
            for (auto i = msg.rbegin(); i != msg.rend(); i++) cout << *i << "\n";
        } else {
            cout << "blue wins\n";
            for (auto i = msb.rbegin(); i != msb.rend(); i++) cout << *i << "\n";
        }

        if (t) cout << "\n";
    }
    
    return 0;
}