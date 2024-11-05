#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 2e5+100;
int a[MAX], c[MAX];
int oo = 1e12;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int h,n; cin >> h >> n;
        int sum = 0;
        for(int i=1; i<=n; i++){
            cin >> a[i];
            sum+=a[i];
        }

        for(int i=1; i<=n; i++){
            cin >> c[i];
        }


        int r = oo;
        int lo = 1;
        int hi = oo;
        int mid;

        if(sum>=h) cout << 1 << '\n';
        else {
            while(lo<=hi){
                mid = (lo+hi)/2;
                int sum2 = sum;
                for(int i=1; i<=n; i++){
                    sum2+=a[i]*((mid)/c[i]);
                }
                
                if(sum2>=h){
                    hi = mid-1;
                    r = mid;
                } else {
                    lo = mid+1;
                }
            }



            cout << r+1 << '\n';
        }
    }
}
