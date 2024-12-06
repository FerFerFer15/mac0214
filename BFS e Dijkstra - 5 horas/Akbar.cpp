// https://www.spoj.com/problems/AKBAR/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1e7+100;
const int oo = 1e18;

bool opt;

int t, n, r, m, qtd; 


void bfs(int src, int str, vector<vector<int>> &adj, vector<bool> &mark, vector<int> &dist){
	queue<int> q;

	q.push(src);
    if(mark[src]) {
        opt = false;
        return;
    }
	mark[src] = true;
    qtd++;
	dist[src] = 0;

    int newdis = 1;

	while((not q.empty())){
		int cur = q.front(); q.pop();
		for(auto viz : adj[cur]){
			if(mark[viz] || 1 + dist[cur]>str) continue;
			q.push(viz);
            if(mark[viz]) {
                opt = false;
                return;
            }
			mark[viz] = true;
            qtd++;
			dist[viz] = 1 + dist[cur];
		}
	}
}

signed main(){
    cin >> t;
    while(t--) {
        opt = true;
        cin >> n >> r >> m;
        vector<vector<int>> adj(n+1);
        vector<bool> mark(n+1, false);
        vector<int> dist(n+1,0);

        qtd = 0;

        for(int i=0; i<r; i++){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=0; i<m; i++){
            int k, s; cin >> k >> s;
            bfs(k,s,adj,mark,dist);
        }

        if(qtd!=n) opt = false;

        if(opt) cout << "Yes" << '\n';
        else    cout << "No"  << '\n';
    }
}