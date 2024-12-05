#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int t; cin >> t;
  while(t--){
	vector<int> a(3);
	
	cin >> a[0] >> a[1] >> a[2];
	
	sort(a.begin(), a.end());
	
	if(a[1]+a[2]>=10){
	    cout << "YES\n";
	} else {
	    cout << "NO\n";
	}
  }
}
