#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int t; cin >> t;
  while(t--){
      vector<char> res;
	  for(int i=0; i<64; i++){
	      char c; cin >> c;
	      if(c!='.') res.push_back(c);
	  }
	  
	  int l = res.size();
	  for(int i=0; i<l; i++){
	      cout << res[i];
	  }
	  cout << '\n';
  }
}
