// https://codeforces.com/problemset/problem/1985/G

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

void crivo(int n, vector<int>& primes){
	vector<bool> is_composite(n+1, false);
	for(int i=2; i<=n; i++){
		if(not is_composite[i]){
			primes.push_back(i);
			for(int j=i*i; j<=n; j+=i)
				is_composite[j] = true;
		}
	}
}

signed main(){
    int t; cin >> t;
    while(t--) {
        int l, r, k; cin >> l >> r >> k;
        int base = 9/k+1;
        int res = (exp(base, r) - exp(base, l) + MOD)%MOD;
        
        cout << res << '\n';
    }
}