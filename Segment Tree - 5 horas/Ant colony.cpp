// https://codeforces.com/contest/474/problem/F

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1e5+100;
const int oo = 2e9;

int n,t;
int val[4*MAX];
array<int,2> valmin[4*MAX];
int arr[MAX];

const int neutral_value = 0;
const array<int,2> neutral_valuemin = {oo,0};

array<int,2> mergemin(array<int,2> v1, array<int,2> v2){
    if(v1[0]<v2[0]) return v1;
    if(v2[0]<v1[0]) return v2;
    return {v1[0],v1[1]+v2[1]};
}

void build_recmin(int id, int tl, int tr){
	if(tl == tr){
		valmin[id] = {arr[tl],1};
	}
	else{
		int mid = (tl+tr)/2;
		build_recmin(2*id, tl, mid);
		build_recmin(2*id+1, mid+1, tr);
		valmin[id] = mergemin(valmin[2*id], valmin[2*id+1]);
	}
}

void buildmin(){
	build_recmin(1, 1, n);
}


array<int,2> query_recmin(int id, int tl, int tr, int l, int r){
	if(tr < l or r < tl) return neutral_valuemin;
	if(l <= tl and tr <= r) return valmin[id];
	int mid = (tl+tr)/2;
	array<int,2> q1 = query_recmin(2*id, tl, mid, l, r);
	array<int,2> q2 = query_recmin(2*id+1, mid+1, tr, l, r);
	return mergemin(q1, q2);
}

array<int,2> querymin(int l, int r){
	return query_recmin(1, 1, n, l, r);
}

//-----------------------------------------------------------------------

int merge(int v1, int v2){
	if(v1%v2==0)
        return v2;
    else
        return merge(v2,v1%v2);
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


int query_rec(int id, int tl, int tr, int l, int r){
	if(tr < l or r < tl) return neutral_value;
	if(l <= tl and tr <= r) return val[id];
	int mid = (tl+tr)/2;
	int q1 = query_rec(2*id, tl, mid, l, r);
	int q2 = query_rec(2*id+1, mid+1, tr, l, r);
	if(q1 == neutral_value) return q2;
	if(q2 == neutral_value) return q1;
	return merge(q1, q2);
}

int query(int l, int r){
	return query_rec(1, 1, n, l, r);
}

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for(int i=1; i<=n; i++) cin >> arr[i];
	build();
	buildmin();
    cin >> t;
	for(int i=0; i<t; i++){
	    int l,r; cin >> l >> r;
	    int mdc = query(l,r);
	    array<int,2> val = querymin(l,r);
	    if(val[0]<=mdc){
	        cout << r-l+1-val[1] << '\n';
	    } else {
	        cout << r-l+1 << '\n';
	    }
	}
}