// https://codeforces.com/gym/101149/problem/I

#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> bss;
vector<bool> visitados;
vector<int> pol;
vector<int> deg;
int mindeg = 1e9;
int imin = -1;
int res = 0;

void dfs(int a) {
	visitados[a] = true;
	for(int b : bss[a]){
        deg[a]++;
		if(!visitados[b]){
			dfs(b);
		}
	}
    if(deg[a]<mindeg) {
        mindeg = deg[a];
        imin = a;
    }
}

signed main() {
	int qv, qa; cin >> qv >> qa;
	bss.resize(qv);
	visitados.resize(qv, false);
	pol.resize(qv, 1);
	deg.resize(qv, 0);

	for(int i=0; i<qa; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		bss[a].push_back(b);
		bss[b].push_back(a);
	}

    for(int i=0; i<qv; i++){
        if(not visitados[i]) dfs(i);
    }

	pol[imin] = 0;
    for(int b : bss[imin]){
	    pol[b] = 0;
	}
	for(int i=0; i<qv; i++) {
	    cout << pol[i] << ' ';
	}
	cout << '\n';
}