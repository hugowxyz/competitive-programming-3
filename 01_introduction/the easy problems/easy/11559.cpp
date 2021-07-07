#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int main() {
    // n = nof. participants b = budget h = hotels w = weeks
    // p = price/person a = beds available m = min cost
    int n, b, h, w, p, a, m;
    while(scanf("%d%d%d%d", &n, &b, &h, &w) != EOF){
        m = INF;
        while(h--){
            scanf("%d", &p);
            for(int i=0; i<w; i++){
                scanf("%d", &a);
                if(a>=n) m = min(m, p*n);
            }
        }
        if(m<=b) printf("%d\n", m);
        else printf("stay home\n");
    }
    
    return 0;
}
