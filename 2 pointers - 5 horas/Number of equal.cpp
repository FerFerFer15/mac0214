// https://codeforces.com/edu/course/2/lesson/9/1/practice/contest/307092/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    for(int i=0; i<m; i++) {
        cin >> b[i];
    }
    
    int ia = 0, ib = 0, res = 0;
    
    int buff;
    
    int starta, startb;
    
    while (ia<n) {
        buff = a[ia];
        starta = ia;
        while(ia<n && a[ia]==buff) {
            ia++;
        }
        
        if(b[ib]>a[starta]) continue;
        while(ib<m && b[ib]<a[starta]) {
            ib++;
        }
        if(ib==m) break;
        
        if(b[ib]==a[starta]) {
            buff = b[ib];
            startb = ib;
            while(ib<m && b[ib]==buff){
                ib++;
            }
            
            res+=((ia-starta)*(ib-startb));
        }
    }
    
    cout << res << '\n';
}