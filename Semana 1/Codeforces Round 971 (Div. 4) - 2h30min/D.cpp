#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<array<bool,2>> check(n);
        int res = 0;
        for(int i=0; i<n; i++){
            int x, y; cin >> x >> y;
            check[x][y] = true;
        }
        for(int i=0; i<n; i++){
            if(check[i][0] && check[i][1]) res+=n-2;
            if(i>0 && i<n-1 && check[i][0] && check[i-1][1] && check[i+1][1]) res++;
            if(i>0 && i<n-1 && check[i][1] && check[i-1][0] && check[i+1][0]) res++;
        }

        cout << res << '\n';
    }
}