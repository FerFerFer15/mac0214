#include <bits/stdc++.h>
using namespace std;
#define int long long

int minx, maxx, miny, maxy;
 
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
 
    int t; cin >> t;
 
    while(t--) {
        int n, m; cin >> n >> m;

        minx = miny = 1e7;
        maxx = maxy = -1;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                char c; cin >> c;

                if(c=='#') {
                    if(i>maxx) maxx = i;
                    if(i<minx) minx = i;

                    if(j>maxy) maxy = j;
                    if(j<miny) miny = j;
                }
            }
        }
 
        cout << (maxx+minx)/2 << " " << (maxy+miny)/2 << '\n';
    }
}