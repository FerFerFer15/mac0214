#include <bits/stdc++.h> 
using namespace std; 
#define int long long

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    int n; cin >> n;
    bool seq = false;
    int sum = 0;
    int q = 0;
    int zero = 0;
    char c;
    
    while(n--) {
        cin >> c;
        if(c=='x' && seq) {
            q++;
        } else if (c=='x' && !seq) {
            seq = true;
            q = 1;
        } else {
            seq = false;
            sum += max(zero,q-2);
            q = 0;
        }
    }
    
    sum += max(zero,q-2);
    
    cout << sum << '\n';
    
}