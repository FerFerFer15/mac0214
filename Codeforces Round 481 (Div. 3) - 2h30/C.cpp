#include <bits/stdc++.h> 
using namespace std; 
#define int long long

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n,m; cin >> n >> m;
    
    vector<int> a(n);
    vector<int> b(m);
    
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];
    
    vector<int> acc(n+1);
    acc[1] = a[0];
    for(int i=2; i<=n; i++){
        acc[i] = acc[i-1] + a[i-1];
    }
    
    int l = 1;
    for(int i=0; i<m; i++){
        while(b[i]>acc[l]){
            l++;
        }
        cout << l << ' ' << b[i]-acc[l-1] << '\n';
    }
}