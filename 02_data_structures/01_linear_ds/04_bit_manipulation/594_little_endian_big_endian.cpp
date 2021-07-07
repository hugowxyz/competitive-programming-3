#include <bits/stdc++.h>

using namespace std;

#define FASTIN ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    FASTIN

    int n;
    bitset<32> b;
    
    while ( !cin.eof() ) {
        cin >> n;
        b = n;

        int c = 0;
        for ( int i=0; i<16; i++ ) {
            if ( !(i % 8) ) c++;
            bool t = b[i];
            b[i] = b[i%8+32-8*c];
            b[i%8+32-8*c] = t;
        }

        cout << n << " converts to " << (int)(b.to_ulong()) << "\n";

    }

    return 0;
}