#include <bits/stdc++.h>

using namespace std;

int g[3][3], gg[3][3];

int tr[4][2] = {
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};

void transform(int x) {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            int s = 0;
            for (int k=0; k<4; k++) {
                int *trr = tr[k];
                
                if (trr[0] + j >= 0 && trr[0] + j < 3 && 
                    trr[1] + i >= 0 && trr[1] + i < 3) 
                    {
                        s += x ? gg[i+trr[1]][j+trr[0]] : g[i+trr[1]][j+trr[0]];
                    }
            }
            if(x)
                g[i][j] = s % 2;
            else
                gg[i][j] = s % 2;
        }
    }
}

bool same() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (g[i][j] != gg[i][j]) return false;
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                char c = '\n';
                while ( c == '\n') scanf("%c", &c); 
                g[i][j] = c-'0';
            }
        }

        int ans = -1, counter = 0;
        while(1){
            transform(counter);
            counter++; counter %= 2;
            if (same()) break;
            ans++;
        }

        printf("%d\n", ans);
    }
    return 0;
}