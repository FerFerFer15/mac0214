#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while(t--) {
        int x, n; cin >> x >> n;
        
        int res;
        int mod = n%4;
        switch(mod) {
            case 0:
                res = 0;
                break;
            case 1:
                res = -n;
                break;
            case 2:
                res = 1;
                break;
            case 3:
                res = n+1;
                break;
        }
        
        if(x%2==0){
            x += res;
        } else {
            x -= res;
        }
        
        cout << x << '\n';
    }
}