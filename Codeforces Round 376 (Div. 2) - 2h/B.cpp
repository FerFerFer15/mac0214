#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    bool possible = true;
    
    for(int i=0; i<n; i++){
        if(i<n-1){
            if(a[i]%2!=0 and a[i+1]==0){
                possible = false; break;
            } else {
                if(a[i]%2!=0){
                    a[i+1]--;
                }
                a[i] = 0;
            }
        } else {
            if(a[i]%2!=0){
                possible = false;
            }
        }
    }
    
    if(possible) cout << "YES\n";
    else cout << "NO\n";
}