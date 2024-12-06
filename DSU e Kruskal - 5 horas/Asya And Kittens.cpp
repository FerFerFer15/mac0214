// https://codeforces.com/contest/1131/problem/F

#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adj;
vector<bool> mark;

void dfs(int src) {
    mark[src] = true;
    cout << src+1 << ' ';
    for(int a : adj[src]) {
        if(not mark[a]) dfs(a);
    }
}

int find(vector<int>& ps, int a) {
	vector<int> ms;
	while(ps[a] != -1) {
		ms.push_back(a);
		a = ps[a];
	}
	for(int m : ms) 
		ps[m] = a;
	return a;
}

void join(vector<int>& ps, vector<int>& ws, int a, int b) {
	vector<int> ms;	
	while(ps[a] != -1) {
		ms.push_back(a);
		a = ps[a];
	}
	while(ps[b] != -1) {
		ms.push_back(b);
		b = ps[b];
	}
	if(a != b) {
		if(ws[a] < ws[b])
			swap(a,b);
		ws[a] += ws[b];
		ms.push_back(b);
	}
	for(int m : ms) 
		ps[m] = a;
}

signed main() {

	int qv; cin >> qv;
	vector<int> ps(qv, -1), ws(qv, 1);
	
	adj.resize(qv);
	mark.resize(qv,false);

	for(int i=0; i<qv-1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		
		int u, v;
		u = find(ps, a);
		v = find(ps, b);
		
		join(ps, ws, a, b);
		
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	dfs(0);
	cout << '\n';
}