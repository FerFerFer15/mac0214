// https://codeforces.com/contest/908/problem/C

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

int calc(point a, point b, point c) {
    int num = abs(_2area(a,b,c));

    int den = sqrtl((c.y-a.y)*(c.y-a.y) + (c.x-a.x)*(c.x-a.x));
    
    return num/den;
}

signed main(){
    long n; cin >> n;
    vector<point> p;

    for(long i=0; i<n; i++) {
        int x, y; cin >> x >> y;
        point pn(x,y);
        p.push_back(pn);
    }

    int res = 1e9;

    for(long i=0; i<n; i++){
        if(calc(p[i],p[(i+1)%n],p[(i+2)%n])/2 < res){
            res = calc(p[i],p[(i+1)%n],p[(i+2)%n])/2;
        }
    }

    cout << fixed << setprecision(10) << res << '\n';
}