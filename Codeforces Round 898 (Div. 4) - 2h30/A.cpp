#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--){
		string l; cin >> l;

		if(l=="bca" or l=="cab") cout << "NO\n";
		else cout << "YES\n";
	}	
}
