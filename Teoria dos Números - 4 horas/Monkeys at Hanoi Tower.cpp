// https://judge.beecrowd.com/en/problems/view/2681

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 86400;
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

int str_mod(string s) {
    int res = 0;
    int t = s.size();
    for(int i=0; i<t; i++){
        int l = s.at(i) - '0';
        res = (res * 10 + l) % MOD;
    }
    
    return res;
}

signed main(){
    string x; cin >> x;
    int l = str_mod(x);
    int res = (exp(2,l)-1+MOD)%MOD;
    
    int h, m, s;
    
    
    h = res/3600;
    m = (res%3600)/60;
    s = res%60;
    
    if(h<10)  cout << 0 << h << ':';
    else      cout << h << ':';
    
    if(m<10)  cout << 0 << m << ':';
    else      cout << m << ':';
    
    if(s<10)  cout << 0 << s << '\n';
    else      cout << s << '\n';
    
    
}