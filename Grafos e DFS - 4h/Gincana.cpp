// https://olimpiada.ic.unicamp.br/pratique/pj/2011/f2/gincana/

#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> bss;
vector<bool> visitados;

void dfs(int a) {
	visitados[a] = true;
	for(int b : bss[a]){
		if(!visitados[b]){
			dfs(b);
		}
	}
}

signed main() {
    int res=0;
	int qv, qa; cin >> qv >> qa;
	bss.resize(qv);
	visitados.resize(qv, false);

	for(int i=0; i<qa; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		bss[a].push_back(b);
		bss[b].push_back(a);
	}

    

	for(int i=0; i<qv; i++) {
		if(not visitados[i]) {
            dfs(i);
            res++;
        }
	}

    cout << res << '\n';
}