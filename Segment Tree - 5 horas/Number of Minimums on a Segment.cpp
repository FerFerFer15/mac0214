// https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1e5+100;
const int oo = 2e9;

int n, m;
array<int,2> val[4*MAX];
array<int,2> arr[MAX];

const array<int,2> neutral_value = {oo,0};

array<int,2> merge(array<int,2> v1, array<int,2> v2){
	if(v1[0]<v2[0]) return v1;
	if(v1[0]>v2[0]) return v2;
	else            return {v1[0],v1[1]+v2[1]};
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

void update_rec(int id, int tl, int tr, int pos, array<int,2> x){
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

void update(int pos, array<int,2> x){
	update_rec(1, 1, n, pos, x);
}

array<int,2> query_rec(int id, int tl, int tr, int l, int r){
	if(tr < l or r < tl) return neutral_value;
	if(l <= tl and tr <= r) return val[id];
	int mid = (tl+tr)/2;
	array<int,2> q1 = query_rec(2*id, tl, mid, l, r);
	array<int,2> q2 = query_rec(2*id+1, mid+1, tr, l, r);
	return merge(q1, q2);
}

array<int,2> query(int l, int r){
	return query_rec(1, 1, n, l, r);
}

signed main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		int l; cin >> l;
		arr[i] = {l,1};
	}
	build();
	while(m--){
		int op; cin >> op;
		if(op == 1){
			int p, x; cin >> p >> x;
			update(p+1, {x,1});
		}
		if(op == 2){
			int l, r; cin >> l >> r;
			array<int,2> res = query(l+1, r);
			cout << res[0] << ' ' << res[1] << '\n';
		}

		
	}
}