#include <bits/stdc++.h>

using namespace std;

int main() {
    long long sz, p;
    scanf("%lld %lld", &sz, &p);
    while(sz+p>0){
        long long i = 1;
        while (p > i*i) i+=2;

        if (i == 1) {
            printf("Line = %lld, column = %lld.\n", sz/2+1, sz/2+1);
        } else {
            long long x, y = sz/2+1 + (i-1)/2, t = i*i; x = y;

            t++;
            for(int j=0; j<i && (t != p); j++) { y--; t--; }

            t++;
            for(int j=0; j<i && (t != p); j++) { x--; t--; }

            t++;
            for(int j=0; j<i && (t != p); j++) { y++; t--; }
            
            t++;
            for(int j=0; j<i-1 && (t != p); j++) { x++; t--; }

            if (t == p) {
                printf("Line = %lld, column = %lld.\n", y, x);
            }
        }

        scanf("%lld %lld", &sz, &p);
    }
    return 0;
}