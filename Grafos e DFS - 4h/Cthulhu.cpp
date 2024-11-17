#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 1e5+100;
bool vis[MAX];
int c = 0;
int comp = 0;
vector<int> adj[MAX];
int edgeTo[MAX];

void dfs(int u, int p) {
	vis[u] = true;
	edgeTo[u] = p;
	for(int& v : adj[u]){
		if(v == p) continue;
		if(not vis[v]){
			dfs(v, u);
		}
		else if(u!=edgeTo[v]) {
			c++;
		}
	}
}

signed main(){
	int n, m; cin >> n >> m;

	for(int i=0; i<m; i++){
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	int i=1;
	while(i<=n){
	    if(not vis[i]){
	        dfs(i,i);
	        comp++;
	    }
	    i++;
	}
    
	if(c==2 && comp==1) cout << "FHTAGN!\n";
	else             cout << "NO\n";
}