#include <bits/stdc++.h>
using namespace std;
#define int long long



void dfs(int a, vector<bool>& visitados, vector<int>& pos, vector<vector<array<int, 2>>>& bss) {
    if(!visitados[a]){
        visitados[a] = true;
    	for(array<int,2> b : bss[a]) {
    	    pos[b[0]] = pos[a] - b[1];
    		dfs(b[0], visitados, pos, bss);
    	}
    }
}

signed main() {
    int t; cin >> t;
    while(t--) {
    	int n, m; cin >> n >> m;
    	vector<vector<array<int, 2>>> bss;
        vector<bool> visitados;
        vector<array<int,3>> queries;
        vector<int> pos;
    	bss.resize(n);
    	pos.resize(n,0);
    	visitados.resize(n,false);
    	
    	for(int i=0; i<m; i++) {
    		int a, b, d; cin >> a >> b >> d;
    		a--; b--;
    		queries.push_back({a,b,d});
    		bss[a].push_back({b,d});
    		bss[b].push_back({a,-d});
    	}
    
        for(int i=0; i<n; i++){
            if(!visitados[i]) {
                pos[i] = 0;
                dfs(i, visitados, pos, bss);
            }
        }
        
        bool possible = true;
        for(int i=0; i<m; i++){
            if(!(pos[queries[i][0]]-pos[queries[i][1]]==queries[i][2])){
                possible = false;
            }
        }
        
        if(possible) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    	
    }
}