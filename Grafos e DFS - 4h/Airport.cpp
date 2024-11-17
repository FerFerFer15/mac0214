// https://neps.academy/exercise/290

#include<bits/stdc++.h>
using namespace std;
#define int long long


int maxdeg;
int c = 1;

signed main() {
	int qv, qa; cin >> qv >> qa;
	while(qv!=0 and qa!=0) {
		maxdeg = 0;
		vector<vector<int>> bss;
		vector<int> deg;
		bss.resize(qv);
		deg.resize(qv, 0);

		for(int i=0; i<qa; i++) {
			int a, b; cin >> a >> b;
			a--; b--;
			bss[a].push_back(b);
			bss[b].push_back(a);
		}
		
		for(int i=0; i<qv; i++) {
			for(int b : bss[i]){
        	    deg[i]++;
        	}
        	if(deg[i]>maxdeg) maxdeg = deg[i];
		}

		cout << "Teste " << c << '\n';
		c++;
		for(int i=0; i<qv; i++){
			if(deg[i]==maxdeg) cout << i+1 << ' ';
		}
		cout << "\n\n";
		cin >> qv >> qa;
	}
}