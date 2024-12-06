// https://www.spoj.com/problems/EDIST/

#include <bits/stdc++.h>
using namespace std;
#define int long long

string a,b;

int solveres(int n, int m, vector<vector<int>>& dp) {
    if(dp[n][m]>=0) return dp[n][m];
    if(n==0 || m==0){
        dp[n][m] = max(n,m);
        return dp[n][m];
    }
    
    if(a.at(n-1)==b.at(m-1)) {
        dp[n][m] = min(solveres(n-1,m,dp)+1 , min(solveres(n,m-1,dp)+1 , solveres(n-1,m-1,dp)));
    } else {
        dp[n][m] = min(solveres(n-1,m,dp)+1 , min(solveres(n,m-1,dp)+1 , solveres(n-1,m-1,dp)+1));
    }
    
    return dp[n][m];
}

int solve() {
    int as = a.size(), bs = b.size();
    vector<vector<int>> dp;
    dp.resize(as+1);
    
    for(int i=0; i<=as; i++) {
        dp[i].resize(bs+1,-1);
    }
    
    return solveres(as,bs,dp);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        cin >> a >> b;
        
        cout << solve() << '\n';
    }
   
}