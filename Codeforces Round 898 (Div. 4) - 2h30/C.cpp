#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--){
		int res = 0;
		for(int i=1; i<=10; i++){
			for(int j=1; j<=10; j++){
				char c; cin >> c;
				if(c=='X') {
					res+=min(min(i,10-i+1),min(j,10-j+1));
				}
			}
		}

		cout << res << '\n';
	}	
}
