// https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, s; cin >> n >> s;
    vector<int> a(n);
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    int l = 0, r = 0, res = 0;
    
    while (r<n) {
        while(a[r]-a[l]>s) {
            res+=(n-r);
            l++;
        }
        r++;
    }
    
    cout << res << '\n';
}