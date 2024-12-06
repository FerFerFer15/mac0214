// https://codeforces.com/contest/1294/problem/C

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9+7;
const int MAX = 1e7;

int fatorial[MAX];

int gcd (int a, int b) {
  if(a%b==0) return b;
  return gcd(b,a%b);
}

void pre_calc_fatorial(){
  fatorial[0] = 1;
  for(int i=1; i < MAX; i++){
    fatorial[i] = (fatorial[i-1] * i)%MOD;
  }
}

int exp(int a, int b){
	if(b == 0) return 1;
	int tmp = exp(a, b/2);
	tmp = (tmp * tmp)%MOD;
	if(b%2 == 1){
		tmp = (tmp * a)%MOD;
	}
	return tmp;
}

int modular_inverse(int a){
	return exp(a, MOD-2);
}

int comb(int n, int k){
  int numerator = fatorial[n];
  int denominator = (fatorial[k] * fatorial[n-k])%MOD;
	return (numerator * modular_inverse(denominator))%MOD;
}

int find_mindivisor(int n, int a){
	for(int d=2; d*d<=n; d++){
		if(n%d == 0 and d!=a){
			return d;
		}
	}
	return n;
}

signed main(){
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        
        int a = find_mindivisor(n,0);
        n/=a;
        int b = find_mindivisor(n,a);
        n/=b;
        
        if(n!=a and n!=b and n>1) {
            cout << "YES\n" << a << ' ' << b << ' ' << n << '\n';
        }
        else cout << "NO\n"; 
    }
}