#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--){
		int n; cin >> n;

		vector<int> a(n);

		int maxi = 0, maxp = 0;

		for(int i=0; i<n; i++) {
			cin >> a[i];

			if(i%2==0 && a[i]>maxp){
				maxp = a[i];
			}

			if(i%2==1 && a[i]>maxi){
				maxi = a[i];
			}
        }
		cout << max(maxi + floor((double) n/2) , maxp + ceil((double) n/2)) << '\n';

	}	
}
