#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    FASTIN

    string s, t;
    map<string, int> m;

    // generate strings

    int count = 1;
    queue<string> q;

    for(char c='a'; c<='z'; c++)
        q.push(string(1, c));

    while(!q.empty()) {
        t = q.front();
        m[t] = count++;
        q.pop();
        
        if(t.length() == 5) 
            continue;

        for(char c=(t.back()+1); c<='z'; c++) 
            q.push(t + c);
    }

    while(cin >> s) {
        auto it = m.find(s);
        if(it == m.end()) cout << 0 << "\n";
        else cout << it->second << "\n";
    }    

    return 0;
}