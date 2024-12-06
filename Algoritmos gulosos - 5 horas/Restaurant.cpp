// https://codeforces.com/contest/597/problem/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    vector<array<int,2>> a;
    
    for(int i=0; i<n; i++){
        int l, r; cin >> l >> r;
        a.push_back({r,l});
    } 
    
    sort(a.begin(),a.end());
    int res = 1;
    int end = a[0][0];
    
    for(int i=1; i<n; i++){
        if(a[i][1]>end){
            res++;
            end = a[i][0];
        }
    }
    
    cout << res << '\n';
}