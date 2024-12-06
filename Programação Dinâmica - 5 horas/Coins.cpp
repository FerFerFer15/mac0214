// https://atcoder.jp/contests/dp/tasks/dp_i
 
#include <bits/stdc++.h> 
using namespace std; 
#define int double 
 
long n; 
vector<int> p; 
vector<vector<int>> dp; 
 
int solve(long l, long i) { 
    if(l<0 or i<0) return 0;
    if(dp[l][i]>-1) return dp[l][i]; 
    
    dp[l][i] = (1-p[l])*solve(l-1,i) + p[l]*solve(l-1,i-1); 
     
    return dp[l][i]; 
} 
 
signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    cin >> n; 
     
    p.resize(n+1); 
    dp.resize(n+1); 
    for(long i = 0; i<=n; i++) { 
        dp[i].resize(n+1,-1); 
    } 
    dp[0][0] = 1;
    p[0] = 0; 
    for(long i=1; i<=n; i++) { 
        cin >> p[i]; 
    } 
    int res = 0; 
     
    for(long i=(n+1)/2; i<=n; i++){ 
        res += solve(n,i); 

    } 
     
    cout << fixed << setprecision(10) << res << '\n'; 
}