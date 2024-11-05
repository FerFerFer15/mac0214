#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        string a, b; cin >> a >> b;

        cout << b.at(0) << a.at(1) << a.at(2) << ' ';
        cout << a.at(0) << b.at(1) << b.at(2) << '\n';
    }
}