// https://codeforces.com/problemset/problem/190/B

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
	int x1, y1, r1, x2, y2, r2;

	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	
	int minr = min(r1,r2);
	int maxr = max(r1,r2);
	int dist = sqrtl(pow(x1-x2,2) + pow(y1-y2,2));
	
	int res;
	
	if(dist-minr-maxr>0) res = (dist-minr-maxr)/2;
	else if(dist+minr<=maxr) res = (maxr-dist-minr)/2;
	else res = 0;

	cout << fixed << setprecision(15) << res << '\n';
}