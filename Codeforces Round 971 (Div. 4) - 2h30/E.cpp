#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;

        int lo=0, hi=n-1;
        int res = 1e18;
        while(lo<=hi){
            int mid = (hi+lo)/2;
            int pos = ((k + k+mid)*(mid+1))/2;
            int neg = ((k+mid+1 + k+n-1)*(n-mid-1))/2;

            if(abs(pos-neg)<res){
                res = abs(pos-neg);
                if(pos-neg<0) lo = mid + 1;
                else hi = mid - 1;
            } else {
                if(pos-neg<0) lo = mid + 1;
                else hi = mid - 1;
            }
        }

        cout << res << '\n';
    }
}