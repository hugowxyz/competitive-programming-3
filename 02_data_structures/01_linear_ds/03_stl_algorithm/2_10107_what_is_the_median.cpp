#include <bits/stdc++.h>

using namespace std;

int main() {
    long long m, x;
    vector<long long> v;

    while ( scanf("%lld", &x) != EOF ) {
        v.push_back(x);
        for (int i = v.size()-1; i>0; i--) {
            if ( v[i] < v[i-1] ) {
                int t = v[i-1];
                v[i-1] = v[i];
                v[i] = t;
            } else {
                break;
            }
        }

        if ( v.size() % 2 == 0 ) printf("%lld\n", (v[v.size()/2] + v[v.size()/2-1]) / 2);
        else printf("%lld\n", v[v.size()/2]);
    }
    
    return 0;
}