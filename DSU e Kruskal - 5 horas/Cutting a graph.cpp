// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D

#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<int>> adj;
vector<pair<string,array<int,2>>> opps;
vector<string> res;

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

	int qv, qe, qq; cin >> qv >> qe >> qq;
	vector<int> ps(qv, -1), ws(qv, 1);
	
	adj.resize(qv);
	
	for(int i=0; i<qe; i++) {
	    int a, b; cin >> a >> b;
	    a--; b--;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}

	for(int i=0; i<qq; i++) {
		int a, b; string c;
		cin >> c >> a >> b;
		a--; b--;
		opps.push_back({c,{a,b}});
	}
	
	int qres = 0;
	
	for(int i=qq-1; i>=0; i--) {
	    if(opps[i].first=="cut") {
	        join(ps,ws,opps[i].second[0],opps[i].second[1]);
	    } else if (opps[i].first=="ask") {
	        if(find(ps,opps[i].second[0])==find(ps,opps[i].second[1])) {
	            res.push_back("YES");
	        } else {
	            res.push_back("NO");
	        }
	        qres++;
	    }
	}
	
	for(int i = qres-1; i>=0; i--) {
	    cout << res[i] << '\n';
	}

}