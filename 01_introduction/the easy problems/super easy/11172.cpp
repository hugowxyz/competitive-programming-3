#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a,&b);
        if (a<b) printf("<");
        else if (a==b) printf("=");
        else printf(">");
        printf("\n");
    }
    return 0;
}