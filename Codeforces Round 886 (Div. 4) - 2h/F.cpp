#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        vector<int> c(n+1,0);
        for(int i=0; i<n; i++) {
            cin >> a[i];
            if(a[i]<=n) c[a[i]]++;
        }
        
        vector<int> res(n+1,0);
        int maxval = 0;
        for(int i=1; i<=n; i++){
            if(c[i]>0){
                for(int j = i; j<=n; j+=i){
                    res[j]+=c[i];
                }
            }
        }
        
        for(int i=1; i<=n; i++){
            if(res[i]>maxval) maxval = res[i];
        }
        
        cout << maxval << '\n';
    }
}
