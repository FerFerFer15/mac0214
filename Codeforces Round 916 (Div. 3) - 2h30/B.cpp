#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int n, k; cin >> n >> k;

        int s = n-k;

        for(int i=0; i<=k; i++){
            cout << s+i << ' ';
        }

        for(int i=1; i<n-k; i++){
            cout << s-i << ' ';
        }
        cout << '\n';

    }
}