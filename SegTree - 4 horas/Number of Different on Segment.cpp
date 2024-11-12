// https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1e5+100;
const int oo = 2e9;

int n, m;
pair<int,array<bool,40>> val[4*MAX];
int arr[MAX];

const pair<int,array<bool,40>> neutral_value = {0,{false,false,false,false,false,false,false,false,
												   false,false,false,false,false,false,false,false,
												   false,false,false,false,false,false,false,false,
												   false,false,false,false,false,false,false,false,
												   false,false,false,false,false,false,false,false}};

pair<int,array<bool,40>> merge(pair<int,array<bool,40>> v1, pair<int,array<bool,40>> v2){
	pair<int,array<bool,40>> tmp;
	int newsum = v1.first;
	for(int i=0; i<40; i++){
		if(v1.second[i]){
			tmp.second[i] = true;
		} else if (v2.second[i]) {
			tmp.second[i] = true;
			newsum++;
		} else {
			tmp.second[i] = false;
		}
	}
	tmp.first = newsum;
	return tmp;
}

void build_rec(int id, int tl, int tr){
	if(tl == tr){
		pair<int,array<bool,40>> tmp;
		tmp.first = 1;
		tmp.second[arr[tl]-1] = true;
		val[id] = tmp;
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
		pair<int,array<bool,40>> tmp;
		tmp.first = 1;
		tmp.second[x-1] = true;
		val[id] = tmp;
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

pair<int,array<bool,40>> query_rec(int id, int tl, int tr, int l, int r){
	if(tr < l or r < tl) return neutral_value;
	if(l <= tl and tr <= r) return val[id];
	int mid = (tl+tr)/2;
	pair<int,array<bool,40>> q1 = query_rec(2*id, tl, mid, l, r);
	pair<int,array<bool,40>> q2 = query_rec(2*id+1, mid+1, tr, l, r);
	return merge(q1, q2);
}

int query(int l, int r){
	return query_rec(1, 1, n, l, r).first;
}

signed main(){
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
	build();
	while(m--){
		int op; cin >> op;
		if(op == 1){
			int l, r; cin >> l >> r;
            cout << query(l, r) << '\n';
		}
		if(op == 2){
			int p, x; cin >> p >> x;
			update(p, x);
		}

		
	}
}