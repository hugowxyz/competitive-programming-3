#include <bits/stdc++.h>

using namespace std;

bool flag[3000];

int main() {
    int n, x, y;
    while (scanf("%d", &n) != EOF) {
        int a = 1;
        scanf("%d", &x);
        for (int i=1; i<n; i++) {
            scanf("%d", &y);
            flag[abs(x-y)] = true;
            x=y;
        }
        for (int i=1; i<n; i++) {
            if(!flag[i]) {
                a=0;
                break;
            }
        }
        
        printf(a ? "Jolly\n" : "Not jolly\n");

        memset(flag, 0, sizeof(flag));
    }

    return 0;
}