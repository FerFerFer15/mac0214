// https://codeforces.com/problemset/problem/1827/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);

        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        for(int i=0; i<n; i++){
            cin >> b[i];
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        bool valid = true;
        for(int i=0; i<n; i++){
            if(a[i]<=b[i]){
                valid = false;
            }
        }

        if(not valid) cout << 0 << '\n';
        else {
            int res = 1;
            int i = 0, j = 0;
            while(i<n and j<n) {
                if(a[i]>b[j]) {
                    res=(res*(j-i+1))%MOD;
                    j++;
                } else {
                    i++;
                }
            }
            cout << res << '\n';
        }
    }
}