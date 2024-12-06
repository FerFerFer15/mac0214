// https://codeforces.com/problemset/problem/1256/C
 
#include <bits/stdc++.h> 
using namespace std; 
#define int long long

signed main() { 
    ios_base::sync_with_stdio(false); cin.tie(NULL); 
    
    int n,m,d; cin >> n >> m >> d;

    vector<int> tam(m);
    for(int i=0; i<m; i++){
        cin >> tam[i];
    }

    vector<int> riv(n,0);
    int pos = n-1;
    for(int i=m-1; i>=0; i--){
        int j;
        for(j=pos; j>=(pos-tam[i]+1); j--){
            riv[j] = i+1;
        }
        pos = j;
    }
    pos++;

    int jmp = -1;
    int plat = 1;
        jmp+=d;
    while(jmp<n and plat<=m){
        if(riv[jmp]==0){
            int i = jmp;
            while(pos<n && riv[pos]==plat){
                riv[i] = plat;
                riv[pos] = 0;
                i++; pos++;
            }
            jmp = i-1;
            if(jmp+d<n) plat++;
        } else {
            while(jmp+1<n && riv[jmp+1]!=0){
                jmp++;
            }
            plat = riv[jmp]+1;
        }
        jmp+=d;
    }

    if(jmp>=n){
        cout << "YES\n";
        for(int i=0; i<n; i++){
            cout << riv[i] << ' ';
        }
    } else {
        cout << "NO\n";
    }
    cout << '\n';

}