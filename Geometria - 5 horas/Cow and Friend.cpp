// https://codeforces.com/problemset/problem/1307/B

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
	long t; cin >> t;
	
	while(t--) {
	    int n, x; cin >> n >> x;
	    
	    int max = 0;
	    
	    for(long i=0; i<n; i++){
	        int o; cin >> o;
	        
            if(o==x) max = x;
	        if(max!=x) {
	            if(o>max) max = o;
	        }
	        
	    }
	    
	    if(max>x) cout << 2 << '\n';
	    else      cout << (long) ceil(x/max) << '\n';
	}
}