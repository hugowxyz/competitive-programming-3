#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, n, m, x, y;
    while(scanf("%d", &k), k){
        scanf("%d%d", &n, &m);
        while(k--){
            scanf("%d%d", &x, &y);
            x-=n; y-=m;
            if(!x||!y) printf("divisa");
            else if(x>0&&y>0) printf("NE");
            else if(x<0&&y>0) printf("NO");
            else if(x>0&&y<0) printf("SE");
            else printf("SO");
            printf("\n");
        }
    }
    return 0;
}