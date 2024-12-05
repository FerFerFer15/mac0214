#include <bits/stdc++.h> 
using namespace std; 
#define int long long

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n; cin >> n;
    vector<int> a(n);
    vector<bool> added(1001,false);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    vector<int> res;
    
    for(int i=n-1; i>=0; i--){
        if(!added[a[i]]) {
            res.push_back(a[i]);
            added[a[i]] = true;
        }
    }
    int t = res.size();
    cout << t << '\n';
    for(int i=t-1; i>=0; i--){
        cout << res[i] << ' ';
    }
    cout << '\n';
}