// https://codeforces.com/contest/1385/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t; cin >> t;
    
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        
        for(int i=0; i<n; i++) cin >> a[i];
        
        int r = n-1;
        
        while(r>0 and a[r]<=a[r-1]) r--;
        while(r>0 and a[r]>=a[r-1]) r--;
        
        cout << r << '\n';
    }
}
