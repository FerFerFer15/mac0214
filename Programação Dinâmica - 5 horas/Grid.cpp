// https://atcoder.jp/contests/dp/tasks/dp_h
 
#include <bits/stdc++.h> 
using namespace std; 
#define int long long

const int MOD = 1e9+7;

int h, w;
vector<vector<int>> dp; 
vector<vector<char>> path; 
 
signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    cin >> h >> w;; 
     
    dp.resize(h); 
    path.resize(h); 
    for(int i=0; i<h; i++) { 
        dp[i].resize(w+1,0); 
        path[i].resize(w+1); 
    } 
    dp[0][0] = 1;
    
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            cin >> path[i][j];
    
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(path[i][j]=='.') {
                if(i-1>=0) dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
                if(j-1>=0) dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
            }
        }
    }
    
    cout << dp[h-1][w-1] << '\n'; 
}