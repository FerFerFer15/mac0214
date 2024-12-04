// https://codeforces.com/problemset/problem/1343/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        
        for(int i=0; i<n; i++) cin >> a[i];
        
        int sum = 0;
        int max = a[0];
        
        for(int i=1; i<n; i++){
            if((a[i-1]>0 && a[i]<0) || (a[i-1]<0 && a[i]>0)) {
                sum+=max;
                max=a[i];
            } else {
                if(a[i]>max) max = a[i];
            }
        }
        
        sum+=max;
        
        cout << sum << '\n';
    }
}