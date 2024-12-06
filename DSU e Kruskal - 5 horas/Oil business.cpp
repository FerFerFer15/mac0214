// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/H

#include<bits/stdc++.h>
using namespace std;
#define int long long

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

	int qv, qr, s; cin >> qv >> qr >> s;
	vector<int> ps(qv, -1), ws(qv, 1);
	vector<array<int,4>> rs(qr);
	vector<array<int,4>> srs;

	vector<bool> del(qr,true);

	int d = 0;
	int sum = 0;
	for(array<int,4>& r : rs) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		r = {c, a, b, d};
		d++;
	}

	sort(rs.rbegin(), rs.rend());

	for(array<int,4>& r : rs) {
		if(find(ps, r[1]) != find(ps, r[2])) {
			srs.push_back(r);
			join(ps, ws, r[1], r[2]);
			del[r[3]] = false;
		}
	}

	sort(rs.begin(), rs.end());

	vector<int> res;

	for(array<int,4>& r : rs) {
		if(del[r[3]]) {
			if(sum+r[0]<=s) {
				res.push_back(r[3]);
				sum+=r[0];
			}
		}
	}

	if(res.size()>0) sort(res.begin(), res.end());

	int lim = res.size();
	cout << lim << '\n';
	for(int i=0; i<lim; i++){
		cout << res[i]+1 << ' ';
	}

	cout << '\n';
}