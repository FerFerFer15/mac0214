#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    vector<vector<int>> dist(26);
    for(int i=0; i<26; i++){
        dist[i].resize(26);
    }
    for(int i=0; i<26; i++){
        for(int j=0; j<26; j++){
            dist[i][j] = min(abs(i-j), 26-(abs(i-j)));
        }
    }
    string s; cin >> s;
    
    int last = 0, o = s.size(), res = 0;
    for(int i=0; i<o; i++){
        int val = (int) s.at(i);
        val-=97;
        res+=dist[val][last];
        last = val;
    }
    
    cout << res << '\n';
}