#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int x, y, k; cin >> x >> y >> k;
        int qtdx = ceil((double)x/k);
        int qtdy = ceil((double)y/k);
        
        if(qtdx>qtdy) cout << 2*qtdx-1 << '\n';
        else cout << 2*qtdy << '\n';
    }
}