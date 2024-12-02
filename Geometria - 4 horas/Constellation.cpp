// https://codeforces.com/problemset/problem/618/C

#include <bits/stdc++.h>
using namespace std;
#define int double

struct point {
	int x, y;
	point(int x, int y) : x(x), y(y){}

	point operator+(const point& other) const{
		return point(x + other.x, y + other.y);
	}

	point operator-(const point& other) const{
		return point(x - other.x, y - other.y);
	}

	int operator*(const point& other) const{
		return x * other.x + y * other.y;
	}

	int operator^(const point& other) const{
		return x * other.y - other.x*y;
	}

	point operator*(const int t) const{
		return point(x*t, y*t);
	}


};

int _2area(point a, point b, point c){
	return (b - a) ^ (c - a);
}

bool left(point a, point b, point c){
	return ((b - a) ^ (c - a)) > 0;
}

bool right(point a, point b, point c){
	return ((b - a) ^ (c - a)) < 0;
}

bool is_collinear(point a, point b, point c){
	return ((b - a) ^ (c - a)) == 0;
}

signed main(){
	long n; cin >> n;
	vector<array<long,3>> p;
	for(long i=1; i<=n; i++){
		long x,y; cin >> x >> y;

		p.push_back({x,y,i});
	}

	sort(p.begin(),p.end());

	long res1 = 0, res2 = 1, res3;

	for(long i=2; i<n; i++){
		point p1(p[res1][0],p[res1][1]);
		point p2(p[res2][0],p[res2][1]);
		point p3(p[i][0],p[i][1]);

		if(!(is_collinear(p1,p2,p3))) {
			res3 = i; break;
		}
	}

	cout << p[res1][2] << ' ' << p[res2][2] << ' ' << p[res3][2] << '\n';
}