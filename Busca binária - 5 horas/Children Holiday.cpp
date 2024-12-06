// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long
int oo = 1e5;

int n,m;
vector<array<int,3>> a;
vector<int> res;

int calc(int i, int x) {
    int val = a[i][0]*a[i][1]+a[i][2];
    int res = (x/val) * a[i][1] + min((x%val)/a[i][0],a[i][1]);
    
    return res;
}

void att(int l) {
    for(int i=1; i<=n; i++){
        res[i] = calc(i,l);
    }
}

signed main(){
    cin >> m >> n;
    res.resize(n+1);
    a.push_back({-1,-1,-1});
    for(int i=1; i<=n; i++){
        int t,z,y; cin >> t >> z >> y;
        a.push_back({t,z,y});
    }

    if(m==0){
        cout << 0 << '\n';
        
        for(int i=1; i<=n; i++){
            cout << 0 << ' ';
        }
        
        cout << '\n';
    } else {
        int lo = 1;
        int hi = m*200;
        int mid;
        int midres;
        int sumres;
    
        while(lo<=hi){
            mid = (lo+hi)/2;
            int sum = 0;
            for(int i=1; i<=n; i++){
                sum+=calc(i,mid);
            }
            
            if(sum>=m){
                hi = mid-1;
                sumres = sum;
                att(mid);
                midres = mid;
            } else {
                lo = mid+1;
            }
        }
        
        int c = n;
        
        while(sumres>m and c>0){
            int sub = min(sumres-m, res[c]);
            sumres -= sub;
            res[c] -= sub;
            c--;
        }
    
        cout << midres << '\n';
        
        for(int i=1; i<=n; i++){
            cout << res[i] << ' ';
        }
        
        cout << '\n';
    }
}
