#include <bits/stdc++.h>
using namespace std;

int index(char a) {
    if(a=='A') return 1; if(a=='B') return 2; if(a=='C') return 3; if(a=='D') return 4; 
    if(a=='E') return 5; if(a=='F') return 6; if(a=='G') return 7; if(a=='H') return 8; 
    if(a=='I') return 9; if(a=='J') return 10; if(a=='K') return 11; if(a=='L') return 12; 
    if(a=='M') return 13; if(a=='N') return 14; if(a=='O') return 15; if(a=='P') return 16; 
    if(a=='Q') return 17; if(a=='R') return 18; if(a=='S') return 19; if(a=='T') return 20; 
    if(a=='U') return 21; if(a=='V') return 22; if(a=='W') return 23; if(a=='X') return 24; 
    if(a=='Y') return 25; if(a=='Z') return 26; 
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        int res = 0;
        vector<int> min(26,0);

        for(int i=0; i<n; i++){
            char c; cin >> c;
            min[index(c)-1]++;
            if(min[index(c)-1]==index(c)) res++;
        }

        cout << res << '\n';
    }
}