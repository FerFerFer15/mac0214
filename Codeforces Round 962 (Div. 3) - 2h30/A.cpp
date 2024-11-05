#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        int res = 0;
        res+=n/4;

        n=n-((n/4)*4);

        res+=n/2;

        cout << res << '\n';
    }
}