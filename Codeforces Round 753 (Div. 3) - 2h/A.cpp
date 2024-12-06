#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t; cin >> t;
    while(t--) {
        map<char,int> keyboard;
        
        for(int i=1; i<=26; i++){
            char c; cin >> c;
            keyboard[c] = i;
        }
        
        string s; cin >> s;
        int res = 0;
        int o = s.size();
        for(int i=1; i<o; i++){
            res += abs(keyboard[s.at(i)]-keyboard[s.at(i-1)]);
        }
        
        cout << res << '\n';
    }
}