// https://codeforces.com/problemset/problem/576/A

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 86400;
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
    int n; cin >> n;
    
    if(n==1){
        cout << 0 << '\n';
    } else {
        vector<int> primes;
        crivo(n,primes);
        int t=primes.size();
        vector<int> res;
        for(int i=0; i<t; i++){
            int fat = primes[i];
            for(int j=primes[i]; j<=n; j*=fat){
                res.push_back(j);
            }
        }
        int s = res.size();
        cout << s << '\n';
        for(int i=0; i<s; i++){
            cout << res[i] << ' ';
        }
        cout << '\n';
    }
}