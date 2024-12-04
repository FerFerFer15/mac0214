// https://neps.academy/br/exercise/4
 
#include <bits/stdc++.h> 
using namespace std; 
#define int long long

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    bool possible = true;
    int sum = min(a[0], m-a[0]);
    int last = sum;
    
    for(int i=1; i<n; i++){
        if(min(a[i], m-a[i]) >= last){
            sum+=min(a[i], m-a[i]);
            last=min(a[i], m-a[i]);
        } else if(max(a[i], m-a[i]) >= last) {
            sum+=max(a[i], m-a[i]);
            last=max(a[i], m-a[i]);
        } else {
            possible = false;
            break;
        }
    }
    
    if(possible) cout << sum << '\n';
    else cout << -1 << '\n';
}