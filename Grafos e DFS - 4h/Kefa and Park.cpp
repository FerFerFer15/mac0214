// https://codeforces.com/contest/580/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> bss;
vector<int> agua;
vector<bool> visitados;
int res = 0;
int m;

void dfs(int a, int seq) {
    if(!visitados[a]){
        visitados[a] = true;
        if(agua[a]==1){
            seq++;
        } else {
            seq = 0;
        }
        if(seq<=m){
            if(bss[a].size()==1 && a!=0){
        	   res++;
        	}
        	for(int b : bss[a]) {
        		dfs(b,seq);
        	}
        }
    }
}

signed main() {
	int n; cin >> n >> m;
	bss.resize(n);
	visitados.resize(n,false);
	agua.resize(n);

	for(int i=0; i<n; i++) {
		cin >> agua[i];
	}

	for(int i=0; i<n-1; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		bss[a].push_back(b);
		bss[b].push_back(a);
	}

	dfs(0,0);
	

    cout << res << endl;
}