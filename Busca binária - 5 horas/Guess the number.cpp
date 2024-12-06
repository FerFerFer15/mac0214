// https://codeforces.com/contest/1385/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int lo = 1, hi = 1e6;
    int maybe;
    
    while(lo<=hi) {
        int mid = (lo+hi)/2;
        cout << mid;
        cout << endl;

        string res; cin >> res;
        if(res==">="){
            lo = mid+1;
            maybe = mid;
        } else {
            hi = mid-1;
        }
    }

    cout << "! " << maybe << endl;
}
