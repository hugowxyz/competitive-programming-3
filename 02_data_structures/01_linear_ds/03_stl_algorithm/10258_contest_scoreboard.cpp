#include <bits/stdc++.h>

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

struct Contestant 
{
    bool attempt, solved[10];
    int number, problems_solved, penalty_time;
    int problems[10];
};

bool comp(const Contestant &t1, const Contestant &t2) {
    
    if ( t1.problems_solved < t2.problems_solved ) return false;
    else if ( t1.problems_solved == t2.problems_solved ) { 
        if ( t1.penalty_time == t2.penalty_time ) return t1.number < t2.number;
        return t1.penalty_time < t2.penalty_time; 
    }
    return true;
}

Contestant contestants[101];

int main() {
    FAST

    int t, c, p, ti;
    char l;
    string s;

    cin >> t;
    getline(cin, s);
    getline(cin, s);
    while(t--) {
        while ( getline(cin, s) && s != "" ) {
            sscanf(s.c_str(), "%d %d %d %c", &c, &p, &ti, &l);
            
            contestants[c].number = c;
            contestants[c].attempt = true;
            if ( l == 'C' && !contestants[c].solved[p] ) {  
                contestants[c].penalty_time += contestants[c].problems[p] + ti; 
                contestants[c].problems_solved++;
                contestants[c].solved[p] = true;
            }
            else if ( l == 'I' ) { 
                contestants[c].problems[p] += 20;
            }
        }
        sort(contestants, contestants + 101, comp);
        for ( auto c : contestants ) {
            if ( c.attempt )
                cout << c.number << " " << c.problems_solved << " " << c.penalty_time << "\n";
        }

        if ( t ) cout << "\n";

        memset(contestants, 0, sizeof(contestants));
    }

    return 0;
}