#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--){
		int n, k; cin >> n >> k;
		string s; cin >> s;
		int res = 0;
		for(int i=0; i<n; i++){
			if(s.at(i)=='B') {
				res++;
				i+=k-1;
			}
		}

		cout << res << '\n';
	}	
}
