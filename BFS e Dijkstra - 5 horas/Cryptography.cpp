// https://codeforces.com/gym/101845/problem/C

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6;
const int oo = 1e6;

vector<vector<int>> dist;
int n, m; 
vector<vector<pair<int,int>>> adj;
int res = 0;

void dijkstra(int src){
	for(int i=0; i<94; i++) dist[src][i] = oo;
	set<pair<int,int>> st;

	st.insert({0, src});
	dist[src][src] = 0;

	while(not st.empty()){
		int cur = st.begin()->second; st.erase(st.begin());
		for(auto [viz, c] : adj[cur]){
			if(dist[src][cur] + c < dist[src][viz]){
				st.erase({dist[src][viz], viz});
				dist[src][viz] = dist[src][cur] + c;
				st.insert({dist[src][viz], viz});
			}
		}
	}
}

signed main(){
	string s, t; cin >> s >> t;

	cin >> m;
	adj.resize(94);
	dist.resize(94);
	for(int i=0; i<94; i++) {
	    dist[i].resize(94);
	}
	for(int i=0; i<m; i++){
		char a, b; cin >> a >> b;
		int c; cin >> c;

		adj[int(a)-33].push_back({int(b)-33, c});
	}

	int lim = s.size();

	for(int i=0; i<94; i++) {
		dijkstra(i);
	}

	bool valid = true;

	for(int i=0; i<lim; i++) {
	    char si = s.at(i);
	    char ti = t.at(i);
		if(dist[int(si)-33][int(ti)-33]==oo) {
			valid = false;
			break;
		} else {
			res+=dist[int(si)-33][int(ti)-33];
		}
	}

	if(valid) cout << res << '\n';
	else cout << -1 << '\n';
}