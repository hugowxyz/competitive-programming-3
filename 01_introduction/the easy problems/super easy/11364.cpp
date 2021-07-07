#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, x;
    scanf("%d", &t);
    while(t--){
        int mi = 100, ma=0;
        scanf("%d", &n);
        while(n--){
            scanf("%d", &x);
            if (mi>x) mi = x;
            if (ma<x) ma = x;
        }
        printf("%d\n", 2 * (ma - mi));
    }    
    return 0;
}