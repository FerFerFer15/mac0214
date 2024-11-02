#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int a; cin >> a;
        cout << (a/10)+(a%10) << '\n';
    }
}