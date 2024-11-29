// https://codeforces.com/gym/101147/problem/D

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9+7;
const int MAX = 30;

int fatorial[MAX];

void pre_calc_fatorial(){
  fatorial[0] = 1;
  for(int i=1; i < 25; i++){
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
    ifstream entrada("popcorn.in");
	int t; entrada >> t;
	while(t--) {
		int n, k; 
        entrada >> n;
        entrada >> k;
		cout << comb(n, k) << '\n';
	}
	
}