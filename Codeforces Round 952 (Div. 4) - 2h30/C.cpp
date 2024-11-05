#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        vector<int> a(n);

        for(int i=-0; i<n; i++) {
            cin >> a[i];
        }

        int res = 0;

        int max = a[0], sum = 0;

        if(a[0]==0) res++;

        for(int i = 1; i<n; i++){
            if(a[i]>max) {
                sum+=max;
                max=a[i];
            } else {
                sum+=a[i];
            }

            if(max==sum) res++;
        }

        cout << res << '\n';
    }
}