#include <bits/stdc++.h>

using namespace std;

int N, n;
char M[100][100], m[100][100];

int search() {
    int ans = 0;
    for(int i=0; i<N-n+1; i++) {
        for(int j=0; j<N-n+1; j++) {
            bool matches = 1;
            
            for(int k=0; (k<n) && matches; k++){
                for(int l=0; (l<n) && matches; l++){
                    if(M[i+k][j+l] != m[k][l])
                        matches = 0;
                }
            }
            
            if (matches) ans++;
        }
    }
    return ans;
}

void rotate() {
    for(int y=0; y<n/2; y++) {
        for(int x=y; x<n-y-1; x++) {
            char temp = m[y][x];
            m[y][x] = m[n-x-1][y];
            m[n-x-1][y] = m[n-y-1][n-x-1];
            m[n-y-1][n-x-1] = m[x][n-y-1]; 
            m[x][n-y-1] = temp;
        }
    }
}

int main() {
    scanf(" %d %d ", &N, &n);
    while(N && n) {
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                M[i][j] = getchar();
            }
            getchar();
        }

        for(int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                m[i][j] = getchar(); 
            }
            getchar();
        }

        printf("%d", search());
        for(int i=0; i<3; i++) {
            rotate();
            printf(" %d", search());
        }

        printf("\n");

        scanf(" %d %d ", &N, &n);
    }
    return 0;
}