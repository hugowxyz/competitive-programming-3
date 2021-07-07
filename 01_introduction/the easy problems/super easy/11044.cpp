#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        int ans = ceil(((double)n-2)/3) * ceil(((double)m-2)/3);
        printf("%d\n", ans);
    }    
    return 0;
}