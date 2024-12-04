#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--){
		char res;
		vector<char> in(9);
		int mark;
		for(int i=0; i<9; i++) {
			cin >> in[i];
			if(in[i]=='?') {
				mark = i;
			}
		}
		if(mark<3) {
			if(in[mark+3]!='A' and in[mark+6]!='A') res = 'A';
			if(in[mark+3]!='B' and in[mark+6]!='B') res = 'B';
			if(in[mark+3]!='C' and in[mark+6]!='C') res = 'C';
		} else if(mark<6) {
			if(in[mark+3]!='A' and in[mark-3]!='A') res = 'A';
			if(in[mark+3]!='B' and in[mark-3]!='B') res = 'B';
			if(in[mark+3]!='C' and in[mark-3]!='C') res = 'C';
		} else {
			if(in[mark-3]!='A' and in[mark-6]!='A') res = 'A';
			if(in[mark-3]!='B' and in[mark-6]!='B') res = 'B';
			if(in[mark-3]!='C' and in[mark-6]!='C') res = 'C';
		}
		cout << res << '\n';
	}	
}
