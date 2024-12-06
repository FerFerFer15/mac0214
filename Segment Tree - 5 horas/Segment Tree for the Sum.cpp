// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1e5+100;
const int oo = 2e9;

int n, m;
int val[4*MAX];
int arr[MAX];

const int neutral_value = 0;

int merge(int v1, int v2){
	return v1+v2;
}

void build_rec(int id, int tl, int tr){
	if(tl == tr){
		val[id] = arr[tl];
	}
	else{
		int mid = (tl+tr)/2;
		build_rec(2*id, tl, mid);
		build_rec(2*id+1, mid+1, tr);
		val[id] = merge(val[2*id], val[2*id+1]);
	}
}

void build(){
	build_rec(1, 1, n);
}

void update_rec(int id, int tl, int tr, int pos, int x){
	if(tl == tr){
		val[id] = x;
	}
	else{
		int mid = (tl+tr)/2;
		if(pos <= mid)
			update_rec(2*id, tl, mid, pos, x);
		else
			update_rec(2*id+1, mid+1, tr, pos, x);
		val[id] = merge(val[2*id], val[2*id+1]);
	}
}

void update(int pos, int x){
	update_rec(1, 1, n, pos, x);
}

int query_rec(int id, int tl, int tr, int l, int r){
	if(tr < l or r < tl) return neutral_value;
	if(l <= tl and tr <= r) return val[id];
	int mid = (tl+tr)/2;
	int q1 = query_rec(2*id, tl, mid, l, r);
	int q2 = query_rec(2*id+1, mid+1, tr, l, r);
	return merge(q1, q2);
}

int query(int l, int r){
	return query_rec(1, 1, n, l, r);
}

signed main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) cin >> arr[i];
	build();
	while(m--){
		int op; cin >> op;
		if(op == 1){
			int p, x; cin >> p >> x;
			update(p+1, x);
		}
		if(op == 2){
			int l, r; cin >> l >> r;
			cout << query(l+1, r) << '\n';
		}

		
	}
}