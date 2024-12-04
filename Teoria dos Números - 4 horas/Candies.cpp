// https://codeforces.com/contest/1343/problem/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
  	
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int l = 2;
		for(int i=2; i<30; i++){
			l*=2;
			l--;
			if(n%l==0){
				cout << n/l << '\n';
				break;
			}
			l++;
		}
	}
	
}