// https://codeforces.com/group/xR6OpxQBMc/contest/215144/problem/F

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
const int oo = 1e9;

vector<int> dist1;
vector<int> dist2;
vector<int> amigos;
int n, m, x; 
vector<vector<pair<int,int>>> adj;
int res = oo;

void dijkstra(int src){
	for(int i=0; i<n; i++) dist1[i] = oo;
	set<pair<int,int>> st;

	st.insert({0, src});
	dist1[src] = 0;

	while(not st.empty()){
		int cur = st.begin()->second; st.erase(st.begin());
		for(auto [viz, c] : adj[cur]){
			if(dist1[cur] + c < dist1[viz]){
				st.erase({dist1[viz], viz});
				dist1[viz] = dist1[cur] + c;
				st.insert({dist1[viz], viz});
			}
		}
	}
}

void dijkstra2(int src){
	for(int i=0; i<n; i++) dist2[i] = oo;
	set<pair<int,int>> st;

	st.insert({0, src});
	dist2[src] = 0;

	while(not st.empty()){
		int cur = st.begin()->second; st.erase(st.begin());
		for(auto [viz, c] : adj[cur]){
			if(dist2[cur] + c < dist2[viz]){
				st.erase({dist2[viz], viz});
				dist2[viz] = dist2[cur] + c;
				st.insert({dist2[viz], viz});
			}
		}
	}
}

signed main(){
	cin >> n >> m >> x;
	adj.resize(n);
	dist1.resize(n);
	dist2.resize(n);
	amigos.resize(x);
	for(int i=0; i<m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		u--; v--;

		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	
	for(int i=0; i<x; i++) {
	    cin >> amigos[i];
	    amigos[i]--;
	}
	
	dijkstra(0);
	dijkstra2(n-1);

	for(int i=0; i<x; i++) {
	    if(dist1[amigos[i]]+dist2[amigos[i]] < res) res = dist1[amigos[i]]+dist2[amigos[i]];
	}
	
	cout << res << '\n';
}