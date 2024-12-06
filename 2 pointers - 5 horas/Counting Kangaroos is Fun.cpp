// https://codeforces.com/contest/373/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    vector<int> a(n+1);

    a[0] = -1;
    
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(),a.end());
    
    int r = n, l = n/2, res = n;
    
    while (l>=1) {
        if(a[l]*2<=a[r]) {
            res--;
            r--;
        }
        l--;
    }
    
    cout << res << '\n';
}