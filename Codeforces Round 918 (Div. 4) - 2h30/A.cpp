#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--){
		int a,b,c; cin >> a >> b >> c;

		if(a==b) cout << c << '\n';
		else if(a==c) cout << b << '\n';
		else cout << a << '\n';
	}
}
