// https://neps.academy/br/exercise/122

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 1e6;
const int oo = 1e9;

int h, l;
vector<vector<int>> table;
vector<vector<bool>> mark;
int res = oo;

void bfs(int srci, int srcj){
	queue<pair<int,int>> q;

	q.push({srci,srcj});
	mark[srci][srcj] = true;
	int newval = 1;

	while(not q.empty()){
		pair<int,int> cur = q.front();
		q.pop();
		int curi = cur.first; 
		int curj = cur.second; 
		
		if(curi-1>=0) {
	        if(table[curi][curj]==table[curi-1][curj] and (not mark[curi-1][curj])) {
	            q.push({curi-1,curj});
	            mark[curi-1][curj] = true;
	            newval++;
	        }
		}
		
		if(curi+1<l) {
		    if(table[curi][curj]==table[curi+1][curj] and (not mark[curi+1][curj])) {
	            q.push({curi+1,curj});
	            mark[curi+1][curj] = true;
	            newval++;
	        }
		}
		
		if(curj-1>=0) {
	        if(table[curi][curj]==table[curi][curj-1] and (not mark[curi][curj-1])) {
	            q.push({curi,curj-1});
	            mark[curi][curj-1] = true;
	            newval++;
	        }
		}
		
		if(curj+1<h) {
		    if(table[curi][curj]==table[curi][curj+1] and (not mark[curi][curj+1])) {
	            q.push({curi,curj+1});
	            mark[curi][curj+1] = true;
	            newval++;
	        }
		}
	}
	
	if(res > newval) res = newval;
}

signed main(){
	cin >> h >> l;
	
	table.resize(l);
	mark.resize(l);
	
	for(int i=0; i<l; i++){
	    table[i].resize(h);
	    mark[i].resize(h,false);
	}
	
	for(int j=0; j<h; j++){
	    for(int i=0; i<l; i++){
	        cin >> table[i][j];
	    }
	}
	
	for(int j=0; j<h; j++){
	    for(int i=0; i<l; i++){
	        if(not mark[i][j]) bfs(i, j);
	    }
	}
	
	cout << res << '\n';
}