#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int n, k; cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);
        vector<int> acca(min(n,k));
        vector<int> maxb(min(n,k));
        int maxv;

        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        for(int i=0; i<n; i++){
            cin >> b[i];
        }

        acca[0] = a[0];

        for(int i=1; i<min(n,k); i++){
            if(i>=n) acca[i] = acca[i-1];
            else     acca[i] = acca[i-1] + a[i];
        }

        maxb[0] = b[0]*(k-1);
        maxv = b[0];

        for(int i=1; i<min(n,k); i++){
            if(i<n && b[i]>maxv) maxv = b[i];
            maxb[i] = maxv*(k-i-1);
        }

        int res = 0;

        for(int i=0; i<min(n,k); i++){
            if(acca[i]+maxb[i]>res) res = acca[i]+maxb[i];
        }

        cout << res << '\n';

    }
}