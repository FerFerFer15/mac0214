#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int t; cin >> t;
  while(t--){
	int a, b; cin >> a >> b;

	if(min(a,b)%2==0 || (max(a,b)%2==0 and max(a,b)/2!=min(a,b))){
	    cout << "YES\n";
	} else {
	    cout << "NO\n";
	}
  }
}
