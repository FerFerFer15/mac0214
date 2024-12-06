// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/F

#include <bits/stdc++.h>
using namespace std;
#define int long long


vector<int> a;
string t, p;
int ts, tp;

bool valid(int mid) {
    string s = t;
    for(int i=0; i<=mid; i++){
        s[a[i]] = '.';
    }
    int x = 0;
    
    for(int y=0; y<ts; y++){
        if(s.at(y)==p.at(x)) {
            x++;
            if(x>=tp) return true;
        }
    }
    
    return false;
}

signed main(){
    cin >> t >> p;
    ts = t.size(); tp = p.size();
    for(int i=0; i<ts; i++){
        int l; cin >> l; l--;
        a.push_back(l);
    }
    
    int lo = 0;
    int hi = ts-1;
    int mid;
    int midres = -1;

    while(lo<=hi){
        mid = (lo+hi)/2;
        
        if(valid(mid)){
            lo = mid+1;
            midres = mid;
        } else {
            hi = mid-1;
        }
    }
    
    if(midres>=0) cout << midres+1 << '\n';
    else cout << 0 << '\n';
}
