// https://codeforces.com/problemset/problem/1968/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int n, m; cin >> n >> m;
        string a, b; cin >> a >> b;

        int i = 0, j = 0;

        while (i<n and j<m) {
            if(a.at(i)==b.at(j)) i++;
            j++;
        }

        cout << i << '\n';
    }
}