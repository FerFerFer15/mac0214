// https://codeforces.com/contest/380/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1e6+100;
const int oo = 2e9;

string s;
int n,m;
array<int,3> val[4*MAX];
char arr[MAX];

const array<int,3> neutral_value = {0,0,0};

array<int,3> merge(array<int,3> v1, array<int,3> v2){
	int tmp = min(v1[1],v2[2]);
	return {v1[0]+v2[0]+2*tmp,v1[1]+v2[1]-tmp,v1[2]+v2[2]-tmp};
}

void build_rec(int id, int tl, int tr){
	if(tl == tr){
		if(arr[tl]=='(') val[id] = {0,1,0};
		else            val[id] = {0,0,1};
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


array<int,3> query_rec(int id, int tl, int tr, int l, int r){
	if(tr < l or r < tl) return neutral_value;
	if(l <= tl and tr <= r) return val[id];
	int mid = (tl+tr)/2;
	array<int,3> q1 = query_rec(2*id, tl, mid, l, r);
	array<int,3> q2 = query_rec(2*id+1, mid+1, tr, l, r);
	if(q1[0]==0 && q1[1]==0 && q1[2]==0) return q2;
	if(q2[0]==0 && q2[1]==0 && q2[2]==0) return q1;
	return merge(q1, q2);
}

array<int,3> query(int l, int r){
	return query_rec(1, 1, n, l, r);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	n = s.length();
	for(int i=1; i<=n; i++){
	    arr[i] = s.at(i-1);
	}
	build();
	cin >> m;
	for(int i=0; i<m; i++){
	    int l,r;
	    cin >> l >> r;
	    cout << query(l,r)[0] << '\n';
	}
}