// https://codeforces.com/contest/1312/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 998244353;
const int MAX = 1e7;

int fatorial[MAX];

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

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
  	pre_calc_fatorial();
	int n, m; cin >> n >> m;
	
	if(n==2) cout << 0 << '\n';
	else {
		int t1 = comb(m,n-1);
		int t2 = exp(2,n-3);

		int res = (t1 * (n-2))%MOD;
		res = (res * t2)%MOD;

		cout << res << '\n';
	}
}