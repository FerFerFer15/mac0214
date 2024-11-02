#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n, s, m; cin >> n >> s >> m;
        bool res = false;
        int last = 0;
        int l, r;
        while(n--) {
            cin >> l >> r;
            if(l-last>=s) res = true;

            last = r;
        }
        if(m-last>=s) res = true;

        if(res) cout << "YES" << '\n';
        else    cout << "NO" << '\n';
    }
}