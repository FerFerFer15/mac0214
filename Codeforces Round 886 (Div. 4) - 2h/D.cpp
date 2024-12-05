#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        
        sort(a.begin(),a.end());
        
        if(n>1){
            int maxseq = 0;
            int seq = 1;
            for(int i=1; i<n; i++){
                if(a[i]-a[i-1]<=k){
                    seq++;
                } else {
                    if(seq>maxseq) maxseq = seq;
                    seq = 1;
                }
            }
            if(seq>maxseq) maxseq = seq;
            cout << n-maxseq << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}
