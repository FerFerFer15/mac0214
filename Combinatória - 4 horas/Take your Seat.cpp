// https://codeforces.com/gym/102222/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int double

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
  	
  	long t; cin >> t;
  	
  	for(long i=1; i<=t; i++) {
  	    int n,m; cin >> n >> m;
  	    
  	    int res1, res2;
  	    
  	    if(n==1) res1 = 1.0;
  	    else         res1 = 0.5;
  	    
  	    res2 = (m+1)/(2.0*m);
  	    
  	    cout << fixed << setprecision(6) << "Case #" << i << ": " << res1 << ' ' << res2 << '\n';
  	}
}