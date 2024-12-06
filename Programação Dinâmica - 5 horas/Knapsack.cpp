// https://atcoder.jp/contests/dp/tasks/dp_d

#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	int n, w; cin >> n >> w;

	vector<int> ars(w+1, 0), brs(w+1, 0);
	vector<vector<int>> es(w+1, vector<int>(n,0));
	vector<int> ts(n), vs(n);


	for(int i=0; i<n; i++) {
	cin >> ts[i] >> vs[i];
	}

	for(int i=n-1; i>=0; i--) {
		for(int c=1; c<=w; c++) {
			int& r = ars[c];
			int& e = es[c][i];
			int r1 = 0; 
			if(ts[i] <= c)
				r1 = brs[c-ts[i]] + vs[i];
			int r2 = brs[c];
			if(r1 > r2) {
				r = r1;
				e = 1;	
			}
			else {
				r = r2;
				e = 0;
			}
		}
		swap(ars, brs);
	}

	cout << brs[w] << '\n';
}
