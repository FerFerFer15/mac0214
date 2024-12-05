#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int t; cin >> t;
  while(t--){
	int n; cin >> n;
	int maxid = 0, maxq = 0;
	for(int i=1; i<=n; i++){
	    int w, q; cin >> w >> q;
	    if(w<=10 and q>maxq){
	        maxq = q;
	        maxid = i;
	    }
	}
	
	cout << maxid << '\n';
  }
}
