// https://codeforces.com/problemset/problem/1081/C

#include <bits/stdc++.h>
#define int long long
using namespace std;
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
  pre_calc_fatorial();

	int n, m, k, nk, i, val; cin >> n >> m >> k;
	nk = comb(n-1,k);
	i = exp(m-1,k);
	val = (nk*i)%MOD;
	val = (val*m)%MOD;
	cout << val << endl;
}