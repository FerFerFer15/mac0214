// https://neps.academy/br/exercise/682

#include <bits/stdc++.h>
using namespace std;
#define int long long
int oo = -1e16;

int n, k;
vector<array<int,4>> a;
bool possible = false;

int area(int mid) {
    int i=0;
    int sumarea = 0;
    while(i<n and a[i][0]<=mid) {
        sumarea+=((a[i][3]-a[i][1])*(min(mid,a[i][2])-a[i][0]));
        i++;
    }
    
    return sumarea;
}

signed main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
        a.push_back({ya,xa,yb,xb});
    }
    
    sort(a.begin(),a.end());
    
    int lo = a[0][0]-1;
    int hi = a[n][0]+1;
    int mid;
    int midres = oo;

    while(lo<=hi){
        mid = (lo+hi)/2;
        if(area(mid)>=k){
            hi = mid-1;
            midres = mid;
        } else {
            lo = mid+1;
        }
    }
    
    if(midres>oo) cout << midres << '\n';
    else cout << "PERDAO MEU REI" << '\n';
}
