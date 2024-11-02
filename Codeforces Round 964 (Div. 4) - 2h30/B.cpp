#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int a, b, c, d; cin >> a >> b >> c >> d;
        int res = 0;

        int p1 = 0, p2 = 0;
        if(a>c) p1++;
        else if (a<c) p2++;
        if(b>d) p1++;
        else if (b<d) p2++;

        if(p1>p2) res+=2;

        p1 = 0, p2 = 0;
        if(a>d) p1++;
        else if (a<d) p2++;
        if(b>c) p1++;
        else if (b<c) p2++;

        if(p1>p2) res+=2;


        cout << res << '\n';
    }
}