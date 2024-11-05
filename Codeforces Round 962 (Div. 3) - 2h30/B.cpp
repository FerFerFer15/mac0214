#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int n, k; cin >> n >> k;
        vector<vector<char>> a(n);

        for(int i=0; i<n; i++){
            a[i].resize(n);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> a[i][j];
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i%k==0 && j%k==0) {
                    cout << a[i][j];
                }
            }
            if(i%k==0) cout << '\n';
        }
    }
}