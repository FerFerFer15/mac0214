#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		sort(a.begin(),a.end());
		a[0]++;
		int res = 1;
		for(int i=0; i<n; i++){
			res*=a[i];
		}
		cout << res << '\n';
	}	
}
