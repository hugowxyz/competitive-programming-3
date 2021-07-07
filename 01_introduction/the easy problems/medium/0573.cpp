#include <bits/stdc++.h>

using namespace std;

int main() {
    int h, d;
    double u, f;
    scanf("%d%lf%d%lf", &h ,&u, &d, &f);
    while(h) {
        int day=1;
        double height=0; 
        f = (f/100) * u;
        while(1){
            if(u>0) height += u;
            if(height>h) { printf("success on day %d\n", day); break; }
            u -= f;
            height -= d;
            if(height<0) { printf("failure on day %d\n", day); break; }
            day++;
        }
        scanf("%d%lf%d%lf", &h ,&u, &d, &f);
    }
    
    return 0;
}