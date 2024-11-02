#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--){
        string s1, s2; cin >> s1 >> s2;
        int t1 = s1.size();
        int t2 = s2.size();
        vector<char> res(t1);

        int i = 0, j = 0;
        while(i<t1 && j<t2) {
            if(s1.at(i)=='?' || s1.at(i)==s2.at(j)) {
                res[i] = s2.at(j);
                i++;
                j++;
            } else {
                res[i] = s1.at(i);
                i++;
            }
        }

        while(i<t1) {
            if(s1.at(i)=='?') res[i] = 'a';
            else              res[i] = s1.at(i);
            i++;
        }

        if(j==t2) {
            cout << "YES" << '\n';
            for(int k=0; k<t1; k++) {
                cout << res[k];
            }
            cout << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}