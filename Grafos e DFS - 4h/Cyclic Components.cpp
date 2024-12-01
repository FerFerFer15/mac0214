// https://codeforces.com/contest/977/problem/E

#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> bss;
vector<bool> visitados;
vector<int> deg;
int res = 0;
bool valid;

void dfs(int a) {
	visitados[a] = true;
	for(int b : bss[a]){
	    deg[a]++;
		if(!visitados[b]){
			dfs(b);
		}
	}
	if(deg[a]!=2) valid = false;
}

signed main() {
	int qv, qa; cin >> qv >> qa;
	bss.resize(qv);
	visitados.resize(qv, false);
	deg.resize(qv, 0);

	for(int i=0; i<qa; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		bss[a].push_back(b);
		bss[b].push_back(a);
	}
	
	for(int i=0; i<qv; i++) {
	    if(!visitados[i]) {
	        valid = true;
	        dfs(i);
	        if(valid) res++;
	    }
	}

	cout << res << '\n';
}