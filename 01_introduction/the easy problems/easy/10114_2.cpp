#include <bits/stdc++.h>

using namespace std;

int main() {
    int m=1, k, f;
    double p, cp, v, vd, m0, m1, d0, d1;
    scanf("%d%lf%lf%d", &m, &p, &v, &k);
    while(m>=0){
        cp = v/m; f=0; m0=1;
        scanf("%lf%lf", &m1, &d0);
        vd = (v+p)*(1-d0); k--; 
        if(v<vd){ 
            printf("0 months\n");
            while(k--) { scanf("%lf%lf", &m1, &d1); }
        }
        printf("out - %lf - %lf\n", v, vd);
        while(k--){
            if(!f) scanf("%lf%lf", &m1, &d1);
            for(m0; m0<m1; m0++){
                v-=cp; vd*=(1-d0);
                printf("%lf - %lf - %lf\n", m0, v, vd);
                if(v<vd){
                    printf("%d month", (int)m0);
                    if(m0!=1) printf("s");
                    printf("\n");
                    f=1; k=0; break;
                }
            }

            m0=m1; d0=d1;

            if(!f&&!k){
                f=1; k=1; m1=m+1;
            }
        }

        scanf("%d%lf%lf%d", &m, &p, &v, &k);
    }
    return 0;
}