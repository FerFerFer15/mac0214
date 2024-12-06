// https://www.spoj.com/problems/EZDIJKST/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1e6;
const ll oo = 1e18;

ll dist[MAX];
int t, n, m, a, b; 

void dijkstra(int src, vector<vector<pair<int,ll>>> &adj){
	for(int i=1; i<=n; i++) dist[i] = oo;
	set<pair<ll,int>> st;

	st.insert({0, src});
	dist[src] = 0;

	while(not st.empty()){
		int cur = st.begin()->second; st.erase(st.begin());
		for(auto [viz, c] : adj[cur]){
			if(dist[cur] + c < dist[viz]){
				st.erase({dist[viz], viz});
				dist[viz] = dist[cur] + c;
				st.insert({dist[viz], viz});
			}
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;

    while(t--) {
        cin >> n >> m;
        vector<vector<pair<int,ll>>> adj;
        adj.resize(n+1);
        for(int i=0; i<m; i++){
            int a, b; ll c;
        cin >> a >> b >> c;
            adj[a].push_back({b, c});
        }
        cin >> a >> b;
        dijkstra(a, adj);
        if(dist[b]==oo) {
            cout << "NO" << '\n';
        } else {
            cout << dist[b] << '\n';
        }
    }
}