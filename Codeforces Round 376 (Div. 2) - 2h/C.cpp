#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> bss;
vector<bool> visitados;
vector<int> c;

void dfs(int a, vector<int>& q) {
	visitados[a] = true;
	q.push_back(c[a]);
	for(int b : bss[a]){
		if(!visitados[b]){
			dfs(b, q);
		}
	}
}

signed main() {
	int n, m, k; cin >> n >> m >> k;
	bss.resize(n);
	visitados.resize(n, false);
	c.resize(n);
    for(int i=0; i<n; i++) {
        cin >> c[i];
        c[i]--;
    }
    
	for(int i=0; i<m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		bss[a].push_back(b);
		bss[b].push_back(a);
	}
	int res = 0;
	for(int i=0; i<n; i++) {
	    vector<int> q;
	    if(!visitados[i]) {
	        dfs(i, q);
	        sort(q.begin(),q.end());
	        int o = q.size();
	        int maxq = 1;
	        int cq = 1;
	        for(int j=0; j<o-1; j++){
	            if(q[j]!=q[j+1]) {
	                if(cq>maxq) maxq = cq;
	                cq = 1;
	            } else cq++;
	        }
            if(cq>maxq) maxq = cq;
	        res+=(o-maxq);
	    }
	}

	cout << res << '\n';
}