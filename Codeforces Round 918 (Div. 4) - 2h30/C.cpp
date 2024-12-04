#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--){
		int n; cin >> n;
		int a, sum = 0;
		for(int i = 0; i<n; i++) {
			cin >> a;
			sum+=a;
		}

		if(floor(sqrt(sum))*floor(sqrt(sum))==sum) cout << "YES\n";
		else cout << "NO\n";
	}	
}
