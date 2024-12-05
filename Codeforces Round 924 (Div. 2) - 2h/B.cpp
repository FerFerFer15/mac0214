#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int t; cin >> t;
  while(t--){
	int n; cin >> n;
	set<int> s;
	for(int i=0; i<n; i++){
	    int l; cin >> l;
	    s.insert(l);
	}
	
	vector<int> a;
	while(!s.empty()){
	    a.push_back(*s.begin());
	    s.erase(s.begin());
	}
	int o = a.size();
	
	int l = 0;
	int res = 0;
	for(int r=0; r<o; r++){
	    while(a[r] - a[l] > n-1){
	        l++;
	    }
	    if(r-l+1>res){
	        res = r-l+1;
	    }
	}
	cout << res << '\n';
  }
}
