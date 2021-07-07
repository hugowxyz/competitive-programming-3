#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    string c, s, t;
    getline(cin, c);
    for(int i=0; i<stoi(c); i++){
        m = 0; t = "";
        getline(cin, s);
        for(auto k=s.begin(); k<=s.end(); k++){
            if(*k!=' '&&k!=s.end()) t.push_back(*k);
            else {
                m = max(m, stoi(t));
                t = "";
            }
        }
        printf("Case %d: %d\n", (i+1), m);
    }
    
    return 0;
}