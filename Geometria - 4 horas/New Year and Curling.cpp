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

signed main(){
    long n;
    int r; cin >> n >> r;
    
    
    vector<int> x(n);
    vector<int> y(n);
    for(long i=0; i<n ; i++){
        cin >> x[i];
    }
    
    for(long i=0; i<n; i++) {
        int max = r;
        for(long j=0; j<i; j++){
            int dx = x[i]-x[j];
            if(!(abs(dx)>r*2)) {
                if(y[j] + sqrtl(pow(2*r,2) - pow(dx,2)) > max) {
                    max = y[j] + sqrtl(pow(2*r,2) - pow(dx,2));
                }
            }
        }
        y[i] = max;
        cout << fixed << setprecision(10) << max << ' ';
    }
    cout << '\n';
}