#include <bits/stdc++.h> 
using namespace std; 
#define int long long

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        int qtdu = 0;
        
        for(int i=0; i<n; i++) {
            char c;
            cin >> c;
            if(c=='U') qtdu++;
        }
        
        if(qtdu%2==0) cout << "NO\n";
        else cout << "YES\n";
    }
}