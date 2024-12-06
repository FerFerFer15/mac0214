// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A

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

	int qv, qq; cin >> qv >> qq;
	vector<int> ps(qv, -1), ws(qv, 1);

	for(int i=0; i<qq; i++) {
		int a, b; string c;
		cin >> c >> a >> b;
		a--; b--;
		if(c == "union")
			join(ps, ws, a, b);
		else if(c == "get") {
			if(find(ps, a) == find(ps, b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}

	return 0;
}