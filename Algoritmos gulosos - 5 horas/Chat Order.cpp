// https://codeforces.com/contest/637/problem/B

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    map<string,bool> printed;
    
    int n; cin >> n;
    
    vector<string> names(n);
    for(int i=0; i<n; i++){
        cin >> names[i];
        printed[names[i]] = false;
    }
    
    for(int i=n-1; i>=0; i--){
        if(!printed[names[i]]){
            cout << names[i] << '\n';
            printed[names[i]] = true;
        }
    }
}