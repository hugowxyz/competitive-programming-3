#include <bits/stdc++.h>

using namespace std;

map<char, int> tb;

int main() {
    int n, k, v, m;
    char c;
    scanf("%d", &n);
    while(n--){
        double ans = 0;
        scanf("%d", &k);
        while(k--){
            scanf(" %c %d", &c, &v);
            tb[c] = v;
        }
        scanf("%d ", &m);
        string s;
        while(m--){
            getline(cin, s);
            for(char i : s){
                ans += tb[i];
            }
        }
        ans/=100;
        printf("%.2f$\n", ans);
        tb.clear();
    }
    
    return 0;
}