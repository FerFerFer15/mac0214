#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--){
		int n, q; cin >> n >> q;
		map <int, int> res;
		vector<int> x(n);

		for(int i=1; i<=n; i++){
			cin >> x[i-1];
			if(res.find(i*(n-i+1)-1)!=res.end()) {
				res[i*(n-i+1)-1]++;
			} else {
				res[i*(n-i+1)-1] = 1;
			}
		}

		for(int i=1; i<=n-1; i++){
			if(res.find(i*(n-i))!=res.end()) {
				res[i*(n-i)]+=x[i]-x[i-1]-1;
			} else {
				res[i*(n-i)]=x[i]-x[i-1]-1;
			}
		}

		for(int i=0; i<q; i++){
			int l; cin >> l;
			if(res.find(l)!=res.end()) {
				cout << res[l] << ' ';
			} else {
				cout << 0 << ' ';
			}
		}

		cout << '\n';

	}	
}
