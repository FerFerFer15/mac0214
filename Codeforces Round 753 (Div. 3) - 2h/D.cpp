#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<char> c(n);
        vector<pair<char,int>> p;
        
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        
        for(int i=0; i<n; i++){
            cin >> c[i];
        }
        
        for(int i=0; i<n; i++){
            p.push_back({c[i],a[i]});
        }
        
        sort(p.begin(),p.end());
        
        bool possible = true;
        for(int i=0; i<n; i++){
            if(!((p[i].first=='B' and p[i].second>=i+1) or (p[i].first=='R' and p[i].second<=i+1))){
                possible = false;
                break;
            }
        }
        
        if(possible) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}