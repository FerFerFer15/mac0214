#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string l;
        vector<int> print;
        for(int i=0; i<n; i++){
            cin >> l;
            if(l.at(0)=='#'){
                print.push_back(1);
            } else if(l.at(1)=='#'){
                print.push_back(2);
            } else if(l.at(2)=='#'){
                print.push_back(3);
            } else if(l.at(3)=='#'){
                print.push_back(4);
            }
        }
        for(int i=n-1; i>=0; i--){
            cout << print[i] << ' ';
        }
        cout << '\n';
    }
}