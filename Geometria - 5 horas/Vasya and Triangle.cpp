// https://codeforces.com/problemset/problem/1030/D

#include <bits/stdc++.h>
using namespace std;
#define int long long

gcd(int a, int b) {
	if(a%b==0) return b;
	return gcd(b,a%b);
}


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
    int n, m, k; cin >> n >> m >> k;

	if((2*n*m)%k!=0) cout << "NO" << '\n';
	else {
		bool k_odd;
		if(k%2==0) {
            k_odd = false;
            k /= 2;
        }
		else       k_odd = true;
		int a = gcd(k,n);
		
		k /= a;
		int res1 = n/a, res2 = m/k;

		if(k_odd and res1<n) res1*=2;
		else if(k_odd)       res2*=2;

		cout << "YES\n" << 0 << ' ' << 0 << '\n' << res1 << ' ' << 0 << '\n' << 0 << ' ' << res2 << '\n';
	}
}