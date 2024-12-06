// https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/B

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, s; cin >> n >> s;
    vector<int> a(n);
    
    for(int i=0; i<n; i++) cin >> a[i];
    
    int l = 0, res = 1e12;
    int sum = 0;
    
    for(int r=0; r<n; r++) {
        sum+=a[r];
        if(sum>=s && r-l+1<res) res = r-l+1;
        
        while(sum-a[l]>=s) {
            sum-=a[l];
            l++;
            if(r-l+1<res) res = r-l+1;
        }
    }
    
    if(res==1e12)  cout << -1 << '\n';
    else           cout << res << '\n';
}