#include <bits/stdc++.h> 
using namespace std; 
#define int long long

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        
        for(int i=0; i<n; i++) cin >> a[i];
        for(int i=0; i<n; i++) cin >> b[i];
        
        int ai = 0;
        int bi = 0;
        int res = 0;
        
        while(bi<n){
            if(a[ai]<=b[bi]){
                ai++; bi++;
            } else {
                bi++; res++;
            }
        }
        
        cout << res << '\n';
    }
}