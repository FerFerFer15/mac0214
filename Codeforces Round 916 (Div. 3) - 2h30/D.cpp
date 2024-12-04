#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        vector<pair<int,int>> a(n);
        vector<pair<int,int>> b(n);
        vector<pair<int,int>> c(n);

        int f;
        for(int i=0; i<n; i++){
            cin >> f;
            a[i] = {f,i};
        }
        for(int i=0; i<n; i++){
            cin >> f;
            b[i] = {f,i};
        }
        for(int i=0; i<n; i++){
            cin >> f;
            c[i] = {f,i};
        }

        sort(a.begin(),a.end(),greater<>());
        sort(b.begin(),b.end(),greater<>());
        sort(c.begin(),c.end(),greater<>());

        int res = 0;

        for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
                for(int k=0; k<3; k++)
                    if(a[i].second!=b[j].second && a[i].second!=c[k].second && c[k].second!=b[j].second) 
                        res = max(res, a[i].first + b[j].first + c[k].first);

        cout << res << '\n';
    }
}