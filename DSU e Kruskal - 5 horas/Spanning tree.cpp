// https://codeforces.com/edu/course/2/lesson/7/2/practice/contest/289391/problem/E

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

	int qv, qr, ct = 0; cin >> qv >> qr;
	vector<int> ps(qv, -1), ws(qv, 1);
	vector<array<int,3>> rs(qr);
	vector<array<int,3>> srs;

	for(array<int,3>& r : rs) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		r = {c, a, b};
	}

	sort(rs.begin(), rs.end());

	for(array<int,3>& r : rs) {
		if(find(ps, r[1]) != find(ps, r[2])) {
			ct += r[0];
			srs.push_back(r);
			join(ps, ws, r[1], r[2]);
		}
	}

	cout << ct << '\n';
}