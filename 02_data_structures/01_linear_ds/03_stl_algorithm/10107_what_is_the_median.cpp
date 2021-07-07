#include <bits/stdc++.h>

using namespace std;

int main() {
    long long m, x;
    vector<long long> v;

    while ( scanf("%lld", &x) != EOF ) {
        v.push_back(x);

        nth_element(v.begin(), v.begin() + v.size()/2, v.end());
        m = v[v.size()/2];

        if ( v.size() % 2 == 0 ) {
            nth_element(v.begin(), v.begin() + v.size()/2 - 1, v.end());
            m = (v[v.size()/2] + v[v.size()/2-1])/2;
        }

        printf("%lld\n", m);
    }
}