#include <bits/stdc++.h> 
using namespace std; 
#define int long long

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n,w; cin >> n >> w;
    
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int sum = 0, maxsum = -1e6, minsum = 1e6;
    
    for(int i=0; i<n; i++){
        sum+=a[i];
        if(sum>maxsum){
            maxsum = sum;
        }
        
        if(sum<minsum) {
            minsum = sum;
        }
    }
    
    if(maxsum<=w){
        int zero = 0;
        int res1 = abs(min(zero,minsum));
        int res2 = abs(min(w-maxsum,w));
        
        if(res1>res2) cout << 0 << '\n';
        else cout << res2-res1+1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}