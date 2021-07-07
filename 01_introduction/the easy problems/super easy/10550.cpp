#include <bits/stdc++.h>

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<ii>      vii;
typedef vector<int>     vi;
#define INF 1e9 

int main() {
    int a, b, c, d;
    scanf("%i %i %i %i", &a, &b, &c, &d);
    while(a || b || c || d)
    {
        printf("%i\n", 1080 + 9 * ((-b+a+40)%40 + (-b+c+40)%40 + (-d+c+40)%40));
        scanf("%i %i %i %i", &a, &b, &c, &d);
    }
    return 0;
}