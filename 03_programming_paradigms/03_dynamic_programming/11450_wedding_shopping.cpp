#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL);

int price[20][21], memo[201][21];
int n, m, c;

int solve(int money, int g) {
    if (money < 0) return -1;
    if (g == c) return m - money;

    if (memo[money][g] != -1) return memo[money][g];

    int ans = -1;
    for (int i=1; i<=price[g][0]; i++) {
        ans = max(ans, solve(money-price[g][i], g+1));
    }

    return memo[money][g] = ans;
}

int main() {
    FASTIN

    cin >> n;
    while (n--) {
        cin >> m >> c;
        for (int i=0; i<c; i++) {
            cin >> price[i][0];
            for (int j=1; j<=price[i][0]; j++) cin >> price[i][j];
        }

        memset(memo, -1, sizeof(memo));
        int ans = solve(m, 0);
        if (ans < 0) 
            cout << "no solution\n";
        else 
            cout << ans << "\n";       
    }

    return 0;
}