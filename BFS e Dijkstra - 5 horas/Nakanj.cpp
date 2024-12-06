// https://www.spoj.com/problems/NAKANJ/

#include <bits/stdc++.h>
using namespace std;
#define int long long

int t;

char s, f;
int sx, sy, fx, fy;

int bfs(int cx, int cy, int dx, int dy){
	vector<vector<bool>> mark(8);
	vector<vector<int>> dist(8);

	for(int i=0; i<8; i++) {
		mark[i].resize(8,false);
		dist[i].resize(8,-1);
	}
	queue<pair<int,int>> q;

	q.push({cx,cy});
	mark[cx][cy] = true;
	dist[cx][cy] = 0;

	while(not q.empty()){
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();

		if(curx==dx and cury==dy) return dist[fx][fy];

		if(curx-2>=0){
			if(cury+1<=7) {
				if(!mark[curx-2][cury+1]) {
					q.push({curx-2,cury+1});
					mark[curx-2][cury+1] = true;
					dist[curx-2][cury+1] = 1 + dist[curx][cury];
				}
			}

			if(cury-1>=0) {
				if(!mark[curx-2][cury-1]) {
					q.push({curx-2,cury-1});
					mark[curx-2][cury-1] = true;
					dist[curx-2][cury-1] = 1 + dist[curx][cury];
				}
			}
		}

		if(curx+2<=7){
			if(cury+1<=7) {
				if(!mark[curx+2][cury+1]) {
					q.push({curx+2,cury+1});
					mark[curx+2][cury+1] = true;
					dist[curx+2][cury+1] = 1 + dist[curx][cury];
				}
			}

			if(cury-1>=0) {
				if(!mark[curx+2][cury-1]) {
					q.push({curx+2,cury-1});
					mark[curx+2][cury-1] = true;
					dist[curx+2][cury-1] = 1 + dist[curx][cury];
				}
			}
		}

		if(curx-1>=0){
			if(cury+2<=7) {
				if(!mark[curx-1][cury+2]) {
					q.push({curx-1,cury+2});
					mark[curx-1][cury+2] = true;
					dist[curx-1][cury+2] = 1 + dist[curx][cury];
				}
			}

			if(cury-2>=0) {
				if(!mark[curx-1][cury-2]) {
					q.push({curx-1,cury-2});
					mark[curx-1][cury-2] = true;
					dist[curx-1][cury-2] = 1 + dist[curx][cury];
				}
			}
		}

		if(curx+1<=7){
			if(cury+2<=7) {
				if(!mark[curx+1][cury+2]) {
					q.push({curx+1,cury+2});
					mark[curx+1][cury+2] = true;
					dist[curx+1][cury+2] = 1 + dist[curx][cury];
				}
			}

			if(cury-2>=0) {
				if(!mark[curx+1][cury-2]) {
					q.push({curx+1,cury-2});
					mark[curx+1][cury-2] = true;
					dist[curx+1][cury-2] = 1 + dist[curx][cury];
				}
			}
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;

	while(t--) {
		cin >> s >> sy >> f >> fy;

		sy--; fy--;
		switch (s) {
			case 'a':
				sx=0;
				break;
			case 'b':
				sx=1;
				break;
			case 'c':
				sx=2;
				break;
			case 'd':
				sx=3;
				break;
			case 'e':
				sx=4;
				break;
			case 'f':
				sx=5;
				break;
			case 'g':
				sx=6;
				break;
			case 'h':
				sx=7;
				break;
		}

		switch (f) {
			case 'a':
				fx=0;
				break;
			case 'b':
				fx=1;
				break;
			case 'c':
				fx=2;
				break;
			case 'd':
				fx=3;
				break;
			case 'e':
				fx=4;
				break;
			case 'f':
				fx=5;
				break;
			case 'g':
				fx=6;
				break;
			case 'h':
				fx=7;
				break;
		}

		cout << bfs(sx,sy,fx,fy) << '\n';
	}
}