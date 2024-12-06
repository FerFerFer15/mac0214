// https://atcoder.jp/contests/dp/tasks/dp_c

#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> dp;
vector<vector<int>> pontos;
int n;

int solve(int i, int j) {
    if(dp[i][j]>=0) return dp[i][j];

    dp[i][j] = pontos[i][j];
    if(j==0) dp[i][j] += max(solve(i-1,1),solve(i-1,2));
    if(j==1) dp[i][j] += max(solve(i-1,0),solve(i-1,2));
    if(j==2) dp[i][j] += max(solve(i-1,0),solve(i-1,1));

    return dp[i][j];
}

signed main() {
    cin >> n;

    dp.resize(n);
    for(int i=0; i<n; i++) dp[i].resize(3,-1);
    pontos.resize(n);
    for(int i=0; i<n; i++) pontos[i].resize(3);

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++) cin >> pontos[i][j];
    }

    dp[0][0] = pontos[0][0];
    dp[0][1] = pontos[0][1];
    dp[0][2] = pontos[0][2];

    int res = max(solve(n-1,0), max(solve(n-1,1), solve(n-1,2)));

    cout << res << '\n';
}
