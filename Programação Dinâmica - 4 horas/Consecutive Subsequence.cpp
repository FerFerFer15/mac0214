// https://codeforces.com/contest/977/problem/F
// Precisa submitar em C++20

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    map<int,int> dp;
    vector<int>   a;
    int n; cin >> n;
    int max = 0;
    int maxv;
    int maxi;
    
    a.resize(n);
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
        
        if(!dp.contains(a[i]-1)){
            dp[a[i]] = 1;
        } else {
            dp[a[i]] = dp[a[i]-1] + 1;
            if(dp[a[i]]>max) {
                max = dp[a[i]];
                maxv = a[i];
                maxi = i;
            }
        }
    }
    if(max!=0) {
        cout << max << '\n';
        vector<int> res;
        for(int i=maxi; i>=0; i--) {
            if(a[i]==maxv){
                res.push_back(i);
                maxv--;
            }
        }
        int s = res.size()-1;
        for(int i=s; i>=0; i--){
            cout << res[i]+1 << ' ';
        }
        cout << '\n';
    } else {
        cout << 1 << '\n' << 1 << '\n';
    }
    
}