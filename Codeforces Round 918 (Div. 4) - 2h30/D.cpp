#include <bits/stdc++.h>
using namespace std;
#define int long long

bool vowel(char l) {
	if(l=='a' or l=='e') return true;
	return false;
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--){
		int n; cin >> n;

		vector<char> in(n);

		for(int i=0; i<n; i++){
			cin >> in[i];
		}

		vector<char> res;

		int i = 0;
		while(i<n){
			res.push_back(in[i]);
			res.push_back(in[i+1]);
			i+=2;
			if(i+1==n) {res.push_back(in[i]);i++;}
			else if(i+1<n and !vowel(in[i+1])){
				res.push_back(in[i]);
				i++;
			}
			res.push_back('.');
		}
		int lim = res.size();
		for(int j=0; j<lim-1; j++) {
			cout << res[j];
		}
		cout << '\n';
	}	
}
