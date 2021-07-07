#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    FASTIN

    string s;
    stringstream ss;
    int c, d, k, a[20];

    cin >> c;
    while (c--) {
        int deg, n = 0; 
        cin >> deg; deg++;
        while (deg--) cin >> a[n++];
        cin >> d >> k;
        
        float i = ceil((-1 + sqrt(1 + 8 * (float)k/d))/2);
        long long ai = 0;
        for (int j=0; j<n; j++) ai += pow(i, j) * a[j];

        cout << ai << "\n";

        memset(a, 0, 20);
    }

    return 0;
}