// https://judge.beecrowd.com/en/problems/view/2449

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    } 
    
    int res = 0;
    for(int i=0; i<n-1; i++){
        res+=(abs(a[i]-m));
        a[i+1] -= (a[i]-m);
        a[i] = m;
    }
    
    cout << res << '\n';
}