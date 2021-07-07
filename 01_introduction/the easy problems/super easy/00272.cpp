#include <bits/stdc++.h>

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<ii>      vii;
typedef vector<int>     vi;
#define INF 1e9 

const int mxN = 2e5;
char arr[mxN];

int main() {
    char c, t=0;
    while((c=getchar()) != EOF){
        if (c == '"'){
            if (t) printf("''");
            else printf("``");
            t++;
            t%=2;
        }else {
            printf("%c", c);
        }
    }
    return 0;
}